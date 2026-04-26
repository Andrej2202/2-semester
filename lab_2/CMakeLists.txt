cmake_minimum_required(VERSION 3.16)
project(Lab2_DataStructures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
add_subdirectory(googletest)

set(CORE_DIR ${CMAKE_SOURCE_DIR}/src/core)
set(ARRAY_DIR ${CORE_DIR}/Array)
set(LIST_DIR  ${CORE_DIR}/List)
set(BIT_DIR   ${CORE_DIR}/BitSequence)

add_library(Lab2Core INTERFACE)
target_include_directories(Lab2Core INTERFACE
    ${CORE_DIR}
    ${ARRAY_DIR}
    ${LIST_DIR}
    ${BIT_DIR}
)

add_executable(Lab2Tests
    tests/Array_tests/DynamicArray_tests.cpp
    tests/Array_tests/ArraySequenceConstruct_tests.cpp
    tests/Array_tests/MutableArraySequence_tests.cpp
    tests/Array_tests/ImmutableArraySequence_tests.cpp
    tests/List_tests/LinkedList_tests.cpp
    tests/List_tests/ImmutableListSequence_tests.cpp
    tests/List_tests/MutableListSequence_tests.cpp
    tests/List_tests/ListSequenceConstructors_tests.cpp
    tests/BitSequence_tests/Bit_tests.cpp
)
target_link_libraries(Lab2Tests PRIVATE Lab2Core gtest gtest_main)

add_executable(Lab2App main.cpp)
target_link_libraries(Lab2App PRIVATE Lab2Core)

enable_testing()
add_test(NAME LabTests COMMAND Lab2Tests)