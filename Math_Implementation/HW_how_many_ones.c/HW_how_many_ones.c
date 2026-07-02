#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int checkOne(int n) {

	int i, temp, count = 0;

	while (n != 0) {

		temp = n % 10;

		if (temp != 1)
			return 0;

		count++;
		n /= 10;
	}

	return count;
}
int main(void)
{
	int a, i = 2, b, c;

	scanf("%d", &a);

	while (1) {

		c = a * i;  

		if (checkOne(c) != 0) {
			printf("%d\n", checkOne(c));
			break; 
		}

		i++;
	}
}