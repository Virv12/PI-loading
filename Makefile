CC=g++ -std=c++17 -Wall -Wextra -lncurses -Ofast

main: main.o config.cpp
	$(CC) -o $@ $^

main.o: main.cpp
	$(CC) -c -o $@ $^

clean:
	rm -rf main main.o

.PHONY: clean
