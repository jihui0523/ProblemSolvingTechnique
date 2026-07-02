#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char arr[100];
	char key = "\0";
	int count = 0, i;

	printf("Enter a String: ");
	scanf("%s", arr);

	getchar();

	printf("Enter a character: ");
	scanf("%c", &key);

	for (i = 0; arr[i] != '\0'; i++) 
		if (arr[i] == key)
			count++;
	
	printf("'%c' is appeared %d times", key, count);
}