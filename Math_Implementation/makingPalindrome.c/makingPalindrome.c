#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int checkPalindrome(char *s,int len) {
	int i;

	for (i = 0; i < len / 2; i++) 
		if (s[i] != s[len - i - 1])
			return 0;
	return 1;
}
int main(void) {
	char s[100]=" ", temp[100] = " ", new[100] = " ";
	int i,j;
	int lenS, lenTemp = 0, count = 0;

	scanf("%s", s);
	lenS = strlen(s);
	lenTemp = lenS;

	for (i = 0; i < lenS; i++)
		temp[i] = s[i];

	if (checkPalindrome(s, lenS)) {
		printf("%s", s);
		return 0;
	}

	for (i = 0; i < lenS; i++) {
		if (checkPalindrome(temp, lenTemp)) {
			count = i;
			break;
		}

		for (j = 0; j < lenTemp; j++) 
			temp[j] = temp[j + 1];
		lenTemp--;
	}

	for (i = 0; i < lenS; i++) 
		new[i] = s[i];
	for (i = 0; i < count; i++)
		new[lenS + i] = s[count-i-1];

	printf("%s", new);
}