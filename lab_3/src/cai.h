#ifndef CAI_HEADER_FILE
#define CAI_HEADER_FILE

void selectexec(struct UserResult *user_result, int program_type);
void selectprogram(struct UserResult *user_result);
void runprogram(struct UserResult *user_result, int exec_type, int program_type);

#endif