#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
int left_max_sum(int A[], int left, int right) {
	int i, j, sum, max = INT_MIN, count = 0;

	for (i = left; i <= right; i++) {
		sum = 0;

		for (j = right; j >= right - count; j--)
			sum += A[j];

		count++;

		if (sum > max)
			max = sum;
	}
	return max;
}
int main() {
	int A[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

	//int max = left_max_sum(A, 4, 6); // A[6], A[5]+A[6], A[4]+A[5]+A[6], 중에서 최대값, 즉 3
	//int max = left_max_sum(A, 0, 4); // 최대값 3
	int max = left_max_sum(A, 4, 7); // 최대값-2
	printf("max value = % d\n", max);
}