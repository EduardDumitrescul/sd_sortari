//
// Created by eduarddumitrescul on 3/3/23.
//

#ifndef SD_SORTARI_ARRAYSORTER_H
#define SD_SORTARI_ARRAYSORTER_H


#include <vector>

class ArraySorter {
    static void mergeSort(std::vector <long long> &v, int left, int right);

    static void shellSort(std::vector <long long> &v, int gap);
public:

    static bool mergeSort(std::vector <long long> &v);

    static bool radixSort(std::vector <long long> &v, int logBase = 8);

    static bool shellSort(std::vector <long long> &v);

    static bool heapSort(std::vector <long long> &v);

    static bool countSort(std::vector <long long> &v);

    static bool checkIfSorted(const std::vector <long long> &v);
};


#endif //SD_SORTARI_ARRAYSORTER_H
