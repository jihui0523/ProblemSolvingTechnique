#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int solution(int n){

	int i, len = 0;

	while (n != 0) {
		len++;
		n /= 10;
	}

	return len;
}
int main(void) {
	int n;

	scanf("%d", &n);
	printf("%d", solution(n));
}