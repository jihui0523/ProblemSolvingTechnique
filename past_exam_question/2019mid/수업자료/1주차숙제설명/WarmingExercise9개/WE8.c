#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // 문자열 길이 구하기 위함

void input(char a[]);
void reverse(char a[]);

int main(void) {
	char a[100];

	printf("Enter your name: ");
	input(a);

	printf("Reverse: ");
	reverse(a);
}

void input(char a[]) {
	scanf("%s", a);
}

void reverse(char a[]) {
	int len = strlen(a); // 문자열 길이 구하기 위함

	for (int i = len - 1; i >= 0; i--)
		printf("%c", a[i]);
}