#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int maxArithmetic(int n, int numA[], int numB[]) {

	int i, j;
	int sum = 0;
	int min1 = 10000, min2 = 10000, max1 = 0, max2 = 0;

	for (i = 0; i < n; i++) 
		if (numA[i] > max1)
			max1 = numA[i];

	for (i = 0; i < n; i++)
		if (numA[i] > max2 &&numA[i]!=max1)
			max2 = numA[i];

	for (i = 0; i < n; i++)
		if (numB[i] < min1)
			min1 = numB[i];

	for (i = 0; i < n; i++)
		if (numB[i] < min2&&numB[i]!=min1)
			min2 = numB[i];

	for (i = 0; i < n; i++)
		sum += numB[i];

	sum = sum - min1 - min2 + max1 + max2;

	return sum;
}
int main(void) {

	int i;
	int N, K;
	int A[10000] = { 0 }, B[10000] = { 0 };

	scanf("%d", &N);

	scanf("%d", &K);

	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);

	for (i = 0; i < N; i++)
		scanf("%d", &B[i]);

	printf("%d", maxArithmetic(N, A, B));
}