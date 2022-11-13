#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../lib/header/helper.h"
#include "../lib/header/structlib.h"
#include "../lib/header/input.h"
#include "../lib/header/cai.h"

#define CHAR_MAX    	20

char input_buffer[CHAR_MAX];

int main(int argc, char *argv[])
{
	struct UserResult user_result;    	
	
	/* Generate seed for rand() function */
	srand(time(NULL));

	/* Get user name, with help of setname() function from custom header file, passing input_buffer by reference */
	printf("\nEnter your name >> ");
	setname(input_buffer);
	printf("\nWelcome %s!\n", input_buffer);

	selectprogram(&user_result, input_buffer);

    	return 0;
}