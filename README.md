# Sorting Algorithms Comparison

### General
| Sorting Algorithm | Time Complexity | Space Complexity (extra) | Details |
| :-----| :-----: | :-----: | :---- | 
| Count Sort | O(n + k) | O(k) | k = absolute difference between the maximum and minimum values |
| Shell Sort | O(n * log<sub>2</sub>n) | O(1) | Using Hibbard(1963) gap sequences 2<sup>k</sup>-1 |
| Merge Sort | O(n * log<sub>2</sub>n) | O(n) ||
| Radix Sort | O(n * log<sub>b</sub>n) | O(n) | b = chose based (recommended 2<sup>8</sup> or 2<sup>16</sup> |
| C++ std::sort | O(n * log<sub>2</sub>n) | | |

All the algorithms have been implemented in C++.
The plots have been created using Python Matplotlib.

