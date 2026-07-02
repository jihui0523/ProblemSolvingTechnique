#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
int main(void)
{
	char answer = '\0';
	int i;
	int lotto[6] = { 0 };

	srand(time(NULL));

	while (answer != 'n') {
		printf("*** 로또번호생성기***\n");

		printf("생성번호: ");
		for (i = 0; i < 6; i++)
			lotto[i] = ((rand() % 45) + 1);
		for (i = 0; i < 6; i++)
			printf("%d ", lotto[i]);

		printf("\n다시생성하겠습니까? (y/n): \n");
		scanf(" %c", &answer);
	}
}