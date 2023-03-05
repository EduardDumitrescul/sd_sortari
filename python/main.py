import matplotlib.pyplot as plt
import numpy as np
from matplotlib.pyplot import figure

def getPerfDict():
    performance = dict()

    with open("../cmake-build-debug/statistics.txt") as file:
        lines = file.readlines()
        i = 0
        while i < len(lines):
            req = lines[i].split()
            if req == "":
                break
            size = int(req[0].split('=')[1])
            maxValue = int(req[3].split('=')[1])

            for j in range(6):
                i += 1
                test = lines[i]
                sortMethod = test.split()[0] + " " + test.split()[1]
                status = test.split()[2]
                time = int(test.split()[3])

                print(sortMethod, status, time)

                if sortMethod not in performance.keys():
                    performance[sortMethod] = []

                performance[sortMethod].append(tuple([size, maxValue, time]))

            i += 2

    return performance


def plotSeparately(perf):
    temp = dict()
    for key in perf.keys():
        temp[key] = dict()

    for key, value in perf.items():
        for value2 in value:
            temp[key][value2[1]] = []

    for key, value in perf.items():
        for value2 in value:
            temp[key][value2[1]].append(tuple([value2[0], value2[2]]))

    i = 0

    for key, d in temp.items():
        plt.xscale('log')
        plt.yscale('linear')
        print(key, d)
        j = 0
        for key2, value in d.items():
            x = [v[0] for v in value]
            y = [v[1] for v in value]
            plt.plot(np.array(x), np.array(y))
            j += 1

        plt.savefig(key + ".png")
        plt.close()
        i += 1



performance = getPerfDict()
plotSeparately(performance)
