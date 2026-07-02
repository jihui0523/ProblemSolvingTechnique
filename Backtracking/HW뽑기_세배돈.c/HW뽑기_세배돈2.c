#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int* items, int itemsize, int* bucket, int bucketSize, int k, int money) {
	
	int i, lastIndex, smallest;

	if (k == 0) {
		int sum = 0;

		for (i = 0; i < bucketSize; i++)
			sum += items[bucket[i]];
		
		if (sum == money) {
			for (i = 0; i < bucketSize; i++)
				printf("%d ", items[bucket[i]]);
			printf("\n");
		}

		return;
	}

	lastIndex = bucketSize - k - 1; 

	if (k == bucketSize)
		smallest = 1;
	else
		smallest = bucket[lastIndex]; 

	for (i = smallest; i < itemsize; i++) {
		bucket[lastIndex + 1] = i;
		pick(items, itemsize, bucket, bucketSize, k - 1, money);
	}

	return;
}
int main(void)
{
	int items[] = { 0, 1000, 5000, 10000 };
	int* bucket;
	int money, n,i;

	scanf("%d", &money);

	n = money / 1000;
	bucket = (int*)malloc(sizeof(int) * n);

	for (i = 1; i <= n; i++) {
		bucket = (int*)malloc(sizeof(int) * i);
		pick(items, 4, bucket, i, i, money);
		free(bucket);
	}
}