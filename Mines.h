#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 11
#define COL 11

void menu();
void __menu();
void Choose();//ѡ����
void Game();
void Init_board(char mine[ROW][COL], char show[ROW][COL]);//��ʼ��
void Display_board(char show[ROW][COL]);//չʾ
void Set_mine(char mine[ROW][COL]);//�����׵�λ��
void Show_board(char mine[ROW][COL]);
void Player(char mine[ROW][COL], char show[ROW][COL]);//�������
 int Get_mine(char mine[ROW][COL], int i, int j);//����
void Open_board(char mine[ROW][COL], char show[ROW][COL], int i, int j);//����չ��
void Move_mine(char mine[ROW][COL], int i, int j);//��һ�����������ƿ�