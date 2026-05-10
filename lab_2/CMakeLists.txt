cmake_minimum_required(VERSION 3.16)
project(Lab2_DataStructures LANGUAGES CXX)
# Объявляем имя проекта и явно указываем, что в нём используется только язык C++, чтобы сэкономить время конфигурации, CMake не будет искать компиляторы для C, Fortran и др.

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#Устанавливаем стандарт компиляции C++23. REQUIRED ON приказывает CMake дропнуть конфигурацию с варнингом, если компилятор не поддерживает C++23.


find_package(Qt6 COMPONENTS Widgets REQUIRED)
#Ищет установленную в системе Qt и её Widgets. REQUIRED означает, что сборка остановится, если Qt не найден или не настроенn через спец пути там как-то.
set(CMAKE_AUTOMOC ON) 
# При запуске MOC сканирует .h/.hpp файлы, находит классы с Q_OBJECT и генерирует дополнительный .cpp файл.
# В этом файле MOC реализует:
# 1 qt_static_metacall(...) - Диспетчеризация сигналов -> слотов во время выполнения
# 2 staticMetaObject - "Таблица со списком сигналов, слотов, свойств, имён методов"
# 3 Реализацию signal-методов - Сигналы в Qt – это обычные функции, которые вызывают "QMetaObject::activate"
# 4 qobject_cast поддержку - Безопасное приведение типов на основе строчных имён классов

#set(CMAKE_AUTOUIC ON) # (User Interface Compiler) преобразует XML-файлы .ui (из Qt Designer) в C++-код.
#set(CMAKE_AUTORCC ON) # (Resource Compiler) компилирует ресурсы из .qrc (изображения, строки локализации и т.д.) в бинарный формат.

set(BUILD_GMOCK OFF CACHE BOOL "" FORCE) 
# Отключает сборку библиотеки Google Mock (у меня мок тестов нет, он мне не сдался)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
# сохранение переменной в CMakeCache.txt, а не как локальной скрипта

# Отключает копирование в систему, тк При cmake --install файлы GTest (*.lib", "*.a", заголовки, ".cmake-конфиги) не будут записаны в /usr/local", "C:\Program Files и т.д.
# Изолирует зависимость, тк GTest остаётся строго внутри папки build/. Другие проекты его не увидят, например, если в уже установлен другой GTest.
# Ускоряет конфигурацию и install, тк CMake не тратит время на генерацию и выполнение правил установки. Команда cmake --install . проходит мгновенно.


add_subdirectory(googletest)
# Добавляет папку googletest как подпроект. CMake найдёт в ней свой CMakeLists.txt и соберёт целевые библиотеки gtest и gtest_main локально в папке сборки.

set(CORE_DIR  ${CMAKE_SOURCE_DIR}/src/core)
set(UI_DIR    ${CMAKE_SOURCE_DIR}/src/UI)
set(SEQ_DIR   ${CORE_DIR}/Sequence)
set(ARRAY_DIR ${CORE_DIR}/Array)
set(BIT_DIR   ${CORE_DIR}/BitSequence)
set(LIST_DIR  ${CORE_DIR}/List)


#создаем статическую библиотеку 
add_library(core_lib STATIC
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

#цель сборки
add_executable(lab2_gui
    src/UI/gui_main.cpp
    src/UI/mainwindow.cpp
    src/UI/mainscreenwidget.cpp
    src/UI/arraysequencewidget.cpp
    src/UI/listsequencewidget.cpp
)

# Чтобы по красоте было <>
target_include_directories(lab2_gui PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UI
    #${CMAKE_CURRENT_SOURCE_DIR}/src/core
)

#Указывает, с какими библиотеками/таргетами нужно связать lab2_gui на этапе линковки.
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
#target_include_directories(Lab2Tests PRIVATE ${CORE_DIR} ${SEQ_DIR} ${ARRAY_DIR} ${BIT_DIR} ${LIST_DIR})
target_link_libraries(Lab2Tests PRIVATE 
    core_lib
    gtest gtest_main
)

enable_testing()
add_test(NAME LabTests COMMAND Lab2Tests)

# D:\2_semester\lab_2>.\build\Lab2Tests.exe --gtest_color=yes

# cmake -G "MinGW Makefiles" -B build -DCMAKE_PREFIX_PATH="D:\Qt\6.11.0\mingw_64"