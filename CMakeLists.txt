cmake_minimum_required(VERSION 3.6)
project(Algorithms)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES_RAII not_exception_safe.cpp)
set(SOURCE_FILES_EXCEPTION exception_example.cpp)
set(SOURCE_FILES_NON_MODIFYING person.cpp all_any_none.cpp)
set(SOURCE_FILES_MODIFYING person.cpp employee.cpp modifying_sequence_operations.cpp)
set(SOURCE_FILES_SORT_PARTITION person.cpp employee.cpp sort_partition_operations.cpp)
set(SOURCE_FILES_NUMERICE numeric_operations.cpp)


add_executable(raii ${SOURCE_FILES_RAII})
add_executable(exception ${SOURCE_FILES_EXCEPTION})
add_executable(non_modifying ${SOURCE_FILES_NON_MODIFYING})
add_executable(modiying ${SOURCE_FILES_MODIFYING})
add_executable(sort_partition ${SOURCE_FILES_SORT_PARTITION})
add_executable(numeric_operations ${SOURCE_FILES_NUMERICE})
