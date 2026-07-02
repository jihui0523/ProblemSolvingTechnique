#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void echo(int a[], int size);
void reverse(int a[], int size);

int main(void) {
	int a[5];

	printf("Enter 5개의 정수: ");
	echo(a, 5);

	printf("Reverse: ");
	reverse(a, 5);
}

void echo(int a[], int size) {
	for (int i = 0; i < size; i++)
		scanf("%d", &a[i]);
}

void reverse(int a[], int size) {
	for (int i = size - 1; i >= 0; i--)
		printf("%d ", a[i]);
}