#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void display(char b[][3]) {

	int i, j;

	printf("     ");

	for (i = 0; i < 3; i++)
		printf("%2d", i);
	printf("\n     --------\n");

	for (i = 0; i < 3; i++) {

		printf("%3d |", i);

		for (j = 0; j < 3; j++)
			printf(" %c", b[i][j]);
		printf("\n");
	}
}
int main(void)
{
	char board[3][3];
	char turn;
	int r, c;
	int i, j;
	int count = 1;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			board[i][j] = ' ';

	display(board);

	do
	{
		if (count % 2 == 0)
			turn = '0';
		else
			turn = 'X';

		do {
			printf("Player %c(За ї­):", turn);
			scanf("%d %d", &r, &c);
		} while (board[r][c] != ' ');

		board[r][c] = turn;
		display(board);
		count++;
	} while (count <= 9);
}