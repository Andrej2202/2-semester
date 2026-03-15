CC = gcc
CFLAGS = -Wall -Wextra -g -std=c11 -MMD -MP
INCLUDES = -I. -Iinclude -Isrc -Itests

MAIN_TARGET = build\bin\app.exe
TEST_TARGET = build\bin\test.exe
TEST_LIB = build\libtesting.a

MAIN_OBJS = build\obj\main.o build\obj\support_funcs.o build\obj\sys_funcs.o build\obj\text_blocks.o
# без main для тестов
MAIN_LIB_OBJS = build\obj\support_funcs.o build\obj\sys_funcs.o build\obj\text_blocks.o
TEST_OBJS = build\obj\tests\test_where.o build\obj\tests\testing.o build\obj\tests\main_tests.o
TEST_LIB_OBJ = build\obj\tests\assertions.o

.PHONY: all main test clean run-tests dirs

all: main test

main: dirs $(MAIN_TARGET)

test: dirs $(TEST_LIB) $(TEST_TARGET)

run-tests: test
	$(TEST_TARGET)

$(MAIN_TARGET): $(MAIN_OBJS)
	$(CC) $(CFLAGS) $(MAIN_OBJS) -o $@

$(TEST_LIB): $(TEST_LIB_OBJ)
	ar rcs $@ $<

$(TEST_TARGET): $(TEST_OBJS) $(MAIN_LIB_OBJS) $(TEST_LIB)
	$(CC) $(CFLAGS) $(TEST_OBJS) $(MAIN_LIB_OBJS) -Lbuild -ltesting -o $@

# Компиляция основных файлов (src/*.c -> build/obj/*.o)
build\obj\%.o: src\%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Компиляция тестов (tests/*.c -> build/obj/tests/*.o)
build\obj\tests\%.o: tests\%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

dirs:
	@if not exist build\bin mkdir build\bin
	@if not exist build\obj mkdir build\obj
	@if not exist build\obj\tests mkdir build\obj\tests

clean:
	@if exist build rmdir /s /q build

-include $(MAIN_OBJS:.o=.d) $(TEST_OBJS:.o=.d) $(TEST_LIB_OBJ:.o=.d)