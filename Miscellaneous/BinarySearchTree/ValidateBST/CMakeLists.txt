cmake_minimum_required(VERSION 3.21)
project(ValidateBST)

set(CMAKE_CXX_STANDARD 17)

add_executable(ValidateBST main.cpp)
target_include_directories(ValidateBST PRIVATE ../BSTConstruction)