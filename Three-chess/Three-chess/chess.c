#include "chess.h"


void Initboard(char board[][COL], int row, int col) //初始化棋盘，将棋盘内容全部初始化为空格
{
	int i = 0;
	for (; i < row; i++)
	{
		int j = 0;
		for (; j < col; j++)
		{
			board[i][j] = ' ';
		}
	} 
}

void Showboard(char board[][COL], int row, int col)//打印棋盘
{
	printf("   | 1 | 2 | 3 |\n");
	for (int i = 0; i < row; i++)
	{
			printf("----------------\n");
			printf(" %d | %c | %c | %c |\n", i + 1, board[i][0], board[i][1], board[i][2]);
	}
}

int PlayerMove(char board[][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("请输入你的坐标<x,y>：");
	if ((x >= 1 && x <= 3) && (y >= 1 && y <= 3))
	{
		if (board[x - 1][y - 1] != ' ')
		{
			return 2;
		}
		else
		{
			board[x - 1][y - 1] != BLACK_PIECE;
			return 0;
		}
	}
	else
	{
		return 1;
	}
}
char JudgeResult(char board[][COL], int row, int col)
{
	int i = 0;
	for (; i < row; i++)
	{
		if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2])
		{
			return board[i][0];
		}
	}
	for (; i < col; i++)
	{
		if (board[0][i] != ' ' &&board[0][i] == board[1][i] && board[0][i] == board[2][i])
		{
			return board[0][i];
		}
	}
	if (board[0][0] != ' '&&board[0][0] == board[1][1] && board[][1] == board[2][2])
	{
		return board[0][0];
	}
	if (board[0][2] != ' '&&board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		return board[1][1];
	}
	for (; i < row; i++)
	{
		int j = 0;
		for (; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 'N';
			}
		}
	}
	return 'E';
}
void Game()
{
	
	char board[ROW][COL];
	Initboard(board,ROW,COL);
	Showboard(board,ROW,COL);
	int num =PlayerMove(board,ROW, COL);
	if (1 == num){
		printf("你输入的坐标有误，请重新输入！\n");
	}
	else if (2 == num)
	{
		printf("对不起！你输入的坐标已经被占用，请重新输入！\n");
	}
	else
	{

	}
}