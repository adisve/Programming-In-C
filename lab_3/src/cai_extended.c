#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_MAX    1
#define ONE         1
#define TWO         2
#define THREE       3

void practices(); void test(); void additions(); 
void subtractions(); void additions_subtractions();
int get_choice(char* arr);

int main(int argc, char *argv[])
{
    char user_name[CHAR_MAX];
    int user_choice;
    int running = 1;

    /* Not necessary to validate input */
    printf("\nEnter your name >> ");
    scanf("%[^\n]", user_name);
    printf("\nWelcome %s!\n", user_name);
    
    do
    {
        printf("You can choose:\n\t1.\tDo practices\n\t2.\tComplete a test\n\t3.\tQuit the program\n");
        printf("Enter your choice >> ");
        user_choice = get_choice();

        switch(user_choice)
        {
            case PRACTICE:
                practices();
                break;
            case TEST:
                test();
                break;
            case EXIT:
                running = 0;
                break;
        }
    } while (running);
    
    return 0;
}

void practices()
{
    char *p, user_in[CHAR_MAX];
    int user_choice;

    validate_input()
    printf("You entered: %d\n", user_choice);
    
    switch (user_choice)
    {
        case 1:
            /* Practice addition */
            break;
        case 2:
            /* Practice subtraction */
            break;
        case 3:
            /* Practice addition and subtraction */
            break;
    }
    return;
}

void test()
{
}

void additions() {}

void subtractions() {}

void additions_subtractions() {}

int get_choice(char* arr, char* stringarr) {
    user_in[CHAR_MAX];
    int user_choice;
    char *p;
    while (fgets(arr, sizeof(arr), stdin)) {
        user_choice = strtol(arr, &p, 10);
        if (p == arr || *p != '\n') {
            print("%s", stringarr);
        } else break;
    }
    return user_choice;
}