#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
    char a[1000];
    char b[1000];
    char temp[10];
    int len;
    int count = 1;
    int indexB = 0;

    scanf("%s", a);
    len = strlen(a);

    for (int i = 0; i < len; i += 2) {
        if (i + 2 < len && a[i] == a[i + 2] && a[i + 1] == a[i + 3]) 
            count++;
        else {
            if (count >= 2) {
                sprintf(temp, "%d", count);
                for (int j = 0; temp[j] != '\0'; j++)
                    b[indexB++] = temp[j];
            }
            b[indexB++] = a[i];
            if (i + 1 < len)
                b[indexB++] = a[i + 1];
            count = 1;
        }
    }
    b[indexB] = '\0';

    printf("%s\n", b);
    printf("%d\n", indexB);
}