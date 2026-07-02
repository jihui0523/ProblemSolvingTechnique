#include <stdio.h>
#include <stdlib.h>
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
	int list1[] = { 10, 20, 30, 70, 80,  // 0-4까지 정렬
					11, 33, 44, 55, 66 }; // 5-9까지 정렬
	int list2[] = { 10, 20, 30, 70, 80, // 0-4까지 정렬
					11, 33, 44, 55, 66 };  // 5-9까지 정렬

	// test #1
	printList(list1, 0, 9);
	merge(list1, 0, 4, 9);
	printList(list1, 0, 9);
	// test #2
	printList(list2, 2, 7);
	merge(list2, 2, 4, 7);
	printList(list2, 2, 7);
}