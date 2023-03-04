#include <iostream>
#include <map>
#include <fstream>
#include <ctime>
#include <chrono>
#include <algorithm>
#include "ArrayGenerator.h"
#include "ArraySorter.h"

int main() {

    std::map <long long, std::vector<long long>> testReq;
    testReq[1e2] = {
        static_cast<long long>(1e2),
        static_cast<long long>(1e6),
        static_cast<long long>(1e10),
        static_cast<long long>(1e14),
        static_cast<long long>(5e17),
    };
    testReq[1e4] = {
        static_cast<long long>(1e2),
        static_cast<long long>(1e6),
        static_cast<long long>(1e10),
        static_cast<long long>(1e14),
        static_cast<long long>(5e17),
    };
    testReq[1e6] = {
        static_cast<long long>(1e2),
        static_cast<long long>(1e6),
        static_cast<long long>(1e10),
        static_cast<long long>(1e14),
        static_cast<long long>(5e17),
    };
    testReq[1e7] = {
        static_cast<long long>(1e2),
        static_cast<long long>(1e6),
        static_cast<long long>(1e10),
        static_cast<long long>(1e14),
        static_cast<long long>(5e17),
    };
    testReq[1e8] = {
        static_cast<long long>(1e2),
        static_cast<long long>(1e5),
        static_cast<long long>(1e8),
        static_cast<long long>(1e11),
        static_cast<long long>(1e14),
        static_cast<long long>(5e17),
    };

    std::ofstream fout;
    fout.open("statistics.txt");


    for(const auto& it: testReq) {
        long long size = it.first;
        for(long long maxValue: it.second) {
            std::vector <long long> v = ArrayGenerator::numberArray(size, -maxValue, maxValue);
            fout << "N=" << size << " Values=(" << -maxValue << ',' << maxValue << ")" << '\n';
            std::cout << "N=" << size << " Values=(" << -maxValue << ',' << maxValue << ")" << '\n';

            std::vector <long long> temp;

            /// Count Sort
            temp = v;
            auto start = std::chrono::high_resolution_clock::now();
            bool ok = ArraySorter::countSort(temp);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            fout << "Count Sort: " << (ok ? "OK" : "Failed") << ' ' << duration.count() << '\n';

            /// Radix Sort - base = 256
            temp = v;
            start = std::chrono::high_resolution_clock::now();
            ok = ArraySorter::radixSort(temp, 8);
            end = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            fout << "Radix Sort: " << (ok ? "OK" : "Failed") << ' ' << duration.count() << " (base 256)\n";

            /// Radix Sort - base = 2^16
            temp = v;
            start = std::chrono::high_resolution_clock::now();
            ok = ArraySorter::radixSort(temp, 16);
            end = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            fout << "Radix Sort: " << (ok ? "OK" : "Failed") << ' ' << duration.count() << " (base 2^16)\n";

            /// Shell Sort
            temp = v;
            start = std::chrono::high_resolution_clock::now();
            ok = ArraySorter::shellSort(temp);
            end = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            fout << "Shell Sort: " << (ok ? "OK" : "Failed") << ' ' << duration.count() <<  '\n';

            /// Heap Sort
            temp = v;
            start = std::chrono::high_resolution_clock::now();
            ok = ArraySorter::heapSort(temp);
            end = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            fout << "Heap Sort: " << (ok ? "OK" : "Failed") << ' ' << duration.count() << '\n';

            /// Merge Sort
            temp = v;
            start = std::chrono::high_resolution_clock::now();
            ok = ArraySorter::mergeSort(temp);
            end = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            fout << "Merge Sort: " << (ok ? "OK" : "Failed") << ' ' << duration.count() << '\n';

            /// Standard Sort
            temp = v;
            start = std::chrono::high_resolution_clock::now();
            std::sort(temp.begin(), temp.end());
            end = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            fout << "Standard Sort: " << (ok ? "OK" : "Failed") << ' '<<  duration.count() << '\n';

            fout << '\n';
        }
    }


    return 0;
}
