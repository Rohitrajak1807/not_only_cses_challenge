cmake_minimum_required(VERSION 3.21)
project(FindClosestValue)

set(CMAKE_CXX_STANDARD 17)

add_library(Node Node.cpp)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} Node)
