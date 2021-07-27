cmake_minimum_required(VERSION 3.21)
project(MinimizingCoins)

set(CMAKE_CXX_STANDARD 17)

add_executable(MinimizingCoins main.cpp)

add_executable(${PROJECT_NAME}Optimized optimized.cpp)