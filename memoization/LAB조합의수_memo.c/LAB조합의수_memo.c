#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int comb(int **M, int n, int r)
{
	if (r == 0 || r == n)
		return 1;
	else {
		if (M[n - 1][r - 1] == -1)
			M[n - 1][r - 1] = comb(M, n - 1, r - 1);

		if (M[n - 1][r] == -1)
			M[n - 1][r] = comb(M, n - 1, r);

		return M[n - 1][r - 1] + M[n - 1][r];
	}
}
int main(void)
{
	int C;
	int n, r;
	int** M;
	int i,j;

	scanf("%d %d", &n, &r);

	M = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
		M[i] = (int*)malloc(sizeof(int) * (r +1));
	

	for (i = 0; i <n; i++) 
		for (j = 0; j <= r; j++) 
			M[i][j] = -1;

	C = comb(M, n, r); // 4C2
	printf("%d", C); // 6    

	return 0;
}