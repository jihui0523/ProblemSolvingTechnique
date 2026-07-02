#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char sentence[80];
char encodedSentence[80];
char decodedSentence[80];

void makeCode(char code[], int dist, char* key) {
	int i, j;
	int kLen = strlen(key);
	int used[26] = { 0 };
	int index = 0;
	char temp[26] = { 0 };

	for (i = 0; i < kLen; i++) {
		if (key[i] >= 'A' && key[i] <= 'Z' && !used[key[i] - 'A']) {
			used[key[i] - 'A'] = 1;
			code[index++] = key[i];
		}
	}

	for (i = 0; i < 26; i++) 
		if (!used[i]) 
			code[index++] = 'A' + i;

	if (dist < 0)
		dist = (26 + (dist % 26)) % 26;
	else
		dist = dist % 26;

	for (i = 0; i < 26; i++) 
		temp[(i + dist) % 26] = code[i];
	
	for (i = 0; i < 26; i++) 
		code[i] = temp[i];
}

void printCode(char code[]) {
	int i;

	printf("--------------------------------\n");
	printf("alphabet: ");
	for (i = 0; i < 26; i++)
		printf("%c", 'A' + i);

	printf("\nencoded: ");
	for (i = 0; i < 26; i++)
		printf("%c", code[i]);
	printf("\n--------------------------------\n");
}

void remove_duplicated_char(char* word) {
	int i, j, len = strlen(word);
	char temp[30];
	int idx = 0;
	int check[26] = { 0 };

	for (i = 0; i < len; i++) {
		if (word[i] >= 'A' && word[i] <= 'Z') {
			if (!check[word[i] - 'A']) {
				check[word[i] - 'A'] = 1;
				temp[idx++] = word[i];
			}
		}
	}
	temp[idx] = '\0';
	strcpy(word, temp);
}

int main(void)
{
	int distance;
	char key[30];
	char code[26];

	printf("Enter a distance for encoding:");
	scanf("%s", key);

	printf("Enter a word to use for encoding:");
	scanf("%d", &distance);

	remove_duplicated_char(key);
	makeCode(code, distance, key);
	printCode(code);
}