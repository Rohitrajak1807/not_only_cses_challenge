cmake_minimum_required(VERSION 3.21)
project(CoinCombinations2)

set(CMAKE_CXX_STANDARD 17)

add_executable(CoinCombinations2 main.cpp)
add_executable(${PROJECT_NAME}Optimized optimized.cpp)