#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int get_cycle_number(int n) {

	printf("%d ", n);

	if (n == 1)
		return 1;
	else {
		if (n % 2 == 0) 
			n /= 2;
		else 
			n = n * 3 + 1;

		return 1 + get_cycle_number(n);
	}
}
int main() {

	int i, num;

	scanf("%d", &num);

	printf("\n%d", get_cycle_number(num));
}