#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(char* items, int itemSize, int* bucket, int bucketSize, int k) {

	int i;

	if (k == 0) {
		int sum = 0;

		for (i = 0; i < bucketSize; i++) {
			if (items[bucket[i]] == '+')
				sum += (i + 1);
			else
				sum -= (i + 1);
		}

		for (i = 0; i < bucketSize; i++) 
			printf("%c%d", items[bucket[i]], i + 1);
		printf(" = %d\n", sum);

		return;
	}

	for (i = 0; i < itemSize; i++) {
		bucket[bucketSize - k] = i; 
		pick(items, itemSize, bucket, bucketSize, k - 1); 
	}

	return;
}
int main(void)
{
	char items[] = { '+','-' };
	int* bucket;
	int n;

	scanf("%d", &n);

	bucket = (int*)malloc(sizeof(int) * n);

	pick(items, 2, bucket, n, n);

	free(bucket);
}