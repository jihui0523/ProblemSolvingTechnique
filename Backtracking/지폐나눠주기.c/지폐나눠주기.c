#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
int pick(int itemSize, int* bucket, int bucketSize, int k) {
    int i, lastIndex, smallest, idx;
    int cnt = 0;

    if (k == 0) {
        int money[10] = { 0 };  

        for (idx = 0; idx < bucketSize; idx++) 
            money[bucket[idx]]++;

        for (idx = 0; idx < itemSize; idx++) 
            printf("person %d: %d ", idx + 1, money[idx] * 10000);
        printf("\n");

        return 1; 
    }

    lastIndex = bucketSize - k - 1;

    if (bucketSize == k)
        smallest = 0;
    else
        smallest = bucket[lastIndex];

    for (i = smallest; i < itemSize; i++) {
        bucket[lastIndex + 1] = i;
        cnt += pick(itemSize, bucket, bucketSize, k - 1);
    }

    return cnt;
}

int main(void)
{
    int a, b;

    scanf("%d", &a); 
    scanf("%d", &b); 

    int* bucket = (int*)malloc(sizeof(int) * a);
    int result = pick(b, bucket, a, a); 

    printf("%d\n", result); 

    free(bucket);
    return 0;
}