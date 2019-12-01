#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 3
#define MAX_COL 3

int Menu()
{
	printf("=================\n");
	printf("欢迎来到三子棋游戏!\n");
	printf("=================\n");
	printf("1.Start\n");
	printf("2.End\n");
	printf("请输入您的选择:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void Init(char chessBoard[MAX_ROW][MAX_COL])
{
	for (int row = 0; row < MAX_ROW; row++)
	{
		for (int col = 0; col < MAX_COL; col++)
		{
			chessBoard[MAX_ROW][MAX_COL] = ' ';
		}
		srand((unsigned int)time(NULL));
	}

}

void Print(char chessBoard[MAX_ROW][MAX_COL])
{
	for (int row = 0; row < MAX_ROW; row++)
	{
		for (int col = 0; col < MAX_COL; col++)
		{
			//%C打印一个字符
			printf("%c \n",chessBoard[row][col]);
		}
		printf("\n");
	}
}
void PlayerMove(char chessBoard[MAX_ROW][MAX_COL])
{
	//正式开始玩了,玩家先落棋
	while (1)
	{
		printf("玩家落棋\n");
		printf("请选择你要落的位置:");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row >= MAX_ROW || row < 0 || col < 0 || col >= MAX_COL)
		{
			printf("error,请重新输入");
			continue;
		}
		if (chessBoard[row][col] != ' ')
		{
			printf("此地有子了");
			continue;
		}
		chessBoard[row][col] = 'X';
		break;
	}
}

void ComputerMove(char chessBoard[MAX_ROW][MAX_COL])
{
	printf("电脑落棋\n");
	while (1)
	{
		int row = rand() % MAX_ROW;//只要 012 中产生随机数 3 可能会在很多地方使用 故直接用MAXROW
		int col = rand() % MAX_COL;
		if (chessBoard[row][col] != ' ')
			//此地有子,重随机
		{
			continue;
		}
		chessBoard[row][col] = 'O';
		break;
	}
	
}


int IsFull(char chessBoard[MAX_ROW][MAX_COL])
{
	//查找看看能不能找到空格,如果找到了 ,那说明没满,否则满了,那说明就是个平局
	for (int row = 0; row < MAX_ROW; row++)
	{
		for (int col = 0; col < MAX_COL; col++)
		{
			if (chessBoard[row][col] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
//以下检测 游戏是否结束 还有谁赢了
//X玩家 win
//O电脑 win
//' ' 还没分出胜负
//Q 平了
char Check(char chessBoard[MAX_ROW][MAX_COL])
{
	//行 列 对角线 分别查 是否连成线
	for (int row = 0; row < MAX_ROW; row++)
	{
		if (chessBoard[row][0] != ' ' 
			&& chessBoard[row][0] == chessBoard[row][1]
			&& chessBoard[row][0] == chessBoard[row][2])
		{
			return chessBoard[row][0];
		}
	}

	for (int col = 0; col < MAX_COL; col++)
	{
		if (chessBoard[0][col] != ' '
			&& chessBoard[0][col] == chessBoard[1][col]
			&& chessBoard[0][col] == chessBoard[2][col])
		{
			return chessBoard[0][col];
		}
	}
	if (chessBoard[0][0] != ' '
		&& chessBoard[0][0] == chessBoard[1][1]
		&& chessBoard[0][0] == chessBoard[2][2])
	{
		return chessBoard[0][0];
	}
	if (chessBoard[0][0] != ' '
		&& chessBoard[0][2] == chessBoard[1][1]
		&& chessBoard[0][2] == chessBoard[2][0])
	{
		return chessBoard[0][2];
	}
	if (IsFull(chessBoard))
	{
		return 'Q';
	}
	else
	{
		return ' ';
	}
}


void Game()
{
	/*创建一个棋盘9*9的
	把棋盘打印出来(每个位置都是空格 见void Init)
	玩家出
	判断一下是否结束
	电脑出
	判断一下是否结束*/
	char chessBoard[MAX_ROW][MAX_COL];
	Init (chessBoard);
	char winner = 0;
	while (1)
	{
		Print(chessBoard);
		PlayerMove(chessBoard);
		winner = Check(chessBoard);
		if (winner != ' ')
		{
			break;
		}

		ComputerMove(chessBoard);
		if (winner != ' ')
		{
			break;
		}


		if (winner == 'X')
		{
			printf("你赢了\n");
		}
		else if (winner == 'O')
		{
			printf("你太弱了\n");
		}
		else
		{
			printf("你和电脑半斤八两\n");
		}
	}
	
}

int main()
{
	int choice = Menu();
	while (1)
	{
		if (choice = 1)
		{
			Game();
		}
		else if (choice = 0)
		{
			printf("Bye!\n");
		}
		else
		{
			printf("error");
		}
	}




	system("pause");
	return 0;
}