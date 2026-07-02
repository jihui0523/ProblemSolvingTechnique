#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int toThe1(int n, int* dp, int* next) {

    if (n == 1) 
        return 0;

    if (dp[n] != -1) 
        return dp[n];

    int min = 1000000;
    int choice = -1;

    if (n % 3 == 0) {
        int temp = toThe1(n / 3, dp, next);

        if (temp < min) {
            min = temp;
            choice = n / 3;
        }
    }

    if (n % 2 == 0) {
        int temp = toThe1(n / 2, dp, next);

        if (temp < min) {
            min = temp;
            choice = n / 2;
        }
    }

    int temp = toThe1(n - 1, dp, next);

    if (temp < min) {
        min = temp;
        choice = n - 1;
    }

    dp[n] = min + 1;
    next[n] = choice; 

    return dp[n];
}

int main(void) {
    int N;
    int i;
    int temp;

    scanf("%d", &N);

    int* dp = (int*)malloc(sizeof(int) * (N + 1));
    int* next = (int*)malloc(sizeof(int) * (N + 1));

    for (i = 0; i <= N; i++) {
        dp[i] = -1;
        next[i] = -1;
    }

    printf("%d\n", toThe1(N, dp, next));

    temp = N;

    while (temp != -1) {
        printf("%d ", temp);
        temp = next[temp];
    }

    free(dp);
    free(next);
}