//
// Created by eduarddumitrescul on 3/3/23.
//

#ifndef SD_SORTARI_ARRAYGENERATOR_H
#define SD_SORTARI_ARRAYGENERATOR_H


#include <vector>
#include <string>

class ArrayGenerator {
public:
    static std::vector<long long> numberArray(const long long &length, const long long &minValue = -1000000000000000000, const long long &maxValue = 1000000000000000000);

    static void printArray(const std::vector <long long> &v, const std::string& filename = "");
};


#endif //SD_SORTARI_ARRAYGENERATOR_H
