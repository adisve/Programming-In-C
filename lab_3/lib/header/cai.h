#ifndef CAI_HEADER_FILE
#define CAI_HEADER_FILE

void selectexec(struct UserResult *user_result, int program_type, char *input_buffer);
void selectprogram(struct UserResult *user_result, char *input_buffer);
void runprogram(struct UserResult *user_result, int exec_type, int program_type, char *input_buffer);

#endif