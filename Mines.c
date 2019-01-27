#define _CRT_SECURE_NO_DEPRECATE

#include"Mines.h"
//菜单
void menu()    
{
	printf("************************************\n");
	printf("****          Welcome Game      ****\n");
	printf("************************************\n");
	printf("****          1.Play            ****\n");
	printf("****          0.Exit            ****\n");
	printf("************************************\n");
}

void Game()
{
	char show[ROW][COL];
	char mine[ROW][COL];
	Init_board(mine, show);
	Display_board(show);
	Set_mine(mine);
	Show_board(mine);
	Player(mine, show);
}
//初始化棋盘
void Init_board(char mine[ROW][COL], char show[ROW][COL])
{
	for (int i = 1; i < ROW-1; i++)
	{
		for (int j = 1; j < COL-1; j++)
		{
			mine[i][j] = ' 0';
		}
	}
	for (int i = 1; i < ROW-1; i++)
	{
		for (int j = 1; j < COL-1; j++)
		{
			show[i][j] = '*';
		}
	}
}

void Display_board(char show[ROW][COL])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW - 1; i++)
	{
		printf("%d", i);
	}
	for (i = 1; i < ROW - 1; i++)
	{
		printf("\n");
		printf("%d", i);
		for (int j = 1; j < COL - 1; j++)
		{
			printf("%c", show[i][j]);
		}
	}
	printf("\n");
}

void Set_mine(char mine[ROW][COL])
{
	int i = 0;
	int j = 0;
	int count = 10;
	while (count--)
	{
		srand((unsigned)time(NULL));
		i = rand() % 8 + 1;
		j = rand() % 8 + 1;
		if (mine[i][j] = '0')
		{
			mine[i][j] = '1';
		}
	}
}

void Show_board(char mine[ROW][COL])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW - 1; i++)
	{
		printf("%d", i);
	}
	for (i = 1; i < ROW - 1; i++)
	{
		printf("\n");
		printf("%d", i);
		for (j = 1; j < COL - 1; j++)
		{
			printf("%c", mine[i][j]);
		}
	}
	printf("\n");
}

void Player(char mine[ROW][COL], char show[ROW][COL])
{
	int i = 0;
	int j = 0;
	int count = 71;
	int input = 0;
	while (input)
	{
		do
		{
			__menu();
			printf("Please input:");
			scanf("%d", &input);
			switch (input)
			{
			case 1:
				printf("Please enter coordinate:");
				scanf("%d%d", &i, &j);
				if (count == 71)
				{
					Move_mine(mine, i, j);
				}
				if (mine[i][j] == '1')
				{
					printf("Step on thunder!\n");
					Show_board(mine);
					return;
				}
				else
				{
					Open_board(mine, show, i, j);
					Display_board(show);
					count--;
				}
				break;
			case 0:
				printf("Please enter coordinate:");
				scanf("%d%d", &i, &j);
				if (show[i][j] == '*')
				{
					show[i][j] = '!';
				}
				else
				{
					show[i][j] = '*';
				}
				Display_board(show);
				break;
			default:
				printf("Input error,please enter again!\n");
				break;
			}
			break;
		} while (input);
	}
	printf("Successfully Minesweeping!\n");
}

int Get_mine(char mine[ROW][COL], int i, int j)
{
	int count = 0;
	if (mine[i - 1][j] == '1')
	{
		count++;
	}
	if (mine[i - 1][j-1] == '1')
	{
		count++;
	}
	if (mine[i][j-1] == '1')
	{
		count++;
	}
	if (mine[i][j+1] == '1')
	{
		count++;
	}
	if (mine[i+1][j] == '1')
	{
		count++;
	}
	if (mine[i - 1][j+1] == '1')
	{
		count++;
	}
	if (mine[i+1][j] == '1')
	{
		count++;
	}
	if (mine[i +1][j+1] == '1')
	{
		count++;
	}
	return count;
}

void Open_board(char mine[ROW][COL], char show[ROW][COL], int i, int j)
{
	if (mine[i][j] == '0'&&i >= 0 && j >= 0 && show[i][j] == '*')
	{
		show[i][j] = Get_mine(mine, i, j) + '0';
	}
	if (mine[i][j - 1] == '0'&&i >= 0 && j - 1 >= 0 && show[i][j - 1] == '*')
	{
		show[i][j - 1] = Get_mine(mine, i, j - 1) + '0';
		if (Get_mine(mine, i, j - 1) == 0)
		{
			Open_board(mine, show, i, j - 1);
		}
	}
	if (mine[i][j + 1] == '0'&&i >= 0 && j + 1 >= 0 && show[i][j + 1] == '*')
	{
		show[i][j + 1] = Get_mine(mine, i, j + 1) + '0';
		if (Get_mine(mine, i, j + 1) == 0)
		{
			Open_board(mine, show, i, j + 1);
		}
	}
	if (mine[i - 1][j] == '0'&&i - 1 >= 0 && j >= 0 && show[i - 1][j] == '*')
	{
		show[i - 1][j] = Get_mine(mine, i - 1, j) + '0';
		if (Get_mine(mine, i - 1, j) == 0)
		{
			Open_board(mine, show, i - 1, j);
		}
	}
	if (mine[i - 1][j - 1] == '0'&&i - 1 >= 0 && j - 1 >= 0 && show[i - 1][j - 1] == '*')
	{
		show[i - 1][j - 1] = Get_mine(mine, i - 1, j - 1) + '0';
		if (Get_mine(mine, i - 1, j - 1) == 0)
		{
			Open_board(mine, show, i - 1, j - 1);
		}
	}
	if (mine[i - 1][j + 1] == '0'&&i - 1 >= 0 && j + 1 >= 0 && show[i - 1][j + 1] == '*')
	{
		show[i - 1][j + 1] = Get_mine(mine, i - 1, j + 1) + '0';
		if (Get_mine(mine, i - 1, j + 1) == 0)
		{
			Open_board(mine, show, i - 1, j + 1);
		}
	}
	if (mine[i + 1][j + 1] == '0'&&i + 1 >= 0 && j + 1 >= 0 && show[i + 1][j + 1] == '*')
	{
		show[i + 1][j + 1] = Get_mine(mine, i + 1, j + 1) + '0';
		if (Get_mine(mine, i + 1, j + 1) == 0)
		{
			Open_board(mine, show, i + 1, j + 1);
		}
	}
	if (mine[i + 1][j] == '0'&&i + 1 >= 0 && j >= 0 && show[i + 1][j] == '*')
	{
		show[i + 1][j] = Get_mine(mine, i + 1, j) + '0';
		if (Get_mine(mine, i + 1, j) == 0)
		{
			Open_board(mine, show, i + 1, j);
		}
	}
	if (mine[i + 1][j - 1] == '0'&&i + 1 >= 0 && j - 1 >= 0 && show[i + 1][j - 1] == '*')
	{
		show[i + 1][j - 1] = Get_mine(mine, i + 1, j - 1) + '0';
		if (Get_mine(mine, i + 1, j - 1) == 0)
		{
			Open_board(mine, show, i + 1, j - 1);
		}
	}
}

void Move_mine(char mine[ROW][COL], int i, int j)
{
	srand((unsigned int)time(NULL));
	while (1)
	{
		if (mine[i][j] = '1')
		{
			int x = rand() % 8 + 1;
			int y = rand() % 8 + 1;
			mine[i][j] = '0';
			mine[x][y] = '1';
		}
	}
}

void __menu()
{
	printf("**** 1.Start  2.Thunder & Withdraw ****\n");
}

void Choose()
{
	int input = 0;
	do
	{
		menu();
		printf("Please enter option:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("Please exit!\n");
			break;
		case 1:
			printf("Are you ready? Games Start!\n");
			Game();
			break;
		default:
			printf("Input error,please enter again!\n");
			break;
		}
	} while (input);
}
