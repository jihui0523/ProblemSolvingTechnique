#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int pick(int items[], int itemsize, int* bucket, int bucketSize, int k, int money) {

	int i, lastIndex, smallest;
	int sum = 0, count = 0;

	lastIndex = bucketSize - k - 1;

	for (i = 0; i <= lastIndex; i++)
		sum += items[bucket[i]];

	if (sum > money)
		return 0;
	else if(sum == money) 
		return 1;
	
	if (k == bucketSize)
		smallest = 0;
	else
		smallest = bucket[lastIndex]; 

	for (i = smallest; i < itemsize; i++) {
		bucket[lastIndex + 1] = i;
		count += pick(items, itemsize, bucket, bucketSize, k - 1, money);
	}

	return count;
}
int main(void)
{
	int items[] = { 10, 50, 100, 500 };
	int* bucket;
	int money, n;

	scanf("%d", &money);

	n = money / 10;
	bucket = (int*)malloc(sizeof(int) * n);

	printf("%d", pick(items, 4, bucket, n, n, money));

	free(bucket);
}