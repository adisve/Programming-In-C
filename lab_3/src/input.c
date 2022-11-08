#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHAR_MAX    20

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

int check_answer(char* buffer, int a, int b)
{
    int user_input;
    printf("\nHow much is %d + %d? Answer >> ", a, b);
    user_input = getnum(buffer);
    if(user_input != a+b)
    {
        printf("\nNo. Please try again.\n");
        return 0;
    } 
    else
    {
        return 1;
    }
}