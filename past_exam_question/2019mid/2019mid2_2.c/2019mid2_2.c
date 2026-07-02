#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int solution(int n) {

	int i, len = 0;

	while (n != 0) {
		len++;
		n /= 10;
	}

	return len;
}
int triple(int n) {

	int numbers[100000] = { 0 };
	int i = 0, j;
	int three = 3;
	int temp;
	int len;
	int digits[10];

	while (i < n) {
		temp = three;
		len = solution(three);

		for (j = len - 1; j >= 0; j--) {
			digits[j] = temp % 10;
			temp /= 10;
		}

		for (j = 0; j < len && i < n; j++) {
			numbers[i] = digits[j];
			i++;
		}

		three += 3;
	}

	return numbers[n - 1];
}
int main(void) {
	int n;

	scanf("%d", &n);
	printf("%d",triple(n));
}