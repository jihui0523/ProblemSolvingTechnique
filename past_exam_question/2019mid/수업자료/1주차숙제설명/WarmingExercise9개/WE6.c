#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
	char c;
	srand(time(NULL));
	do
	{
		while (getchar() != '\n');
		printf("*** 로또 번호 생성기 ***\n");
		printf("생성 번호: ");
		for (int i = 0; i < 6; i++)
			printf("%d ", rand() % 45 + 1);
		printf("\n다시 생성하겠습니까? (y/n): ");
		scanf("%c", &c);
	} while (c == 'y');
}