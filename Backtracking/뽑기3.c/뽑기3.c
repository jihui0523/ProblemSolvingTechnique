#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int is_prime(int num)
{
	int i;

	if (num == 1)
		return 0;

	for (i = 2; i < num; i++)
		if (num % i == 0)
			return 0;
	return 1;
}
int pick3(int n, int picked[], int* nums, int m, int toPick, int index)
{
	int i;
	int sum = 0;
	int count = 0;

	if (toPick == 0) {
		for (i = 0; i < m; i++)
			sum += nums[i];

		if (is_prime(sum)) {
			for (i = 0; i < m; i++) {
				printf("%d", nums[i]);
				if (i < m - 1)
					printf(" + ");
			}
			printf(" = %d\n", sum);
			return 1;
		}
		else
			return 0;
	}

	for (i = index; i < n; i++) {
		nums[m - toPick] = picked[i];
		count += pick3(n, picked, nums, m, toPick - 1, i + 1);
	}
	return count;
}
int main(void)
{
	int picked[7] = { 0 };
	int* nums;
	int m, i;
	int count;

	for (i = 0; i < 7; i++)
		scanf("%d", &picked[i]);
	scanf("%d", &m);

	count = 0;

	nums = (int*)malloc(sizeof(int) * m);

	count = pick3(7, picked, nums, m, m, 0);
	printf("%d", count);

	free(nums);
}