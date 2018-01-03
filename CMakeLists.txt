cmake_minimum_required(VERSION 3.6)
project(Algorithms)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")

set(SOURCE_FILES person.cpp employee.cpp modifying_sequence_operations.cpp)
add_executable(std_algorithms ${SOURCE_FILES})
