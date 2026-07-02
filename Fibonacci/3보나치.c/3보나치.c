#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int three_bonachi(int *M,int n) {
	if (n == 1 || n == 2 || n == 3)
		return 1;

	if (M[n] != -1)
		return M[n];
	
	M[n] = three_bonachi(M, n - 1) + three_bonachi(M, n - 2) + three_bonachi(M, n - 3);

	return M[n];
		
}
int main(void) {
	int n;
	int* M;
	int i;

	scanf("%d", &n);

	M = (int*)malloc(sizeof(int) * (n+1));

	for (i = 0; i <= n; i++)
		M[i] = -1;

	printf("%d", three_bonachi(M, n));

	free(M);
}