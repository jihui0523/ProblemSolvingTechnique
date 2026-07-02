#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int max1(int list[], int low, int high)
{
	int max = list[low];

	while (low <= high)
	{
		if (list[low] > max)
			max = list[low];
		low++;
	}
	return max;
}
int max2(int list[], int low, int high)
{
	int middle, i, maxRight, maxLeft;

	if (low == high)
		return list[low];

	middle = (low + high) / 2;

	maxRight = max2(list, low, middle);
	maxLeft = max2(list, middle + 1, high);

	if (maxRight > maxLeft)
		return maxRight;
	else
		return maxLeft;
}
int main(void)
{
	int list[] = { 10, 20, 100, 4, 5, 45, 3, 99, 11, 22 };

	printf("가장 큰 수는 %d\n", max1(list, 0, 9)); // 100
	printf("가장 큰 수는 %d\n", max2(list, 0, 9)); // 100

	printf("가장 큰 수는 %d\n", max1(list, 5, 9)); // 99
	printf("가장 큰 수는 %d\n", max2(list, 5, 9)); // 99

	printf("가장 큰 수는 %d\n", max1(list, 3, 6)); // 45
	printf("가장 큰 수는 %d\n", max2(list, 3, 6)); // 45
}