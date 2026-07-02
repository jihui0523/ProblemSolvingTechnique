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
int winCheck(char b[][3], int r, int c) {

    int count, i;

    count = 1;
    for (i = 1; i < 3; i++) {
        if (c - i >= 0 && b[r][c] == b[r][c - i])
            count++;
        else
            break;
    }
    for (i = 1; i < 5; i++) {
        if (c + i < 3 && b[r][c] == b[r][c + i])
            count++;
        else
            break;
    }
    if (count == 3)
        return 1;

    count = 1;
    for (i = 1; i < 3; i++) {
        if (r - i >= 0 && b[r][c] == b[r - i][c])
            count++;
        else
            break;
    }
    for (i = 1; i < 3; i++) {
        if (r + i < 3 && b[r][c] == b[r + i][c])
            count++;
        else
            break;
    }
    if (count == 3)
        return 1;

    count = 1;
    for (i = 1; i < 3; i++) {
        if (r - i >= 0 && c - i >= 0 && b[r][c] == b[r - i][c - i])
            count++;
        else
            break;
    }
    for (i = 1; i < 3; i++) {
        if (r + i < 3 && c + i < 3 && b[r][c] == b[r + i][c + i])
            count++;
        else
            break;
    }
    if (count == 3)
        return 1;

    count = 1;
    for (i = 1; i < 3; i++) {
        if (r - i >= 0 && c + i < 3 && b[r][c] == b[r - i][c + i])
            count++;
        else
            break;
    }
    for (i = 1; i < 3; i++) {
        if (r + i < 3 && c - i >= 0 && b[r][c] == b[r + i][c - i])
            count++;
        else
            break;
    }
    if (count == 3)
        return 1;

    return 0;
}
int main(void)
{
	char board[3][3];
	char turn;
	int r, c;
	int i, j;
	int count = 1;
	int win = 0;

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

		if (winCheck(board, r, c) == 1) {
			printf("Player %c wins!", turn);
			break;
		}
		count++;
	} while (count <= 9);

	if (!win && count == 9)
		printf("Nobody win!\n");
}