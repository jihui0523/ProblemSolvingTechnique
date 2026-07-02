#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int isPrime(int x) {

	int i;

	if (x == 1)
		return 0;

	for (i = 2; i < x; i++)
		if (x % i == 0)
			return 0;

	return 1;
}
int main(void)
{
	int i;

	for (i = 1; i <= 30; i++)
		if (isPrime(i) == 1)
			printf("%d ", i);
}