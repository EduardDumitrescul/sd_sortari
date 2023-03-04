#include <iostream>
#include "ArrayGenerator.h"
#include "ArraySorter.h"

int main() {

    std::vector<long long> v = ArrayGenerator::numberArray(10000000, 0, 1000000000);
    ArraySorter::mergeSort(v);
    std::cout << ArraySorter::checkIfSorted(v) << '\n';
    ArrayGenerator::printArray(v, "output.txt");


    return 0;
}
