cmake_minimum_required(VERSION 3.16)
project(Lab3_LinearForm LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)
set(CMAKE_AUTOMOC ON) 

add_subdirectory(D:/2_semester/lab_2/googletest ${CMAKE_CURRENT_BINARY_DIR}/googletest)
#CMAKE_CURRENT_BINARY_DIR Папка сборки текущего CMakeLists.txt
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE) 
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)


set(SRC_DIR  ${CMAKE_SOURCE_DIR}/../lab_2/src)
set(CORE_DIR  ${SRC_DIR}/core)
set(UI_DIR    ${SRC_DIR}/UI)
set(SEQ_DIR   ${CORE_DIR}/Sequence)
set(ARRAY_DIR ${CORE_DIR}/Array)
set(BIT_DIR   ${CORE_DIR}/BitSequence)
set(LIST_DIR  ${CORE_DIR}/List)
set(LINEAR_DIR  ${CMAKE_SOURCE_DIR}/src/core)


add_library(core_lib INTERFACE)

target_include_directories(core_lib INTERFACE 
    ${LINEAR_DIR}
    ${CORE_DIR}
    ${SEQ_DIR}
    ${ARRAY_DIR}
    ${BIT_DIR}
    ${LIST_DIR}
)

# ---------------------------------------------------------------------------
add_executable(lab3_gui
    src/UI/main.cpp
)

# Чтобы по красоте было <>
target_include_directories(lab3_gui PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UI
    #${CMAKE_CURRENT_SOURCE_DIR}/src/core
)

#Указывает, с какими библиотеками/таргетами нужно связать lab3_gui на этапе линковки.

target_link_libraries(lab3_gui PRIVATE
    core_lib 
    #Qt6::Widgets
)






#-----------------------------------
add_executable(Lab3Tests
    tests/LinearForm_tests.cpp
)
#target_include_directories(Lab2Tests PRIVATE ${CORE_DIR} ${SEQ_DIR} ${ARRAY_DIR} ${BIT_DIR} ${LIST_DIR})
target_link_libraries(Lab3Tests PRIVATE 
    core_lib
    gtest gtest_main
)

enable_testing()
add_test(NAME LabTests COMMAND Lab3Tests)