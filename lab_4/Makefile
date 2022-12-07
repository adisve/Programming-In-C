SRC=src/
BIN=bin/
OBJ=obj/
LIB=lib/

test: $(OBJ)main.o $(OBJ)aoc.o
	gcc -Wall -Werror -o $(BIN)main $(OBJ)main.o $(OBJ)aoc.o

%.o: %.c
	gcc -c -Wall -Werror -o $@ $<

clean:
	rm -f $(OBJ)*.o test

build:
	gcc -Wall -Werror -c -o $(OBJ)main.o $(SRC)main.c
	gcc -Wall -Werror -c -o $(OBJ)aoc.o $(LIB)aoc.c