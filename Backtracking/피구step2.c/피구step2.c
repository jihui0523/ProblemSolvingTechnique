#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int min = 1000;
int pick(int n, int students[], int picked[], int m, int toPick)
{
	int smallest, lastIndex, i;
	int sumTotal = 0;
	int sumA = 0 , sumB = 0;

	for (i = 0; i < n; i++)
		sumTotal += students[i];

	if (toPick == 0) {
		for (i = 0; i < m; i++) 
			sumA += students[picked[i]];

		sumB = sumTotal - sumA;
		if (abs(sumA - sumB) < min)
			min = abs(sumA - sumB);
		
		return 0;
	}

	lastIndex = m - toPick - 1;

	if (m == toPick)
		smallest = 0;
	else
		smallest = picked[lastIndex] + 1;

	for (i = smallest; i < n; i++) {
		picked[lastIndex + 1] = i;
		pick(n, students, picked, m, toPick - 1);
	}

	return min;
}
int main(void)
{
	int N;
	int students[100] = { 0 };
	int picked[100] = { 0 };
	int i;
	int capacity;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &students[i]);

	capacity = N / 2;

	printf("%d",pick(N, students, picked, capacity, capacity));
}