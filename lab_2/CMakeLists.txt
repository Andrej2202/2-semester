cmake_minimum_required(VERSION 3.16)
project(Lab2_DataStructures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/core)

add_executable(Lab2App main.cpp)

set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)

add_subdirectory(googletest)

add_executable(Lab2Tests tests/DynamicArray_tests.cpp)
target_link_libraries(Lab2Tests PRIVATE gtest gtest_main)

enable_testing()
add_test(NAME LabTests COMMAND Lab2Tests)