//
// Created by eduarddumitrescul on 3/3/23.
//

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include "ArrayGenerator.h"

std::vector<long long>  ArrayGenerator::numberArray(const int &length, const long long &minValue, const long long &maxValue) {
    std::vector <long long> v;
    srand(time(nullptr));

    for(int i = 0;  i < length; i ++) {
        v.push_back(minValue + rand() % (maxValue - minValue));
    }
    return v;
}

void ArrayGenerator::printArray(const std::vector<long long int> &v, const std::string& filename) {

    if(!filename.empty()) {
        std::ofstream fout;
        fout.open(filename);
        for(long long i : v) {
            fout << i << ' ';
        }
        fout << '\n';
    }
    else {
        for(long long i : v) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }

}
