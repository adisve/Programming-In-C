#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

#define CHAR_MAX    20
#define FIRST       1
#define SECOND      2
#define THIRD       3

void practices();

int main(int argc, char *argv[])
{
    /* Allocate buffer for input */
    char buffer[CHAR_MAX];
    int running = 1;

    printf("\nEnter your name >> ");
    setname(buffer);
    printf("\nWelcome %s!\n", buffer);

    do
    {
        printf("\nYou can choose:\n\t1.Do practices\n\t2.Complete a test\n\t3.Quit the program\n");
        printf("\nEnter your choice >> ");

        switch(getnum(buffer))
        {
            case FIRST:
                practices(buffer);
                break;
            case SECOND:
                //test(buffer);
                break;
            case THIRD:
                running = 0;
                break;
            default:
                break;
        }
    } while (running);
    
    return 0;
}

void practices(char* buffer)
{
    printf("\nNow, you can choose to do practices on:\n\t1. Additions\n\t2. Subtractions\n\t3. Additions and subtractions\n");

    do 
    {
        printf("\nEnter your choice >> ");
        switch (getnum(buffer))
        {
            case 1:
                /* Execute addition practice .. */
                return;
            case 2:
                /* Execute subtraction practice .. */
                return;
            case 3:
                /* Execute addition and subtraction practice .. */
                return;
            default:
                return;
        }
    } while (1);
}
