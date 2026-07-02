#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char* num;
	int len;

	num = (char*)malloc(sizeof(char) * 10^51); 

	scanf("%s", num);

	len = strlen(num); 

	if ((num[len - 1] - '0') % 2 == 0) 
		printf("1");
	else
		printf("0");

	free(num);
}