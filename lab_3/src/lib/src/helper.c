#include <stdio.h>
#include "../header/structlib.h"

#define MAX_TEST	15

int getoperand(int type, int round_count)
{
	return (type == 2 ? (round_count % 2 == 0) : type);
}

void display_results(struct UserResult *user_result, int round_count, int max)
{
	printf("%.2f", user_result->passed);
	printf("\n\nYOUR TEST RESULT IS %.2f (PERCENTAGE)\n", (user_result->passed/MAX_TEST)*100);
	printf("Detailed questions and answers: \n\n");
	printf("-- Question\tCorrect answer\tYour answer --\n");
	for (int i = 0; i < round_count; i++) {
		printf("\n%d. %s\t%d\t\t%d\n", i+1, user_result->questions[i], user_result->correct_responses[i], user_result->user_answers[i]);
	}
}