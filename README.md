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


