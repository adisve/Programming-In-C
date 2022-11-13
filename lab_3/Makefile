SRC=src/
BIN=bin/
OBJ=obj/
LIB=lib/

test: $(OBJ)main.o $(OBJ)cai.o $(OBJ)input.o $(OBJ)structlib.o $(OBJ)helper.o
	gcc -Wall -Werror -o $(BIN)main $(OBJ)cai.o $(OBJ)input.o $(OBJ)structlib.o $(OBJ)helper.o $(OBJ)main.o

%.o: %.c
	gcc -c -Wall -Werror -o $@ $<

clean:
	rm -f $(OBJ)*.o test

build:
	gcc -Wall -Werror -c -o $(OBJ)main.o $(SRC)main.c
	gcc -Wall -Werror -c -o $(OBJ)cai.o $(LIB)src/cai.c 
	gcc -Wall -Werror -c -o $(OBJ)input.o $(LIB)src/input.c
	gcc -Wall -Werror -c -o $(OBJ)structlib.o $(LIB)src/structlib.c
	cc -Wall -Werror -c -o $(OBJ)helper.o $(LIB)src/helper.c