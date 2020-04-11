CC=g++ -std=c++17 -Wall -Wextra -Iincludes -lncurses -Ofast
SRC=$(wildcard src/*.cpp)

main: obj/main.o config.cpp
	$(CC) -o $@ $^

obj/%.o: src/%.cpp | obj/
	$(CC) -c -o $@ $^

clean:
	rm -rf obj main

%/:
	mkdir -p $*

.PHONY: clean
.SECONDARY:
