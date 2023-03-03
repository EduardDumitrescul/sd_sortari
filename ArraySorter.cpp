//
// Created by eduarddumitrescul on 3/3/23.
//

#include "ArraySorter.h"



void ArraySorter::mergeSort(std::vector<long long int> &v) {
    ArraySorter::mergeSort(v, 0, v.size()-1);
}

void ArraySorter::radixSort(std::vector<long long int> &v) {

}

void ArraySorter::shellSort(std::vector<long long int> &v) {

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
