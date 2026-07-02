#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void matrixMuti(int** a, int** b, int** x, int Ar, int Ac, int Cc) {
	int i, j, k;
	for (i = 0; i < Ar; i++) {
		for (j = 0; j < Cc; j++) {
			x[i][j] = 0;
			for (k = 0; k < Ac; k++) 
				x[i][j] += a[i][k] * b[k][j];
		}
	}
}

void matrixMTransposed(int** a, int** x, int r, int c) {
	int i, j;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			x[j][i] = a[i][j];
}

void printMatrix(int** a, int r, int c) {
	int i, j;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
}

void readMatrix(int** a, int r, int c) {
	int i, j;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			scanf("%d", &a[i][j]);
}

int main(void) {
	int** A, ** C;
	int** X1, ** X2;
	int Ar, Ac, Cr, Cc;
	int i;

	printf("Enter 행렬 A의 행과 열의 개수: ");
	scanf("%d %d", &Ar, &Ac);
	printf("Enter 행렬 C의 행과 열의 개수<C의 행은 %d이어야>: ", Ac);
	scanf("%d %d", &Cr, &Cc);

	A = (int**)malloc(sizeof(int*) * Ar);
	for (i = 0; i < Ar; i++)
		A[i] = (int*)malloc(sizeof(int) * Ac);

	C = (int**)malloc(sizeof(int*) * Cr);
	for (i = 0; i < Cr; i++)
		C[i] = (int*)malloc(sizeof(int) * Cc);

	X1 = (int**)malloc(sizeof(int*) * Ar);
	for (i = 0; i < Ar; i++)
		X1[i] = (int*)malloc(sizeof(int) * Cc);

	X2 = (int**)malloc(sizeof(int*) * Ac);
	for (i = 0; i < Ac; i++)
		X2[i] = (int*)malloc(sizeof(int) * Ar);

	printf("%d × %d 행렬 A 입력:\n", Ar, Ac);
	readMatrix(A, Ar, Ac);
	printf("%d × %d 행렬 C 입력:\n", Cr, Cc);
	readMatrix(C, Cr, Cc);

	matrixMuti(A, C, X1, Ar, Ac, Cc);
	printf("행렬곱 결과:\n");
	printMatrix(X1, Ar, Cc);  

	matrixMTransposed(A, X2, Ar, Ac); 
	printf("전치행렬:\n");
	printMatrix(X2, Ac, Ar);  

	for (i = 0; i < Ar; i++) 
		free(A[i]);
	for (i = 0; i < Cr; i++) 
		free(C[i]);
	for (i = 0; i < Ar; i++) 
		free(X1[i]);
	for (i = 0; i < Ac; i++) 
		free(X2[i]);
	free(A); 
	free(C); 
	free(X1);
	free(X2);
}