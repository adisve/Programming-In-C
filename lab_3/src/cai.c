#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lib/header/helper.h"
#include "lib/header/structlib.h"
#include "lib/header/input.h"
#include "cai.h"

#define CHAR_MAX    	20
#define CORRECT_RESP	6
#define BAD_RESP	4
#define MAX_TEST	15.0f
#define MAX_PRACTICE	10


int main(int argc, char *argv[])
{
	int running = 1;
	struct UserResult user_result;
	/* Instantiate arrays of responses */
	char *correct_responses[CORRECT_RESP] = {
		"Very good!", "Excellent!", "Nice work!", 
		"Well done!", "Great!", "Keep up the good work!"
	};
	char *bad_responses[BAD_RESP] = {
		"No, please try again", "Wrong. Try once again.", 
		"Don't give up!", "No. Keep trying"
	};
	

	/* Allocate input_buffer for input */
    	char input_buffer[CHAR_MAX];
	
	/* Generate seed for rand() function */
	srand(time(NULL));

	/* Get user name, with help of setname() function from custom header file, passing input_buffer by reference */
	printf("\nEnter your name >> ");
	setname(input_buffer);
	printf("\nWelcome %s!\n", input_buffer);

    	do
    	{
        	printf("\nYou can choose:\n\t1. Do practices\n\t2. Complete a test\n\t3. Quit the program\n");
        	printf("\nEnter your choice >> ");

        	switch(getnum(input_buffer))
        	{
            		case 1:
                		choose_practices(input_buffer, correct_responses, bad_responses);
                		break;
            		case 2:
                		choose_tests(&user_result, input_buffer);
                		break;
            		case 3:
                		running = 0;
               			break;
            		default:
                		break;
        	}
    	} while (running);
    	return 0;
}

void choose_practices(char* input_buffer, char** correct_responses, char** bad_responses)
{
    	printf("\nNow, you can choose to do practices on:\n\t1. Additions\n\t2. Subtractions\n\t3. Additions and subtractions\n");

    	do 
    	{
        	printf("\nEnter your choice >> ");
        	switch (getnum(input_buffer))
        	{
            		case 1:
                		run_practice(input_buffer, 0, correct_responses, bad_responses);
               			return;
            		case 2:
                		run_practice(input_buffer, 1, correct_responses, bad_responses);
               			return;
            		case 3:
                		run_practice(input_buffer, 2, correct_responses, bad_responses);
                		return;
            		default:
                		return;
        	}
    	} while (1);
}

void choose_tests(struct UserResult *user_result, char* input_buffer)
{
	printf("\nNow, you can choose to do tests on:\n\t1. Additions\n\t2. Subtractions\n\t3. Additions and subtractions\n");

	do
	{
		printf("\nEnter your choice >> ");
		switch(getnum(input_buffer))
		{
			case 1:
				run_test(user_result, input_buffer, 0);
				return;
			case 2:
				run_test(user_result, input_buffer, 1);
				return;
			case 3:
				run_test(user_result, input_buffer, 2);
				return;
			default:
				return;
		}
	} while (1);
}

void run_practice(char* input_buffer, int type, char** correct_responses, char** bad_responses)
{
    	int first = 0, second = 0, c = 0, passed = 0, round_count = 0, completed_questions = 0;
    	int correct_resp;
	int bad_resp;
	int user_input;
	printf("Now, you will be given 10 questions to solve: \n");

    	do
    	{
        	passed = 0;
        	first = rand() % (100 + 1 - 0) + 0;
        	second = rand() % (first + 1 - 0) + 0;
		correct_resp = rand() % ((CORRECT_RESP-1) + 1 - 0) + 0;
		
		printf("\nQuestion %d:\n", round_count+1);
		do
		{
			bad_resp = rand() % (BAD_RESP + 1 - 0) + 0;
			passed = check_answer(input_buffer, first, second, getoperand(type, round_count), &user_input);

			/* Alternate between subtraction and addition if necessary */
			if(!passed) printf("\n%s\n", bad_responses[bad_resp]); 
			else if(type == 2 && passed) c++;
		} while (!passed);

		printf("\n\n%s\n", correct_responses[correct_resp]);
        	printf("---------------------------------\n");
		completed_questions++;
		round_count++;
    	} while (completed_questions < MAX_PRACTICE);
}

void run_test(struct UserResult *user_result, char* input_buffer, int type)
{
	int first = 0, second = 0, passed = 0, round_count = 0;
	printf("\nNow, you will be given 15 questions to solve: \n");

	/* Value of this variable is changed in check_answer() */
	int user_input;

	/* Reset user result struct values */
	user_result->passed = 0;
	do
	{
		passed = 0;
		first = rand() % (100 + 1) + 0;
		second = rand() % (first + 1) + 0;
		printf("\nQuestion %d:\n", round_count+1);

		passed = check_answer(input_buffer, first, second, getoperand(type, round_count), &user_input);
		
		printf("---------------------------------\n");
		setstruct(user_result, round_count, first, second, passed, user_input, type);
		round_count++;
	} while (round_count < MAX_TEST);

	display_results(user_result, round_count);
}