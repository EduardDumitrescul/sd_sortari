cmake_minimum_required(VERSION 3.24)
project(sd_sortari)

set(CMAKE_CXX_STANDARD 17)

add_executable(sd_sortari main.cpp ArrayGenerator.cpp ArrayGenerator.h ArraySorter.cpp ArraySorter.h RandomizedMinHeap.cpp RandomizedMinHeap.h)
