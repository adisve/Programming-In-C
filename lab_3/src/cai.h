#ifndef CAI_HEADER_FILE
#define CAI_HEADER_FILE

void choose_tests(struct UserResult *user_result, char* input_buffer);
void run_test(struct UserResult *user_result, char* input_buffer, int type);
void choose_practices(char* input_buffer, char** correct_responses, char** bad_responses);
void run_practice(char* input_buffer, int type, char** correct_responses, char** bad_responses); 

#endif