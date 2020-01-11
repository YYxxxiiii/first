#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int Menu() {
	printf("=====================\n");
	printf("欢迎来到三子棋游戏!\n");
	printf("1. 开始游戏\n");
	printf("0. 退出游戏\n");
	printf("=====================\n");
	printf("请输入您的选择: ");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

#define MAX_ROW 3
#define MAX_COL 3

void Init(char chessBoard[MAX_ROW][MAX_COL]) {
	//for (int row = 0; row < MAX_ROW; row++) {
	//	for (int col = 0; col < MAX_COL; col++) {
	//		chessBoard[row][col] = ' ';
	//	}
	//}
	srand((unsigned int)time(0));
	memset(chessBoard, ' ', MAX_ROW * MAX_COL * sizeof(char));
}

void Print(char chessBoard[MAX_ROW][MAX_COL]) {
	// 把棋盘的内容打印出来
	for (int row = 0; row < MAX_ROW; row++) {
		printf("+---+---+---+\n");
		printf("| %c | %c | %c |\n", chessBoard[row][0],
			chessBoard[row][1], chessBoard[row][2]);
	}
	printf("+---+---+---+\n");
}

void PlayerMove(char chessBoard[MAX_ROW][MAX_COL]) {
	printf("轮到玩家落子!\n");
	while (1) {
		printf("请输入您要落子位置的坐标(row col):");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		// 永远无法知道用户会输入什么样的数据. 
		// 尽可能的对用户的输入进行校验. 如果发现输入数据非法
		// 就要进行对应的处理
		if (row < 0 || row >= MAX_ROW
			|| col < 0 || col >= MAX_COL) {
			printf("您的输入有误! \n");
			continue;
		}
		if (chessBoard[row][col] != ' ') {
			// 当前位置已经有子了, 不能再重复落子
			printf("该位置已经有子了!\n");
			continue;
		}
		chessBoard[row][col] = 'X';
		break;
	}
}

void ComputerMove(char chessBoard[MAX_ROW][MAX_COL]) {
	printf("轮到电脑落子!\n");
	while (1) {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (chessBoard[row][col] != ' ') {
			continue;
		}
		chessBoard[row][col] = 'O';
		break;
	}
}

// 判定棋盘是否满了. 如果满了返回 1, 否则返回 0
int IsFull(char chessBoard[MAX_ROW][MAX_COL]) {
	// 查找一下棋盘上是否有空位
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			if (chessBoard[row][col] == ' ') {
				// 找到空位了!!! 棋盘没满
				return 0;
			}
		}
	}
	// 所有位置都找完了, 也没找到空格, 最终才返回 1
	return 1;
}

// 返回值表示游戏的状况
// 1. 返回 X 表示玩家获胜
// 2. 返回 O 表示电脑获胜
// 3. 返回 ' ' 表示还未分胜负
// 4. 返回 Q 表示和棋
char Check(char chessBoard[MAX_ROW][MAX_COL]) {
	// 1. 检查所有的行, 看是否有连成三个子的情况
	for (int row = 0; row < MAX_ROW; row++) {
		if (chessBoard[row][0] != ' '
			&& chessBoard[row][0] == chessBoard[row][1]
			&& chessBoard[row][0] == chessBoard[row][2]) {
			return chessBoard[row][0];
		}
	}
	// 2. 再检查所有的列
	for (int col = 0; col < MAX_COL; col++) {
		if (chessBoard[0][col] != ' '
			&& chessBoard[0][col] == chessBoard[1][col]
			&& chessBoard[0][col] == chessBoard[2][col]) {
			return chessBoard[0][col];
		}
	}
	// 3. 再检查对角线
	if (chessBoard[0][0] != ' '
		&& chessBoard[0][0] == chessBoard[1][1]
		&& chessBoard[0][0] == chessBoard[2][2]) {
		return chessBoard[0][0];
	}
	if (chessBoard[0][2] != ' '
		&& chessBoard[0][2] == chessBoard[1][1]
		&& chessBoard[0][2] == chessBoard[2][0]) {
		return chessBoard[0][2];
	}
	// 4. 判定是否和棋, 棋盘如果满了, 就算和棋
	if (IsFull(chessBoard)) {
		return 'Q';
	}
	return ' ';
}

void Game() {
	// 一局游戏的核心函数
	// 1. 创建并初始化一个棋盘(字符类型的二维数组)
	//    尽量避免使用 magic number 魔幻数字
	//    最好给这个数字起一个合适的名字
	char chessBoard[MAX_ROW][MAX_COL] = { 0 };
	Init(chessBoard);
	char winner = ' ';
	while (1) {
		// 2. 先打印棋盘
		Print(chessBoard);
		// 3. 提示玩家落子(输入坐标)
		PlayerMove(chessBoard);
		// 4. 检查游戏是否结束
		winner = Check(chessBoard);
		if (winner != ' ') {
			break;
		}
		// 5. 电脑进行落子
		ComputerMove(chessBoard);
		// 6. 检查游戏是否结束
		winner = Check(chessBoard);
		if (winner != ' ') {
			break;
		}
	}
	Print(chessBoard);
	if (winner == 'X') {
		printf("恭喜你, 你赢了!\n");
	} else if (winner == 'O') {
		printf("你真菜, 连电脑都下不过!\n");
	} else {
		printf("你真菜, 和电脑五五开!\n");
	}
}

int main() {
	while (1) {
		int choice = Menu();
		if (choice == 1) {
			Game();
		} else if (choice == 0) {
			printf("goodbye!\n");
			break;
		} else {
			printf("您是输入有误!\n");
		}
	}
	system("pause");
	return 0;
}