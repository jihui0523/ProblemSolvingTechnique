#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int calculateReverse(int n) {

	int i, temp, newN = 0, ten = 1, len = 0, copyN;

	copyN = n;

	while (copyN != 0) {

		copyN /= 10;
		len++;
	}

	for (i = 0; i < len-1; i++)
		ten *= 10;

	while (n != 0) {

		temp = n % 10;
		n /= 10;
		newN += temp * ten;
		ten /= 10;
	}

	return newN;
}
int main(void)
{
	int i, n, reverseN, sumN, flag = 0, count = 0;

	scanf("%d", &n);

	while (flag != 1) {

		count++;

		reverseN = calculateReverse(n);
		sumN = reverseN + n;

		if (calculateReverse(sumN) == sumN) 
			flag = 1;

		n = sumN;
	}

	if (sumN < 0)
		printf("Overflow");
	else
		printf("%d %d", count, sumN);
}