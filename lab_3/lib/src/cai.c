#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../header/helper.h"
#include "../header/structlib.h"
#include "../header/input.h"
#include "../header/cai.h"

#define MAX_INT		100
#define MAX_TEST	15.0f
#define MAX_PRACTICE	10
#define PRACTICE	1
#define TEST		2
#define EXIT		3
#define BAD_RESP	4
#define CORRECT_RESP	6

/* Instantiate arrays of responses */
char *correct_responses[CORRECT_RESP] = {
	"Very good!", "Excellent!", "Nice work!", 
	"Well done!", "Great!", "Keep up the good work!"
};
char *bad_responses[BAD_RESP] = {
	"No, please try again", "Wrong. Try once again.", 
	"Don't give up!", "No. Keep trying"
};

void selectprogram(struct UserResult *user_result, char *input_buffer)
{
	int running = 1;
    	do
    	{
        	printf("\nYou can choose:\n\t1. Do practices\n\t2. Complete a test\n\t3. Quit the program\n");
        	printf("\nEnter your choice >> ");

        	switch(getnum(input_buffer))
        	{
            		case PRACTICE:
                		selectexec(user_result, PRACTICE, input_buffer);
                		break;
            		case TEST:
                		selectexec(user_result, TEST, input_buffer);
                		break;
            		case EXIT:
                		running = 0;
               			break;
            		default:
                		break;
        	}
    	} while (running);
}

void selectexec(struct UserResult *user_result, int program_type, char *input_buffer)
{
	printf("\nNow, you can choose to do %s on:\n\t1. Additions\n\t2. Subtractions\n\t3. Additions and subtractions\n",
		program_type == PRACTICE ? "practices" : "tests");

	printf("\nEnter your choice >> ");
	int exec_type = getnum(input_buffer);
	
	while(exec_type > 3 || exec_type < 0) getnum(input_buffer);

	runprogram(user_result, exec_type, program_type, input_buffer);
}

void runprogram(struct UserResult *user_result, int exec_type, int program_type, char *input_buffer)
{
	const int LIMIT = program_type == PRACTICE ? MAX_PRACTICE : MAX_TEST;
	int first = 0, second = 0, operand_count = 0, passed = 0, round_count = 0;
	int correct_index;
	int bad_index;
	printf("\nNow, you will be given %d questions to solve: \n", LIMIT);

	/* Value of this variable is changed in check_answer() */
	int user_input;

	/* Reset user result struct values */
	user_result->passed = 0;

	do
	{
		passed = 0;
		first = getrandom(MAX_INT);
		second = getrandom(first);
		correct_index = getrandom((CORRECT_RESP - 1));
		printf("\nQuestion %d:\n", round_count+1);
		
		switch (program_type)
		{
			/* If PRACTICE, only let user continue if they enter correct answers */
			case PRACTICE:
				do
				{
					bad_index = getrandom(BAD_RESP-1);
					passed = check_answer(input_buffer, first, second, getoperand(exec_type, round_count), &user_input);

					if(!passed) printf("\n%s\n", bad_responses[bad_index]);
					
					/* Alternate between subtraction and addition if necessary */
					else if(exec_type == 3) operand_count++;
				} while (!passed);
				break;
			case TEST:
				passed = check_answer(input_buffer, first, second, getoperand(exec_type, round_count), &user_input);
		}
		
		if(program_type == PRACTICE) printf("\n%s", correct_responses[correct_index]);

		printf("\n---------------------------------\n");
		setstruct(user_result, round_count, first, second, passed, user_input, exec_type);
		round_count++;
	} while (round_count < LIMIT);

	if(program_type == TEST) display_results(user_result, round_count);
}