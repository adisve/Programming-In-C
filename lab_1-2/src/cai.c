#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int completed_questions = 0;
	int round_count = 0;
	int a;
	int b;
	int answer;

	do {
		printf("\n---- ROUND NUMBER %d ----\n", round_count+1);
		
		a = rand() % (100 + 1 - 0) + 0;
		b = rand() % (a + 1 - 0) + 0;

		// Get user answer
		do {
			printf("\nHow much is %d - %d? Answer >> ", a, b);
			scanf("%d", &answer);
		} while(answer != a-b && printf("\nNo. Please try again.\n"));
		
		// Finalize
		printf("\nVery good!\n");
		completed_questions += 1;
		round_count += 1;

	} while(completed_questions < 10);
	printf("\n---- You passed! ----\n");
	return 0;	
}