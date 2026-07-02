#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int total(int n) {

	int i, sum = 0;

	for (i = 1; i <= n; i++)
		sum += i;

	return sum;
}
int main(void)
{
	int num = 0, result;

	while (num != -1) {
		printf("Input a number(-1 for exit):");
		scanf("%d", &num);

		result = total(num);

		if(num!=-1)
			printf("1부터 %d까지의 합은 %d\n", num, result);
	}
}