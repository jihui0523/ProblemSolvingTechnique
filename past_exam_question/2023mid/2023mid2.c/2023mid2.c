#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int isSequence(int a[], int size) {
	
	int diff = a[1] - a[0];

	for (int i = 2; i < size; i++)
		if (a[i] - a[i - 1] != diff)
			return 0;
	return 1;
}
void print(int arr[], int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
int pick(int B[], int Nb, int picked[], int m, int toPick, int A[], int Na) {
	
	int smallest, lastIndex, i, result, cnt = 0;

	if (toPick == 0) {
		int* C = (int*)malloc(sizeof(int) * Nb);
		int i;

		for (i = 0; i < Nb; i++)
			C[i] = B[i];
		
		for (i = 0; i < Na; i++) 
			C[picked[i]] = A[i];
			
		if (isSequence(C, Nb) == 1) {
			print(C, Nb);
			return 1;
		}
		else
			return 0;
	}

	lastIndex = m - toPick - 1; 

	int flag, j;

	for (i = 0; i < Nb; i++) {
		flag = 0;

		for (j = 0; j <= lastIndex; j++) {
			if (picked[j] == i) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) 
			continue;
		                        
		picked[lastIndex + 1] = i;
		cnt += pick(B, Nb, picked, m, toPick - 1, A, Na);
	}
	return cnt;
}
int main(void) {
	int* A, * B, * picked, Na, Nb;

	scanf("%d", &Na);

	A = (int*)malloc(sizeof(int) * Na);

	for (int i = 0; i < Na; i++)
		scanf("%d", &A[i]);
	scanf("%d", &Nb);

	B = (int*)malloc(sizeof(int) * Nb);

	for (int i = 0; i < Nb; i++)
		scanf("%d", &B[i]);
	picked = (int*)malloc(sizeof(int) * Na);

	printf("%d\n", pick(B, Nb, picked, Na, Na, A, Na));
}