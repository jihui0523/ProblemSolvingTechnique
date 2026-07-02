//컴퓨터학과 2 20240794 김은우
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isPrime(int n) //소수판별
{
	int i;
	for (i = 2; i < n; i++)
		if (n % i == 0)
			return 0;
	return 1;
}

int equalArray(int a[], int aSize, int b[], int bSize) //베열 판단
{
	int i;
	if (aSize != bSize)
		return 0;
	else
		for (i = 0; i < aSize; i++)
			if (a[i] != b[i])
				return 0;
	return 1;
}

int search(int a[], int sizeA, int key) //서치
{
	int i;
	for (i = 0; i < sizeA; i++)
		if (key == a[i])
			return i + 1;
	return -1;
}
