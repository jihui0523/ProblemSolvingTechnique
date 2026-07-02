#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void readArray(int a[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		scanf("%d", &a[i]);
}
int compareArray(int a[], int b[], int size)
{
	int i, j, flag = 0;

	for (i = 0; i < size; i++) {
		flag = 0;
		for (j = 0; j < size; j++) {
			if (a[i] == b[j]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			return 0;
	}
	return 1;
}
int main(void)
{
	int arrayA[5], arrayB[5];

	printf("Enter 첫번째 배열:");
	readArray(arrayA, 5);
	printf("Enter 두번째 배열:");
	readArray(arrayB, 5);

	if (compareArray(arrayA, arrayB, 5))
		printf("두 개의 배열은 같다.");
	else
		printf("두 개의 배열은 다르다.");
}