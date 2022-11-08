#ifndef STRUCT_LIB_HEADER
#define STRUCT_LIB_HEADER

struct UserResult {
	float passed;
	char *questions[15];
	int user_answers[15];
	int correct_responses[15];
};

void setstruct(struct UserResult *user_result, int round_count, int first, int second, int passed, int user_input, int type);

#endif