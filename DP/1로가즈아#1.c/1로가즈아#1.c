#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int toThe1(int n) {

	int min = 101;
	int count;

	if (n==1) 
		return 0;
	
	if (n % 3 == 0) {
		count = toThe1(n / 3);
		if (count < min)
			min = count;
	}

	if (n % 2 == 0) {
		count = toThe1(n / 2);
		if (count < min)
			min = count;
	}

	count = toThe1(n - 1);
	if (count < min)
		min = count;

	return min + 1;
}
int main(void) {
	int N;
	
	scanf("%d", &N);
	printf("%d", toThe1(N));
}