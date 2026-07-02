#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int H(int n, int* M)
{
	int sum = 0;

	if (n == 0 || n == 1)
		return 1;
	else {
		if (M[n] != 0)
			return M[n];

		for (int i = 0; i < n; i++) {
			sum += H(i, M) * H(n - 1 - i, M);
		}
	}
	M[n] = sum;

	return sum;
}
int main(void)
{
	int n, i;
	int* M;

	printf("0보다 큰 정수:");
	scanf("%d", &n);

	M = (int*)malloc(sizeof(int) * (n+1));
	for (i = 0; i <= n; i++)
		M[i] = 0;

	printf("결과는 %d\n", H(n, M));
}