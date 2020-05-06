#ifndef _CHESS_H_
#define _CHESS_H_

#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#pragma warning(disable:4996)

#define BLACK_PIECE 'X'  //����
#define WHITE_PIECE 'O'  //����
#define ROW 3  //���̵ĳ�
#define COL 3  //���εĿ�

void Initboard( char board[][COL],int row,int col);
void Showboard(char board[][COL], int row, int col);
void ComputerMove(char board[][COL], int row, int col);
int PlayerMove(char board[][COL], int row, int col);
char JudgeResult(char board[][COL], int row, int col);

void meau();
void Game();


#endif