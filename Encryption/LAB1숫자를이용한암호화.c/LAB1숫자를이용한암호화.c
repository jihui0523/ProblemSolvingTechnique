#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void makeCode(char code[], int dist) { 
	int i; 
	int up=0;

	for (i = 0; i < 26; i++) {
		code[i] = 'A' + i + dist;
		if (i >= 26 - dist) {
			code[i] = 'A' + up;
			up++;
		}
	}
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
void encode(char code[], char s[], char e[]) { 
	int i;

	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			e[i] = code[s[i] - 'A'];
		else
			e[i] = s[i];
	}
	e[i] = '\0';
}
int main(void)
{
	char code[26];
	int distance;
	char sentence[80];
	char encodedSentence[80];
	char decodedSentence[80];

	printf("Enter a distance for encoding:");
	scanf("%d", &distance);
	while (getchar() != '\n');

	makeCode(code, distance);
	printCode(code);

	printf("Enter a sentence to encode:");
	fgets(sentence, sizeof(sentence), stdin);

	encode(code, sentence, encodedSentence);
	printf("original sentence:\t");
	puts(sentence);

	printf("encoded sentence:\t");
	puts(encodedSentence);
}