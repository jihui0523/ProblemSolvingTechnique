#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int H(int n) {

	int total = 0, i;

	if (n == 0 || n == 1)
		return 1;
	else {
		for (i = 0; i < n; i++)
			total += H(n - i - 1) * H(i);
	}
	return total;
}
int main() {

	int n;

	scanf("%d", &n);
	printf("%d", H(n));
}