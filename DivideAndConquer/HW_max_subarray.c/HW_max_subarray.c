#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
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
int right_max_sum(int A[], int left, int right) {

	int i, j, sum, max = 0, count = 0;

	for (i = left; i <= right; i++) {
		sum = 0;

		for (j = left; j <= left + count; j++)
			sum += A[j];

		count++;

		if (sum > max)
			max = sum;
	}
	return max;
}
int max_subArray(int A[], int left, int right) {

	int mid = (left + right) / 2;
	int V1;
	int V2;
	int V3 = 0;
	int i, j, sum, max = INT_MIN, count = 0;

	if (left == right)
		return A[left];

	V1 = max_subArray(A, left, mid);
	V2 = max_subArray(A, mid + 1, right);
	V3 = left_max_sum(A, left, mid) + right_max_sum(A, mid + 1, right);

	if (V1 >= V2 && V1 >= V3)
		return V1;
	else if (V2 >= V1 && V2 >= V3)
		return V2;
	else
		return V3;
}
int main() {
	//int A[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 }; // tc #1: max는 6
	//int A[] = {2, -1, 5, -2, 2, -3, 1}; // tc #2: max는 6
	//int A[] = {3, -1, 1, 2, 3, 1, -1, 5}; // tc #3: max는 13
	//int A[] = {1, 2, 3}; // tc #4: max는 6
	int A[] = {-1, -2, -3, -4}; //tc #5: max는-1
	//int A[] = {5}; // tc #6: max는 5
	int lastIndex = sizeof(A) / sizeof(int) - 1;
	int max = max_subArray(A, 0, lastIndex);

	printf("max value = %d\n", max);
}