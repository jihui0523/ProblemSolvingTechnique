#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void echo(int arr[], int store[]) {

	int i;

	for (i = 0; i < 5; i++)
		store[i] = arr[i];
}
void reverse(int arr[]) {

	int i;

	for (i = 0; i < 5; i++)
		printf("%d ", arr[4 - i]);
}
int main(void) {

	int a[5] = { 0 };
	int b[5] = { 0 };
	int i;

	for (i = 0; i < 5; i++) 
		scanf("%d", &a[i]);

	echo(a, b);

	for (i = 0; i < 5; i++)
		printf("%d ", b[i]);
	printf("\n");
	reverse(a);
}