#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int count = 0;
int pick3(int n, int picked[], int* nums, int m, int toPick, int index)
{
	int i;
	
	if (toPick == 0) {
		for (i = 0; i < m; i++) {
			printf("%d ", nums[i]);
		}
		printf("\n");
		count++;
		return count;
	}

	for (i = index; i < n; i++) {
		nums[m - toPick] = picked[i];
		pick3(n, picked, nums, m, toPick - 1, i + 1);
	}
	return count;
}
int main(void)
{
	int picked[7] = { 0 };
	int *nums;
	int m, i;

	for (i = 0; i < 7; i++)
		scanf("%d", &picked[i]);
	scanf("%d", &m);

	nums = (int*)malloc(sizeof(int) * m);

	printf("%d", pick3(7, picked, nums, m, m, 0));

	free(nums);
}