//
// Created by eduarddumitrescul on 3/3/23.
//

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include "ArrayGenerator.h"

std::vector<long long>  ArrayGenerator::numberArray(const long long &length, const long long &minValue, const long long &maxValue) {
    std::vector <long long> v;
    std::random_device rd;     //Get a random seed from the OS entropy device, or whatever
    std::mt19937_64 eng(rd()); //Use the 64-bit Mersenne Twister 19937 generator
                                    //and seed it with entropy.

                                    //Define the distribution, by default it goes from 0 to MAX(unsigned long long)
                                    //or what have you.
    std::uniform_int_distribution<unsigned long long> distr;

    for(int i = 0;  i < length; i ++) {
        v.push_back(minValue + distr(eng) % (maxValue - minValue));
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
