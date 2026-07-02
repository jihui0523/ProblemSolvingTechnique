#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int pick(int n, int item[], int picked[], int m, int toPick)
{
	int smallest, lastIndex, i;
	int count = 0;
	int check = -1;

	if (toPick == 0) {
		//for (i = 0; i < m; i++)
			//printf("%d ", item[picked[i]]);
		//printf("\n");
		return 1;
	}

	lastIndex = m - toPick - 1;

	if (m == toPick)
		smallest = 0;
	else
		smallest = picked[lastIndex] + 1;

	for (i = smallest; i < n; i++) {
		if (item[i] == check)
			continue;

		check = item[i];
		picked[lastIndex + 1] = i;
		count += pick(n, item, picked, m, toPick - 1);
	}
	return count;
}
int main(void)
{
	int N, M, i;
	int p[100] = { 0 };
	int* bucket;
	int memo;

	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
		scanf("%d", &p[i]);

	bucket = (int*)malloc(sizeof(int) * M);

	printf("%d", pick(N, p, bucket, M, M));
}