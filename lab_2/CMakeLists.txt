cmake_minimum_required(VERSION 3.16)
project(Lab2_DataStructures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
set(CMAKE_AUTOMOC ON) # (Meta-Object Compiler) для .cpp/.hpp (тут очев, но типо для однообразного стиля надо чет в скобки написать)
set(CMAKE_AUTOUIC ON) # (User Interface Compiler) для .ui (XML-файлы Qt Designer)
set(CMAKE_AUTORCC ON) # (Resource Compiler) для .qrc(картинки, переводы и прочие приколямбы)

set(BUILD_GMOCK OFF CACHE BOOL "" FORCE) # Отключает сборку библиотеки Google Mock (у меня мок тестов нет, он мне не сдался)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE) # Отключает правила установки (install()) для Google Test.
add_subdirectory(googletest)

set(CORE_DIR  ${CMAKE_SOURCE_DIR}/src/core)
set(SEQ_DIR   ${CORE_DIR}/Sequence)
set(ARRAY_DIR ${CORE_DIR}/Array)
set(BIT_DIR   ${CORE_DIR}/BitSequence)
set(LIST_DIR  ${CORE_DIR}/List)

add_executable(Lab2UI src/UI/main.cpp)
target_include_directories(Lab2UI PRIVATE ${CORE_DIR} ${SEQ_DIR} ${ARRAY_DIR} ${BIT_DIR} ${LIST_DIR})
target_link_libraries(Lab2UI PRIVATE Qt6::Widgets)

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
target_include_directories(Lab2Tests PRIVATE ${CORE_DIR} ${SEQ_DIR} ${ARRAY_DIR} ${BIT_DIR} ${LIST_DIR})
target_link_libraries(Lab2Tests PRIVATE gtest gtest_main)

enable_testing()
add_test(NAME LabTests COMMAND Lab2Tests)

# D:\2_semester\lab_2>.\build\Lab2Tests.exe --gtest_color=yes