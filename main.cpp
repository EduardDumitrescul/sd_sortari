#include <iostream>
#include "ArrayGenerator.h"
#include "ArraySorter.h"

int main() {


    std::vector<long long> v = ArrayGenerator::numberArray(1000, 0, 1000);
    ArraySorter::radixSort(v);
    ArrayGenerator::printArray(v);



    return 0;
}
