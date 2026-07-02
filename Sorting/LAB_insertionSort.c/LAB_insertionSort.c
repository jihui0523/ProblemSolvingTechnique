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
int insertionSort(int* A, int n) {

	int i, j, key;

	for (i = 1; i < n; i++) {
		key = A[i]; 
		j = i - 1;

		while (j >= 0 && A[j] > key) {
			A[j + 1] = A[j]; 
			j--;  
		}

		A[j + 1] = key;  
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
	insertionSort(bucket, n);
	for (i = 0; i < n; i++)
		printf("%d ", bucket[i]);

	free(bucket);
}