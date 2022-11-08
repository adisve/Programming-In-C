#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ADDITION	1
#define SUBTRACTION	2

int getnum(char* buffer)
{
    char *p;
    fgets(buffer, sizeof(buffer), stdin);
    return strtol(buffer, &p, 10);
}

void setname(char* buffer)
{
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
}

int check_answer(char* buffer, int a, int b, int type, int *user_input)
{
	printf("\nHow much is %d %s %d? Answer >> ", a, (type == ADDITION ? "+" : "-"), b);
	*user_input = getnum(buffer);
	return !(*user_input != (type == ADDITION ? a+b : a-b));
}
