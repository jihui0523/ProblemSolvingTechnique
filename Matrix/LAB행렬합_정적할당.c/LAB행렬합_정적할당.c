#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void readMatrix(int (*a)[3]) {
	int i, j;

	for (i = 0; i < 3; i++) 
		for (j = 0; j < 3; j++)
			scanf("%d", &a[i][j]);
}
void matrixAdd(int (*a)[3], int (*b)[3], int (*x)[3]) {
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			x[i][j] = a[i][j] + b[i][j];
}
void printMatrix(int (*a)[3]) {
	int i, j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
}
int main(void) {
	int A[3][3] = { 0 };
	int B[3][3] = { 0 };
	int X[3][3] = { 0 };

	printf("< 3 * 3 > 행렬 A 입력:\n");
	readMatrix(A);
	printf("< 3 * 3 > 행렬 B 입력:\n");
	readMatrix(B);

	matrixAdd(A, B, X);
	printf("행렬합:\n");
	printMatrix(X);
}