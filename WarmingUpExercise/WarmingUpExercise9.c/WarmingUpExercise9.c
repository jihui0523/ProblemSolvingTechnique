#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {

	int i;
	int a[5] = { 0 };
	int b[5] = { 0 };
	int flag = 1;

	printf("Enter 첫번째 배열: ");
	for (i = 0; i < 5; i++)
		scanf("%d", &a[i]);

	printf("Enter 두번째 배열: ");
	for (i = 0; i < 5; i++)
		scanf("%d", &b[i]);

	for (i = 0; i < 5; i++) {
		if (a[i] != b[i]) {
			flag = 0;
			break;
		}
	}

	if(flag == 0)
		printf("두 배열은 같지 않다");
	else
		printf("두 배열은 같다");
}