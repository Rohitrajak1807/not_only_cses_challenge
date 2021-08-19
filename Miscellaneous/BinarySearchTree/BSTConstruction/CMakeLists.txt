cmake_minimum_required(VERSION 3.21)
project(BSTConstruction)

set(CMAKE_CXX_STANDARD 17)

add_library(bst BST.h BST.cpp)

add_executable(bst-construction main.cpp)

target_link_libraries(bst-construction bst)
