#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 11
#define COL 11

void menu();
void __menu();
void Choose();//选操作
void Game();
void Init_board(char mine[ROW][COL], char show[ROW][COL]);//初始化
void Display_board(char show[ROW][COL]);//展示
void Set_mine(char mine[ROW][COL]);//设置雷的位置
void Show_board(char mine[ROW][COL]);
void Player(char mine[ROW][COL], char show[ROW][COL]);//玩家走棋
 int Get_mine(char mine[ROW][COL], int i, int j);//查雷
void Open_board(char mine[ROW][COL], char show[ROW][COL], int i, int j);//遇雷展开
void Move_mine(char mine[ROW][COL], int i, int j);//第一次走棋遇雷移开