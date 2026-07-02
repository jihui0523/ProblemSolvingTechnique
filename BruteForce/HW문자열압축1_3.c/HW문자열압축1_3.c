#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
    int i, j, k;
    char a[1000];
    char b[1000];
    char temp[10];
    int len;
    int count;
    int indexB;
    int minCount = 1000;
    int check = 1;

    scanf("%s", a);
    len = strlen(a);

    for (k = 1; k <= len / 2; k++) {
        count = 1;
        indexB = 0;

        for (i = 0; i < len; i += k) {
            if (i + 2 * k <= len) {
                check = 1;
                for (j = 0; j < k; j++) {
                    if (a[i + j] != a[i + k + j]) {
                        check = 0;
                        break;
                    }
                }
                if (check) {
                    count++;
                    continue;
                }
            }

            if (count >= 2) {
                sprintf(temp, "%d", count);
                for (j = 0; temp[j] != '\0'; j++)
                    b[indexB++] = temp[j];
            }

            for (j = 0; j < k && i + j < len; j++)
                b[indexB++] = a[i + j];

            count = 1;
        }
        b[indexB] = '\0';

        if (indexB < minCount)
            minCount = indexB;
    }

    printf("%d\n", minCount);
}