//
// Created by eduarddumitrescul on 3/3/23.
//

#include <cmath>
#include <unordered_map>
#include "ArraySorter.h"
#include "RandomizedMinHeap.h"
#include <climits>
#include <cstring>
#include <iostream>


bool ArraySorter::mergeSort(std::vector<long long int> &v) {
    ArraySorter::mergeSort(v, 0, v.size()-1);
    return ArraySorter::checkIfSorted(v);
}

bool ArraySorter::radixSort(std::vector<long long int> &v, const int logBase) {
    long long divider = 1;
    long long base = 1LL << logBase;

    long long min = LONG_LONG_MAX;
    for(long long i: v)
        min = std::min(min, i);
    for(long long &i: v) {
        i -= min;
    }

    while(divider > 0) {
        std::vector <long long> bucket[base];
        for(long long i : v) {
            bucket[(i / divider) % base].push_back(i);
        }
        if(bucket[0].size() == v.size())
            break;
        v.clear();
        for(int i = 0; i < base; i ++) {
            for(long long value: bucket[i]) {
                v.push_back(value);
            }
        }
        divider *= base;
    }
    for(long long &i: v) {
        i += min;
    }
    return ArraySorter::checkIfSorted(v);
}

void ArraySorter::shellSort(std::vector<long long int> &v, int gap) {
    for(int i = gap; i < v.size(); i ++) {
        long long temp = v[i];
        int j;
        for(j = i; j >= gap and v[j-gap] > temp; j -= gap) {
            v[j] = v[j-gap];
        }
        v[j] = temp;
    }
}


bool ArraySorter::shellSort(std::vector<long long int> &v) {
    for(int k = log2(v.size() + 1); k >= 1; k --) {
        ArraySorter::shellSort(v, (1<<k)-1);
    }
    return ArraySorter::checkIfSorted(v);
}

void ArraySorter::mergeSort(std::vector<long long int> &v, const int left, const int right) {
    if(left >= right)
        return;
    int mid = (left + right) / 2;
    ArraySorter::mergeSort(v, left, mid);
    ArraySorter::mergeSort(v, mid+1, right);

    std::vector <long long> aux;
    int i, j;
    for(i = left, j = mid + 1; i <= mid and j <= right;) {
        if(v[i] <= v[j]) {
            aux.push_back(v[i]);
            i ++;
        }
        else {
            aux.push_back(v[j]);
            j ++;
        }
    }
    for(; i <= mid; i ++) {
        aux.push_back(v[i]);
    }
    for(; j <= right; j ++) {
        aux.push_back(v[j]);
    }

    for(i = left; i <= right; i ++) {
        v[i] = aux[i-left];
    }
}

bool ArraySorter::checkIfSorted(const std::vector<long long int> &v) {
    for(int i = 0; i < v.size() - 1; i ++) {
        if(v[i] > v[i+1])
            return false;
    }
    return true;
}

bool ArraySorter::heapSort(std::vector<long long int> &v) {
    RandomizedMinHeap heap;
    for(int i = 0; i < v.size(); i ++) {
        heap.addValue(v[i]);
    }
    v.clear();
    while(!heap.isEmpty()) {
        v.push_back(heap.removeMinValue());
    }
    return ArraySorter::checkIfSorted(v);
}

bool ArraySorter::countSort(std::vector<long long int> &v) {
    try {
        long long max = LONG_LONG_MIN, min = LONG_LONG_MAX;
        for(long long i: v) {
            max = std::max(max, i);
            min = std::min(min, i);
        }
        std::vector <int> count(max-min+1, 0);
        for(long long i: v) {
            count[i-min] ++;
        }
        int j = 0;
        for(int i = 0; i <= max - min; i ++) {
            while(count[i] --) {
                v[j++] = i;
            }
        }
        return true;
    }
    catch (...){
        return false;
    }


}
