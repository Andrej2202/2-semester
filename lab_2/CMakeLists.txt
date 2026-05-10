cmake_minimum_required(VERSION 3.16)
project(Lab2_DataStructures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)
set(CMAKE_AUTOMOC ON) # (Meta-Object Compiler) для .cpp/.hpp (тут очев, но типо для однообразного стиля надо чет в скобки написать)
set(CMAKE_AUTOUIC ON) # Преобразует XML-файлы Qt Designer (.ui) в C++-заголовки, которые подключаются в коде.
set(CMAKE_AUTORCC ON) # Компилирует файлы ресурсов (.qrc), упаковывая изображения, иконки, шрифты и т.д. прямо в исполняемый файл.


set(BUILD_GMOCK OFF CACHE BOOL "" FORCE) # Отключает сборку библиотеки Google Mock (у меня мок тестов нет, он мне не сдался)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE) # Отключает правила установки (install()) для Google Test.
add_subdirectory(googletest)

set(CORE_DIR  ${CMAKE_SOURCE_DIR}/src/core)
set(UI_DIR    ${CMAKE_SOURCE_DIR}/src/UI)
set(SEQ_DIR   ${CORE_DIR}/Sequence)
set(ARRAY_DIR ${CORE_DIR}/Array)
set(BIT_DIR   ${CORE_DIR}/BitSequence)
set(LIST_DIR  ${CORE_DIR}/List)

add_library(core_lib STATIC #виды связыванмя
    ${ARRAY_DIR}/DynamicArray.hpp
    ${LIST_DIR}/LinkedList.hpp
    ${SEQ_DIR}/Sequence.hpp
    ${ARRAY_DIR}/ArraySequence.hpp
    ${LIST_DIR}/ListSequence.hpp
    ${ARRAY_DIR}/MutableArraySequence.hpp
    ${ARRAY_DIR}/ImmutableArraySequence.hpp
    ${LIST_DIR}/MutableListSequence.hpp
    ${LIST_DIR}/ImmutableListSequence.hpp
    ${BIT_DIR}/BitWithProxy.hpp
    ${BIT_DIR}/BitSequence.hpp
    ${CORE_DIR}/Exceptions.hpp
)

target_include_directories(core_lib PUBLIC 
    ${CORE_DIR}
    ${SEQ_DIR}
    ${ARRAY_DIR}
    ${BIT_DIR}
    ${LIST_DIR}
)
add_executable(lab2_gui
    src/UI/gui_main.cpp
    src/UI/mainwindow.cpp
    src/UI/mainscreenwidget.cpp
    src/UI/arraysequencewidget.cpp
    src/UI/listsequencewidget.cpp
)
target_include_directories(lab2_gui PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UI
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core
)
target_link_libraries(lab2_gui PRIVATE
    core_lib 
    Qt6::Widgets
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
target_include_directories(Lab2Tests PRIVATE ${CORE_DIR} ${SEQ_DIR} ${ARRAY_DIR} ${BIT_DIR} ${LIST_DIR})
target_link_libraries(Lab2Tests PRIVATE gtest gtest_main)

enable_testing()
add_test(NAME LabTests COMMAND Lab2Tests)


add_executable(TestMain test_main.cpp)
target_link_libraries(TestMain PRIVATE core_lib)

# D:\2_semester\lab_2>.\build\Lab2Tests.exe --gtest_color=yes

# cmake .. -G "MinGW Makefiles" ^
#   -DCMAKE_PREFIX_PATH="D:/Qt/6.11.0/mingw_64" ^
#   -DCMAKE_BUILD_TYPE=Debug