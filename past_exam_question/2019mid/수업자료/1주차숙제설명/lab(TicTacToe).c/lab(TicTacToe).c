#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void display(char b[][3])
{
	char ch;
	int i, j;
	printf("    0 1 2\n");
	printf("   ------\n");
	for (i = 0; i < 3; i++) {
		printf("%d |", i);
		for (j = 0; j < 3; j++)
			printf(" %c", b[i][j]);
		printf("\n");
	}
}
int wincheck(char b[][3])
{
	//성공한 사람이 있나 체크해서
		//있으면 그 플레이어가 이겼다고 출력하고 1을 return;
		//없으면 0을 return;
}
int main(void)
{
	char board[3][3];
	char turn = 'X';
	int r, c;
	int i, j;
	int count;
	int win;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			board[i][j] = ' ';

	count = 1;
	display(board);
	do
	{
		printf("Player %c(행 열):", turn);
		scanf("%d %d", &r, &c);

		if (board[r][c] != ' ') continue;

		count++;
		board[r][c] = turn;
		display(board);
		turn = (turn == 'X' ? 'O' : 'X'); // turn을 바꾼다, X로 시작
	} while (count <= 9);
}