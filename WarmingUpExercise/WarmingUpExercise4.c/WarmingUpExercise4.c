#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int arr[5] = { 0 };
	int count = 0;
	int key;
	int i;

	printf("Enter 5개의정수: ");
	for (i = 0; i < 5; i++)
		scanf("%d", &arr[i]);

	printf("Enter a key: ");
	scanf("%d", &key);

	for (i = 0; i < 5; i++) {
		count++;

		if (arr[i] == key)
			break;
	}

	printf("%d번째에 있다", count);
}