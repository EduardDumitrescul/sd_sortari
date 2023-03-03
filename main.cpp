#include <iostream>
#include "ArrayGenerator.h"
#include "ArraySorter.h"

int main() {


    std::vector<long long> v = ArrayGenerator::numberArray(1000, 0, 1000);
    ArraySorter::shellSort(v);
    std::cout << ArraySorter::checkIfSorted(v) << '\n';
    ArrayGenerator::printArray(v);



    return 0;
}
