#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int isEven(int n) {
    return n % 2 == 0;
}

int pick(int n, int picked[], int m, int toPick, int even, int** M) {
    int smallest, lastIndex, i, checkEven = 0, sum = 0;

    if (toPick == 0) {
        for (i = 0; i < m; i++)
            if (isEven(picked[i]))
                checkEven++;
        if (checkEven >= even)
            return 1;
        return 0;
    }

    if (M[m][toPick] != -1)
        return M[m][toPick];

    lastIndex = m - toPick - 1;

    if (m == toPick)
        smallest = 1; 
    else
        smallest = picked[lastIndex] + 1;

    for (i = smallest; i <= n; i++) {
        picked[lastIndex + 1] = i;
        sum += pick(n, picked, m, toPick - 1, even, M);
    }

    M[m][toPick] = sum;

    return sum;
}

int main(void) {
    int N, M, L;
    int i, j;
    int picked[100] = { 0 };
    int** memo;

    scanf("%d %d %d", &N, &M, &L);

    memo = (int**)malloc(sizeof(int*) * (M + 1));
    for (i = 0; i <= M; i++) {
        memo[i] = (int*)malloc(sizeof(int) * (M + 1));
        for (j = 0; j <= M; j++) {
            memo[i][j] = -1;  
        }
    }

    printf("%d\n", pick(N, picked, M, M, L, memo));

    for (i = 0; i <= M; i++) 
        free(memo[i]);
    free(memo);
}