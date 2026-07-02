#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
int main(void) {

	char a[1000];
	char b[1000];
	int indexB = 0;
	int i;
	int count = 1;
	int len;
	char temp[100];
	int flag = 0;

	scanf("%s", a);

	len = strlen(a);

	for (i = 1; i <= len; i++) {
		if (a[i]==a[i-1]) 
			count++;
		else {
			if (count >= 2) {
				sprintf(temp, "%d", count);
				for (int j = 0; temp[j] != '\0'; j++) 
					b[indexB++] = temp[j];
				if (count >= 10)
					flag++;
			}
			b[indexB++] = a[i-1];
			count = 1;
		}
		
	}
	b[indexB] = '\0';

	printf("%s\n", b);
	printf("%d", indexB-flag);
}