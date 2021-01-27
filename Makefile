CC=g++
CFLAGS= -Wshadow -Wall 
.SUFFIXES = .cpp
objs:=$(wildcard *.cpp)
targets:=$(objs:.cpp= )

.PHONY:all
all: $(targets)
.cpp:
	$(CC) $(CFLAGS) -std=c++17 -o $@ $< && $@ < input.txt