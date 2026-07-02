#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int four_bonacci(int n)
{
	if (n <= 4)
		return 1;
	else {
		return four_bonacci(n - 1) + four_bonacci(n - 2) + four_bonacci(n - 3) + four_bonacci(n - 4);
	}
}
int k_bonacci(int k, int n)
{
	if (n <= k)
		return 1;
	else {
		int sum = 0;

		for (int i = 1; i <= k; i++)
			sum += k_bonacci(k, n - i);

		return sum;
	}
}
int main() {
	int k, n;

	//scanf("%d", &n);
	scanf("%d %d", &k, &n);
	//printf("%d", four_bonacci(n));
	printf("%d", k_bonacci(k, n));
}