#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char* num;
	int len;
	int check[4] = { 0 };
	int i, sum = 0;

	num = (char*)malloc(sizeof(char) * 10 ^ 51);

	scanf("%s", num);

	len = strlen(num);

	if ((num[len - 1] - '0') % 2 == 0)
		check[0] = 1;

	for (i = 0; i < len; i++) 
		sum += num[i];
	if (sum % 3 == 0)
		check[1] = 1;
	
	if ((num[len - 1] - '0' + 10 * num[len - 2] - '0') % 4 == 0)
		check[2] = 1;


	if ((num[len - 1] - '0') == 0 || (num[len - 1] - '0') == 5)
		check[3] = 1;

	for (i = 0; i < 4; i++)
		printf("%d", check[i]);

	free(num);
}