#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int n, int students[], int picked[], int m, int toPick)
{
	int smallest, lastIndex, i;
	int sum = 0;

	if (toPick == 0) {
		for (i = 0; i < m; i++) {
			printf("%d ", students[picked[i]]);
			sum += students[picked[i]];
		}	
		printf(" : %d\n",sum);
		sum = 0;
		return;
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
}
int main(void)
{
	int N;
	int students[100] = { 0 };
	int picked[100] = { 0 };
	int i;
	int capacity;

	scanf("%d", &N);
	for(i=0;i<N;i++)
		scanf("%d", &students[i]);

	capacity = N / 2;

	pick(N,students, picked, capacity, capacity);
}