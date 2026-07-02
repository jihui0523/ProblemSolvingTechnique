#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int pick1(int n, int* bucket, int bucketSize, int k)
{
	int smallest, lastIndex, i;
	int cnt = 0;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++) {
			printf("%d", bucket[i]);
		}
		cnt++;
		printf("\n");
		return 1;
	}

	lastIndex = bucketSize - k - 1;

	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;

	for (i = smallest; i < n; i++) {
		bucket[lastIndex + 1] = i;
		cnt += pick1(n, bucket, bucketSize, k - 1);
	}

	return cnt;
}
int main(void)
{
	int * picked;
	int m, n;

	scanf("%d", &n);
	scanf("%d", &m);

	picked = (int*)malloc(sizeof(int) * m);
	printf("%d\n", pick1(n, picked, m, m));
}