#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
int partition(int* A, int p, int r)
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

	if (p < r) {
		q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}
int main(void)
{
	int i, n1, n2;
	int* nums;

	srand(time(NULL));

	printf("Enter the number of numbers: ");
	scanf("%d", &n1);

	printf("몇번째로 작은 수: ");
	scanf("%d", &n2);

	nums = (int*)malloc(sizeof(int) * n1);

	for (i = 0; i < n1; i++)
		nums[i] = rand() % 1000;

	for (i = 0; i < n1; i++)
		printf("%d ", nums[i]);
	printf("\n");

	quickSort(nums, 0, n1 - 1);

	printf("%d번째 작은 수는 %d", n2, nums[n2 - 1]);

	free(nums);
}