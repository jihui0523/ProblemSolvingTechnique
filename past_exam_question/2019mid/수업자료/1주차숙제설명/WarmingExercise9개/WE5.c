#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char strings[80], ch;
	int i, count = 0;

	printf("Enter a String:");
	scanf("%s", strings);

	while (getchar() != '\n');

	printf("Enter a character:");
	scanf("%c", &ch);

	for (i = 0; strings[i] != '\0'; i++)
		if (strings[i] == ch)
			count++;

	printf("'%c' is appered %d times", ch, count);
}