cmake_minimum_required(VERSION 3.16)
project(Lab3_LinearForm LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)
set(CMAKE_AUTOMOC ON) 

#CMAKE_CURRENT_BINARY_DIR Папка сборки текущего CMakeLists.txt
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE) 
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
add_subdirectory(googletest)

include(FetchContent)

FetchContent_Declare(
    sequence_repo
    GIT_REPOSITORY https://github.com/Andrej2202/2-semester
    GIT_TAG        main
)

FetchContent_MakeAvailable(sequence_repo)

add_subdirectory(${sequence_repo_SOURCE_DIR}/lab_2 ${CMAKE_BINARY_DIR}/lab_2)




# ---------------------------------------------------------------------------
add_executable(lab3_gui
    src/UI/main.cpp
)


target_include_directories(lab3_gui PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UI
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core
)

target_link_libraries(lab3_gui PRIVATE
    core_lib 
    lab_2
    #Qt6::Widgets
)






#-----------------------------------
add_executable(Lab3Tests
    tests/LinearForm_tests.cpp
)
#target_include_directories(Lab3Tests PRIVATE ${CORE_DIR} ${SEQ_DIR} ${ARRAY_DIR} ${BIT_DIR} ${LIST_DIR})
target_link_libraries(Lab3Tests PRIVATE 
    core_lib
    lab_2
    gtest gtest_main
)

enable_testing()
add_test(NAME LabTests COMMAND Lab3Tests)



# D:\2_semester\lab_3>.\build\Lab3Tests.exe --gtest_color=yes
# D:\2_semester\lab_3>.\build\lab3_gui.exe 
# cmake -G "MinGW Makefiles" -B build -DCMAKE_PREFIX_PATH="D:\Qt\6.11.0\mingw_64"