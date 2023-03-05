import os

import matplotlib.pyplot as plt
import numpy as np
from matplotlib.pyplot import figure


def readStats():
    perf = dict()
    for filename in os.listdir('../stats'):
        if filename[-4:] == ".txt":
            with open("../stats/" + filename) as file:
                perf[filename] = dict()
                for line in file:
                    temp = line.split()
                    max = int(temp[0])
                    status = temp[1]
                    size = int(temp[2])
                    time = int(temp[3])

                    if status != "OK":
                        continue
                    if max not in perf[filename]:
                        perf[filename][max] = []

                    perf[filename][max].append(tuple([size, time]))

    return perf


def plotSeparately(perf):
    for sort_method, stats_dict in perf.items():
        plt.xscale('log')
        plt.yscale('linear')
        for max, stats in stats_dict.items():
            x = [v[0] for v in stats if v[0] > 1e5]
            y = [v[1] for v in stats if v[0] > 1e5]
            plt.plot(np.array(x), np.array(y), label="maxVal=" + str(max))

        plt.ylabel("microseconds")
        plt.xlabel("array size")
        plt.title(sort_method[0:-4])
        plt.legend()
        plt.savefig("../stats/" + sort_method[0:-4] + ".png")
        plt.close()


def plotCombined(perf):
    fig, axs = plt.subplots(1, 4, figsize=(20, 6))
    axs[0].set_title("Max Abs Value = 10^4")
    axs[1].set_title("Max Abs Value = 10^8")
    axs[2].set_title("Max Abs Value = 10^12")
    axs[3].set_title("Max Abs Value = 10^16")

    for j in axs:
        j.set_xscale('log')
        j.set_yscale('linear')

    for sort_method, stats_dict in perf.items():

        for max, stats in stats_dict.items():
            x = [v[0] for v in stats if v[0] > 1e5]
            y = [v[1] for v in stats if v[0] > 1e5]
            if max == 10000:
                axs[0].plot(np.array(x), np.array(y), label=sort_method[0:-4])
            elif max == 1e8:
                axs[1].plot(np.array(x), np.array(y), label=sort_method[0:-4])
            elif max == 1e12:
                axs[2].plot(np.array(x), np.array(y), label=sort_method[0:-4])
            elif max == 1e16:
                axs[3].plot(np.array(x), np.array(y), label=sort_method[0:-4])

    for j in axs:
        j.legend()
        j.set_ylabel("microseconds")
        j.set_xlabel("array size")
        j.sharey(axs[0])

    fig.tight_layout()
    plt.savefig("../stats/combined.png")
    plt.close()


performance = readStats()
plotSeparately(performance)
plotCombined(performance)

print(performance.items())

