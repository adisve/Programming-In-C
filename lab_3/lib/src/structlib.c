#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../header/helper.h"
#include "../header/structlib.h"

#define ADDITION        1
#define SUBTRACTION     2
#define MIXED           3

struct UserResult user_result;

void setstruct(struct UserResult *user_result, int round_count, int first, int second, int passed, int user_input, int type)
{
	asprintf(&user_result->questions[round_count], "%d %s %d", first, ((type == MIXED ? (round_count % 2 == 0) : type) == ADDITION ? "+" : "-"), second);
	user_result->correct_responses[round_count] = (getoperand(type, round_count) == ADDITION ? first + second : first - second);
	user_result->user_answers[round_count] = user_input;
	if(passed) user_result->passed += 1;
}