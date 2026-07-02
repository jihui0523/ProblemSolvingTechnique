#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
int random(int* bucket, int a) {

	int n, i;

	for (i = 0; i < a; i++)
		bucket[i] = rand() % 1000;

	return bucket;
}
int selectionSort(int* A, int n) {

	int i,j, max, max_idx, temp;

	for (i = 0; i <n-1; i++) {
		max_idx = 0;
		max = A[0];

		for (j = 1; j < n-i ; j++){
			if (max < A[j]) {
				max = A[j];
				max_idx = j;
			}
		}

		temp = A[max_idx];
		A[max_idx] = A[n - 1 - i];
		A[n - 1 - i] = temp;
	}

	return A;
}
int main(void) {

	int n, i;
	int* bucket;

	printf("Enter a number: ");
	scanf("%d", &n);

	bucket = (int*)malloc(sizeof(int) * n);

	random(bucket, n);

	for (i = 0; i < n; i++) 
		printf("%d ", bucket[i]);
	printf("\n");

	printf("정렬된 후:\n");
	selectionSort(bucket, n);
	for (i = 0; i < n; i++)
		printf("%d ", bucket[i]);

	free(bucket);
}