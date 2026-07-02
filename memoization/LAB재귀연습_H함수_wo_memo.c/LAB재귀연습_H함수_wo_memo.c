#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
long long memo[1001];
long long H(long long n)
{
    if (memo[n] != -1)
        return memo[n];

    long long sum = 0;

    for (int i = 0; i < n; i++)
        sum += H(i) * H(n - 1 - i);
    memo[n] = sum;

    return sum;
}

int main(void)
{
    long long n;
    int i;

    scanf("%lld", &n);

    for (i = 0; i <= n; i++)
        memo[i] = -1;

    memo[0] = 1;
    memo[1] = 1;

    printf("%lld\n", H(n));
}