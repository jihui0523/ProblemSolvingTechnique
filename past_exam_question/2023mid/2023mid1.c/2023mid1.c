#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int arithmetic(int n, int nums[]) {
	int i;

	for (i = 0; i < n - 2; i++) 
		if (nums[i + 1] - nums[i] != (nums[i + 2] - nums[i + 1]))
			return 0;
	return 1;
}
int main(void) {
	int n;
	int i;
	int nums[100];

	scanf("%d", &n);
	for (i = 0; i < n; i++) 
		scanf("%d", &nums[i]);

	printf("%d", arithmetic(n, nums));
}