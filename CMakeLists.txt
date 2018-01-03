cmake_minimum_required(VERSION 3.6)
project(Algorithms)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")

set(SOURCE_FILES_NON_MODIFYING person.cpp all_any_none.cpp)
set(SOURCE_FILES_MODIFYING person.cpp employee.cpp modifying_sequence_operations.cpp)
set(SOURCE_FILES_SORT_PARTITION person.cpp employee.cpp sort_partition_operations.cpp)

add_executable(non_modifying ${SOURCE_FILES_NON_MODIFYING})
add_executable(modiying ${SOURCE_FILES_MODIFYING})
add_executable(sort_partition ${SOURCE_FILES_SORT_PARTITION})
