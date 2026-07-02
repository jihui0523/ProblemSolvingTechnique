#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
int random(int *bucket, int a) {

	int n,i;

	for (i = 0; i < a; i++)
		bucket[i] = rand() % 1000;

	return bucket;
}
int main(void) {

	int n,i;
	int* bucket;

	printf("Enter a number: ");
	scanf("%d", &n);

	bucket = (int*)malloc(sizeof(int) * n);

	random(bucket, n);

	for (i = 0; i < n; i++) {
		printf("%d ", bucket[i]);
	}

	free(bucket);
}