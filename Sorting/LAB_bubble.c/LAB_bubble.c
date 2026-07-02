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
int bubbleSort(int* A, int n) {

	int i,j,temp;

	for (i = 0; i < n -1; i++) {
		for (j = 0; j < n -i -1; j++) {
			if (A[j] > A[j + 1]) {
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
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
	bubbleSort(bucket, n);
	for (i = 0; i < n; i++)
		printf("%d ", bucket[i]);

	free(bucket);
}