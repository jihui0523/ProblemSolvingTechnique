#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int pick(int* items, int itemSize, int* bucket, int bucketSize, int k, int N) {
	
	int i, lastIndex, smallest;
	int total = 0;
	int found;

	if (k == 0) {
		for (i = 1; i <= bucketSize; i++)
			total += (i * bucket[i - 1]);

		if (total == N)
			return 1;
		else
			return 0;
	}

	lastIndex = bucketSize - k - 1; 

	smallest = 0; 	

	found = 0;

	for (i = smallest; i < itemSize; i++) {
		bucket[lastIndex + 1] = items[i];
		found = found || pick(items, itemSize, bucket, bucketSize, k - 1, N);
	}
	return found;
}

int main(void)
{
	int items[] = { 1, -1 };
	int* bucket;
	int n;
	int N;

	scanf("%d %d", &n, &N);

	bucket = (int*)malloc(sizeof(int) * n);

	printf("%d\n", pick(items, 2, bucket, n, n, N));
}