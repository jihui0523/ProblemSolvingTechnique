#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, carry = 0;
	int n1, n2;
	int temp1, temp2;

	scanf("%d %d", &n1, &n2);

	while (n1 != 0 && n2 != 0) {
		
		temp1 = n1 % 10;
		temp2 = n2 % 10;

		n1 /= 10;
		n2 /= 10;

		if (temp1 + temp2 >= 10) {
			carry++;
			n1++;
		}
	}

	printf("%d", carry);
}