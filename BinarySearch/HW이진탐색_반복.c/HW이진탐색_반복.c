#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int list[10] = { 1,3,5,6,7,9,11,20,30 };
int search_binary2(int key, int low, int high)
{
	int middle;

	while (low <= high) { 
		middle = (low + high) / 2;

		if (list[middle] == key)
			return middle;
		else if (list[middle] < key) {
			low = middle + 1;

		}
		else if (list[middle] > key) {
			high = middle + 1;
		}
	}
	return -1;
}
int main(void) {

	int n;

	scanf("%d", &n);

	printf("%d", search_binary2(n, 0, 9));
}