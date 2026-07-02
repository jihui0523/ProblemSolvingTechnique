#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int* items, int itemsize, int* bucket, int bucketSize, int k, int money) { 
	
    int i;
    int sum = 0;

    for (i = 0; i < k; i++)
        sum += items[bucket[i]];

    if (sum > money)
        return;

    if (sum == money) {
        for (i = 0; i < k; i++)
            printf("%d ", items[bucket[i]]);
        printf("\n");
        return;
    }

    int start;
    if (k == 0)
        start = 0;
    else
        start = bucket[k - 1]; 

    for (i = start; i < itemsize; i++) {
        bucket[k] = i;
        pick(items, itemsize, bucket, bucketSize, k + 1, money);
    }
}
int main(void)
{
	int items[] = { 1000, 5000, 10000 };
	int* bucket;
	int money, n;

	scanf("%d", &money);

	n = money / 1000;
	bucket = (int*)malloc(sizeof(int) * n);

	pick(items, 3, bucket, n, 0, money);

	free(bucket);
}