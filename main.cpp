#include <iostream>
#include "ArrayGenerator.h"

int main() {


    std::vector<long long> v = ArrayGenerator::numberArray(1000, 0, 1000);
    ArrayGenerator::printArray(v);


    return 0;
}
