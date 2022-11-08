#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "input.h"

#define CHAR_MAX    20
#define ADDITION    1
#define SUBTRACTION 2

void choose_practices(char* buffer);
void run_practice(char* buffer, int type);

int main(int argc, char *argv[])
{
    /* Allocate *buffer for input */
    char buffer[CHAR_MAX];
    int running = 1;

    printf("\nEnter your name >> ");
    setname(buffer);
    printf("\nWelcome %s!\n", buffer);

    do
    {
        printf("\nYou can choose:\n\t1. Do practices\n\t2. Complete a test\n\t3. Quit the program\n");
        printf("\nEnter your choice >> ");

        switch(getnum(buffer))
        {
            case 1:
                choose_practices(buffer);
                break;
            case 2:
                //test(*buffer);
                break;
            case 3:
                running = 0;
                break;
            default:
                break;
        }
    } while (running);
    
    return 0;
}

void choose_practices(char* buffer)
{
    printf("\nNow, you can choose to do practices on:\n\t1. Additions\n\t2. Subtractions\n\t3. Additions and subtractions\n");

    do 
    {
        printf("\nEnter your choice >> ");
        switch (getnum(buffer))
        {
            case 1:
                run_practice(buffer, ADDITION);
                return;
            case 2:
                run_practice(buffer, SUBTRACTION);
                return;
            case 3:
                /* Execute addition and subtraction practice .. */
                return;
            default:
                return;
        }
    } while (1);
}

void run_practice(char* buffer, int type) 
{
    int a = 0, b = 0, passed = 0, round_count = 0, failed_questions = 0, completed_questions = 0;
    printf("Now, you will be given 10 questions to solve: \n");

    do
    {
        passed = 0;
        a = rand() % (100 + 1 - 0) + 0;
        b = rand() % (a + 1 - 0) + 0;
		switch (type)
        {
            case ADDITION:
                do {
                    passed = check_answer(buffer, a, b);
                    if(!passed) failed_questions++;
                } while(!passed);
                break;
            case SUBTRACTION:
                do
                {
                    passed = check_answer(buffer, a, b);
                    if(!passed) failed_questions++;
                } while(!passed);
                break;
        }
		printf("\nVery good!\n");
        printf("---------------------------------\n");
		completed_questions++;
		round_count++;
    } while (completed_questions < 10);
}
