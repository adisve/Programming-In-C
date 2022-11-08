#ifndef HELPER_HEADER_FILE
#define HELPER_HEADER_FILE
#include "structlib.h"

int getoperand(int type, int round_count);
void display_results(struct UserResult *user_result, int round_count);
int getrandom(int max);

#endif