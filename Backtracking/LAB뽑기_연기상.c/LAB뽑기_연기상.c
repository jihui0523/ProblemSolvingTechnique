#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
void pick(char people[][20], int n, int* bucket, int bucketSize, int k) {

	int i, lastIndex, smallest, item;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("\t%s", people[bucket[i]]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k; 

	for (item = 0; item < n; item++) {

		int j, chosen = 0;

		for (j = 0; j < lastIndex; j++) {
			if (bucket[j] == item) {
				chosen = 1;
				break;
			}
		}

		if (!chosen) {
			bucket[lastIndex] = item; 
			pick(people, n, bucket, bucketSize, k - 1); 
		}
	}
}
int main(void)
{
	char people[][20] = { "공유","김수현","송중기","지성","현빈" };
	int bucket[10] = { 0 };
	int n, i;

	printf("상의 종류는? ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++) 
		printf("\t상%d", i);
	printf("\n");

	pick(people, 5, bucket, n, n);
}