cmake_minimum_required(VERSION 3.20)
project(TwoKnights)

set(CMAKE_CXX_STANDARD 17)

add_executable(BruteForce bruteforce.cpp)

add_executable(Optimized optimized.cpp)