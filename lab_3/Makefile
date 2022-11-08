SRC=src/
BIN=bin/
OBJ=obj/
LIB=lib/

test: $(OBJ)cai.o $(OBJ)input.o $(OBJ)structlib.o $(OBJ)helper.o
	gcc -Wall -Werror -o $(BIN)cai $(OBJ)cai.o $(OBJ)input.o $(OBJ)structlib.o $(OBJ)helper.o

%.o: %.c
	gcc -c -Wall -Werror -o $@ $<

clean:
	rm -f $(OBJ)*.o test

build:
	gcc -Wall -Werror -c -o $(OBJ)cai.o $(SRC)cai.c
	gcc -Wall -Werror -c -o $(OBJ)input.o $(LIB)src/input.c
	gcc -Wall -Werror -c -o $(OBJ)structlib.o $(LIB)src/structlib.c
	cc -Wall -Werror -c -o $(OBJ)helper.o $(LIB)src/helper.c