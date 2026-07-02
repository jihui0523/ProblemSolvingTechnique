#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick3(int n, int picked[], int *nums, int m, int toPick, int index)
{
	int i;

	if (toPick == 0) {
		for (i = 0; i < m; i++) {
			printf("%d ", nums[i]);
		}
		printf("\n");
		return;
	}

	for (i = index; i < n; i++) {
		nums[m - toPick] = picked[i]; 
		pick3(n, picked, nums, m, toPick - 1, i + 1);  
	}
}
int main(void)
{
	int picked[7] = { 0 };
	int *nums;
	int m = 0, i;

	for (i = 0; i < 7; i++)
		scanf("%d", &picked[i]);

	nums = (int*)malloc(sizeof(int) * m);

	scanf("%d", &m);
	pick3(7, picked, nums, m, m, 0);
}