#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
void merge(int A[], int p, int q, int r)
{
	int i, j, t = 0;
	int* temp = (int*)malloc(sizeof(int) * (r - p + 1));

	i = p;
	j = q + 1;

	while (i <= q && j <= r) {
		if (A[i] <= A[j])
			temp[t++] = A[i++];
		else
			temp[t++] = A[j++];
	}

	while (i <= q)
		temp[t++] = A[i++];

	while (j <= r)
		temp[t++] = A[j++];

	for (i = 0; i < t; i++)
		A[p + i] = temp[i];

	free(temp);
}
void mergeSort(int A[], int p, int r) {
	
	if (p < r) {
		int q = (p + r) / 2;
		mergeSort(A, p, q);
		mergeSort(A, q+1, r);
		merge(A, p, q, r);
	}

}
void printList(int A[], int s, int e)
{
	int i;
	for (i = s; i <= e; i++)
		printf("%d ", A[i]);
	printf("\n");
}
int main(void)
{
	int n, i;

	srand(time(NULL));

	scanf("%d", &n);

	int* list = (int*)malloc(sizeof(int) * (n));

	for (i = 0; i < n; i++) 
		list[i]= rand() % 1000;

	printList(list, 0, n - 1);
	mergeSort(list, 0, n - 1);
	printList(list, 0, n - 1);
}