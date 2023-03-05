# Sorting Algorithms Comparison

### General
| Sorting Algorithm | Time Complexity | Space Complexity (extra) | Details |
| :-----| :-----: | :-----: | :---- | 
| Count Sort | O(n + k) | O(k) | k = absolute difference between the maximum and minimum values |
| Shell Sort | O(n * log<sub>2</sub>n) | O(1) | Using Hibbard(1963) gap sequences 2<sup>k</sup>-1 |
| Merge Sort | O(n * log<sub>2</sub>n) | O(n) ||
| Heap Sort | O(n * log<sub>2</sub>n) | O(n) ||
| Radix Sort | O(n * log<sub>b</sub>n) | O(n) | b = chose based (recommended 2<sup>8</sup> or 2<sup>16</sup> |
| C++ std::sort | O(n * log<sub>2</sub>n) | | |

All the algorithms have been implemented in C++.
The plots have been created using Python Matplotlib.

### Observations
- most effiecient for small numbers: Count Sort
  - maximum absolute value = 10<sup>4</sup> , array size = 9603984 => 203295 microseconds (13x faster than std::sort 2771677)
  - maximum absolute value = 10<sup>8</sup> , array size = 9603984 => 395496 microseconds (8x faster std::sort 3206191)
  - failing for bigger numbers due to space usage
- most effiecient for large numbers: Radix Sort (using base 256)
  - maximum absolute value = 10<sup>12</sup> , array size = 9603984 => 2905962 microseconds (vs std::sort 3217299)
  - maximum absolute value = 10<sup>16</sup> , array size = 9603984 => 3195253 microseconds (vs std::sort 3201822)
  - slight improvement over std::sort
 
### Plots
**Combined Comparison** 

![Combined Time Efficiency Graph](/stats/combined.png "Combined Plot")

**Count Sort**

![Count Sort Efficiency Graph](/stats/count_sort.png "Count Sort Efficiency Graph")

**Shell Sort**

![Shell Sort Efficiency Graph](/stats/shell_sort.png "Shell Sort Efficiency Graph")

**Merge Sort**

![Merge Sort Efficiency Graph](/stats/merge_sort.png "Merge Sort Efficiency Graph")

**Heap Sort**

![Heap Sort Efficiency Graph](/stats/heap_sort.png "Heap Sort Efficiency Graph")

**Radix Sort**

![Radix Sort Efficiency Graph](/stats/radix_sort.png "Radix Sort Efficiency Graph")

**C++ std::sort**

![C++ std::sort Efficiency Graph](/stats/standard_sort.png "C++ std::sort Efficiency Graph")


