#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int k_bonachi(int* M, int n,int k) {
	int i;

	if (n <= k)
		return 1;

	if (M[n] != 0)
		return M[n];

	for (i = 0; i < k; i++)
		M[n] += k_bonachi(M, n - 1 - i, k);

	return M[n];

}
int main(void) {
	int n, k;
	int* M;
	int i;

	scanf("%d %d", &n, &k);

	M = (int*)malloc(sizeof(int) * (n + 1));

	for (i = 0; i <= n; i++)
		M[i] = 0;

	printf("%d", k_bonachi(M, n, k));

	free(M);
}