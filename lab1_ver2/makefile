CC = gcc
CFLAGS = -Wall -Wextra -g -std=c11 -MMD -MP
INCLUDES = -I. -Iinclude -Isrc -Itests

MAIN_TARGET = build/bin/app.exe

MAIN_SRCS = $(wildcard src/*.c)
MAIN_OBJS = $(patsubst src/%.c,build/obj/%.o,$(MAIN_SRCS))

.PHONY: all main clean dirs run

all: main

main: dirs $(MAIN_TARGET)

run: $(MAIN_TARGET)
	$(MAIN_TARGET)

$(MAIN_OBJS): | dirs

$(MAIN_TARGET): $(MAIN_OBJS)
	$(CC) $(CFLAGS) $(MAIN_OBJS) -o $@


build/obj/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

dirs:
	@if not exist build\bin mkdir build\bin
	@if not exist build\obj mkdir build\obj

clean:
	@if exist build rmdir /s /q build

-include $(MAIN_OBJS:.o=.d)