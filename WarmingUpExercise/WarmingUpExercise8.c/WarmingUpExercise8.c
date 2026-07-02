#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void input(char arr[], char store[]) {
   
    int i;

    for (i = 0; arr[i] != '\0'; i++)
        store[i] = arr[i];
    store[i] = '\0';
}
void reverse(char arr[]) {
    
    int n = strlen(arr);
    int i;
    
    for (i = 0; i < n; i++)
        printf("%c", arr[n - 1 - i]);
}
int main(void) {
    
    char a[100] = { 0 };
    char b[100] = { 0 };
    int i;

    printf("* Enter your name: ");
    fgets(a, sizeof(a), stdin);
    a[strcspn(a, "\n")] = '\0';

    input(a, b);

    printf("* Reverse: ");
    reverse(b);  
}