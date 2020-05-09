CC=g++ -std=c++17 -Wall -Wextra -Iincludes -lncurses -Ofast
SRC=$(wildcard src/*.cpp)

main: obj/run.o obj/main.o config.cpp
	$(CC) -o $@ $^

obj/%.o: src/%.cpp | obj/
	$(CC) -c -o $@ $^

all: test main

test: test/bin/quit # TODO
	for BIN in $^; do $$BIN || exit 1; done

test/bin/quit: config.cpp obj/main.o
test/bin/%: test/%.cpp | test/bin/
	$(CC) -o $@ $^

clean:
	rm -rf obj main test/bin

%/:
	mkdir -p $*

.PHONY: all test clean
.SECONDARY:
