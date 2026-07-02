#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
int partition(int *A, int p, int r)
{
	int i = p, j = p;
	int temp;

	while (j != r) {
		if (A[j] < A[r]) {
			temp = A[j];
			A[j] = A[i];
			A[i] = temp;

			i++;
			j++;
		}
		else
			j++;
	}

	temp = A[r];
	A[r] = A[i];
	A[i] = temp;

	return i;
}
void printList(int* A, int s, int e)
{
	int i;

	for (i = s; i <= e; i++)
		printf("%d ", A[i]);
	printf("\n");
}
void quickSort(int* A, int p, int r) {

	int q = 0;

	if (p < r){
		q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}
int main(void)
{
	int i, n;
	int* nums;

	srand(time(NULL));

	scanf("%d", &n);

	nums = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
		nums[i] = rand() % 100;

	quickSort(nums, 0, n - 1);

	for (i = 0; i < n; i++)
		printf("%d ", nums[i]);

	free(nums);
}