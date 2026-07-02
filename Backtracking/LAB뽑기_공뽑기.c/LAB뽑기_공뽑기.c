#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
void pick(int n, int bucket[], int bucketSize, int k) {

	int i, lastIndex, smallest;
	char item[] = { 'A','B','C','D','E','F','Z' };

	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%c ", item[bucket[i]]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1; 
	
	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;

	for (i = smallest; i < n; i++) {
		bucket[lastIndex + 1] = i;
		pick(n, bucket, bucketSize, k - 1);
	}
}
int main(void)
{
	int n = 7;
	int bucket[7];

	pick(7, bucket, 3, 3);
}