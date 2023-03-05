#include <iostream>
#include <map>
#include <fstream>
#include <ctime>
#include <chrono>
#include <algorithm>
#include "ArrayGenerator.h"
#include "ArraySorter.h"

const long long MAX_SIZE = 200000;

void testCountSort(std::vector <long long> maxAbsValue) {
    std::ofstream fout;
    fout.open("../stats/count_sort.txt");
    for(auto max: maxAbsValue) {
        for (long long size = 100; size <= MAX_SIZE; size *= 2) {
            std::vector<long long> v = ArrayGenerator::numberArray(size, -max, max);
            auto start = std::chrono::high_resolution_clock::now();
            bool ok = ArraySorter::countSort(v);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            fout << max << ' ' << (ok ? "OK" : "Failed") << ' ' << size << ' ' << duration.count() << '\n';
        }
    }
}

void testShellSort(std::vector <long long> maxAbsValue) {
    std::ofstream fout;
    fout.open("../stats/shell_sort.txt");
    for(auto max: maxAbsValue) {
        for (long long size = 100; size <= MAX_SIZE; size *= 2) {
            std::vector<long long> v = ArrayGenerator::numberArray(size, -max, max);
            auto start = std::chrono::high_resolution_clock::now();
            bool ok = ArraySorter::shellSort(v);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            fout << max << ' ' << (ok ? "OK" : "Failed") << ' ' << size << ' ' << duration.count() << '\n';
        }
    }
}

void testHeapSort(std::vector <long long> maxAbsValue) {
    std::ofstream fout;
    fout.open("../stats/heap_sort.txt");
    for(auto max: maxAbsValue) {
        for (long long size = 100; size <= MAX_SIZE; size *= 2) {
            std::vector<long long> v = ArrayGenerator::numberArray(size, -max, max);
            auto start = std::chrono::high_resolution_clock::now();
            bool ok = ArraySorter::heapSort(v);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            fout << max << ' ' << (ok ? "OK" : "Failed") << ' ' << size << ' ' << duration.count() << '\n';
        }
    }
}

void testRadixSort(std::vector <long long> maxAbsValue) {
    std::ofstream fout;
    fout.open("../stats/radix_sort.txt");
    for(auto max: maxAbsValue) {
        for (long long size = 100; size <= MAX_SIZE; size *= 2) {
            std::vector<long long> v = ArrayGenerator::numberArray(size, -max, max);
            auto start = std::chrono::high_resolution_clock::now();
            bool ok = ArraySorter::radixSort(v);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            fout << max << ' ' << (ok ? "OK" : "Failed") << ' ' << size << ' ' << duration.count() << '\n';
        }
    }
}

void testMergeSort(std::vector <long long> maxAbsValue) {
    std::ofstream fout;
    fout.open("../stats/merge_sort.txt");
    for(auto max: maxAbsValue) {
        for (long long size = 100; size <= MAX_SIZE; size *= 2) {
            std::vector<long long> v = ArrayGenerator::numberArray(size, -max, max);
            auto start = std::chrono::high_resolution_clock::now();
            bool ok = ArraySorter::mergeSort(v);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            fout << max << ' ' << (ok ? "OK" : "Failed") << ' ' << size << ' ' << duration.count() << '\n';
        }
    }
}

void testStandardSort(std::vector <long long> maxAbsValue) {
    std::ofstream fout;
    fout.open("../stats/standard_sort.txt");
    for(auto max: maxAbsValue) {
        for(long long size = 100; size <= MAX_SIZE; size *= 2) {
            std::vector <long long> v = ArrayGenerator::numberArray(size, -max, max);
            auto start = std::chrono::high_resolution_clock::now();
            std::sort(v.begin(), v.end());
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            fout << max << ' ' << "OK" << ' ' << size << ' ' << duration.count() << '\n';
        }
    }

}

void testAllIndividually() {
    std::vector <long long> maxAbsValue = {10000, static_cast<long long>(1e8), static_cast<long long>(1e12), static_cast<long long>(1e16)};

    testCountSort(maxAbsValue);
    testMergeSort(maxAbsValue);
    testShellSort(maxAbsValue);
    testHeapSort(maxAbsValue);
    testRadixSort(maxAbsValue);
    testStandardSort(maxAbsValue);

}

void testAllSortingMethods() {
    std::map <long long, std::vector<long long>> testReq;
    testReq[1e2] = {
            static_cast<long long>(1e2),
            static_cast<long long>(1e6),
            static_cast<long long>(1e10),
            static_cast<long long>(1e14),
            static_cast<long long>(5e17),
    };
    testReq[5e2] = {
            static_cast<long long>(1e2),
            static_cast<long long>(1e6),
            static_cast<long long>(1e10),
            static_cast<long long>(1e14),
            static_cast<long long>(5e17),
    };
    testReq[1e3] = {
            static_cast<long long>(1e2),
            static_cast<long long>(1e6),
            static_cast<long long>(1e10),
            static_cast<long long>(1e14),
            static_cast<long long>(5e17),
    };
    testReq[5e3] = {
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
    testReq[5e4] = {
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
//    testReq[1e8] = {
//        static_cast<long long>(1e2),
//        static_cast<long long>(1e5),
//        static_cast<long long>(1e8),
//        static_cast<long long>(1e11),
//        static_cast<long long>(1e14),
//        static_cast<long long>(5e17),
//    };

    std::ofstream fout;
    fout.open("statistics.txt");


    for(const auto& it: testReq) {
        long long size = it.first;
        for(long long maxValue: it.second) {
            std::vector <long long> v = ArrayGenerator::numberArray(size, -maxValue, maxValue);
            fout << "N=" << size << " Max Absolute Value=" << maxValue << '\n';
            std::cout << "N=" << size << " Values=(" << -maxValue << ',' << maxValue << ")" << '\n';

            std::vector <long long> temp;

            /// Count Sort
            temp = v;
            auto start = std::chrono::high_resolution_clock::now();
            bool ok = ArraySorter::countSort(temp);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            fout << "CountSort: " << (ok ? "OK" : "Failed") << ' ' << duration.count() << '\n';

            /// Radix Sort - base = 256
            temp = v;
            start = std::chrono::high_resolution_clock::now();
            ok = ArraySorter::radixSort(temp, 8);
            end = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            fout << "Radix Sort: " << (ok ? "OK" : "Failed") << ' ' << duration.count() << " (base 256)\n";

//            /// Radix Sort - base = 2^16
//            temp = v;
//            start = std::chrono::high_resolution_clock::now();
//            ok = ArraySorter::radixSort(temp, 16);
//            end = std::chrono::high_resolution_clock::now();
//            duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
//            fout << "Radix Sort: " << (ok ? "OK" : "Failed") << ' ' << duration.count() << " (base 2^16)\n";

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
}

int main() {



    testAllIndividually();

    return 0;
}
