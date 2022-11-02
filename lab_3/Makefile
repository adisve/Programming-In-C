SRC=src/
BIN=bin/
OBJ=obj/

test: $(OBJ)cai.o $(OBJ)input.o
	gcc -Wall -Werror -o $(BIN)cai $(OBJ)cai.o $(OBJ)input.o

%.o: %.c
	gcc -c -Wall -Werror -o $@ $<

clean:
	rm -f $(OBJ)*.o test

build:
	gcc -Wall -Werror -c -o $(OBJ)cai.o $(SRC)cai.c
	gcc -Wall -Werror -c -o $(OBJ)input.o $(SRC)input.c