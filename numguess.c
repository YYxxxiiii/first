#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Menu()
{
	printf("------------------\n");
	printf("欢迎来到猜数字游戏\n");
	printf("1.开始游戏\n0.结束游戏\n");
	printf("------------------\n");
	printf("请选择:");
	int n = 0;
	scanf("%d", &n);
	return n;
}

void Game()
{
	//生成一个随机数(0-100)
	//提示用户猜数字
	//根据猜的数字来提示他是猜高了还是低了

	int toGuess = rand() % 100 + 1;

	//生成的这个数字肯定<100

	while(1)
	{
		printf("请输入猜的数字(1-100):");
		int num = 0;
		scanf("%d", &num);
		if (num < toGuess)
		{
			printf("低了\n");
		}
		else if (num > toGuess)
		{
			printf("高了\n");
		}
		else
		{
			printf("bingo\n");
			break;
		}
	}
}




int main()
{
	/*srand(time(0));*/
	while (1)
	{
		int num = Menu();
		if (num == 1)
		{
			Game();		
		}
		else 
		{				
			printf("Bye!\n");
			break;
		}		
	}

	system("pause");
	return 0;
	
}






#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int Menu()
{
	printf("==========================\n");
	printf(" welcome to guess play!!!\n");
	printf("        1.start\n");
	printf("        0.over\n");
	printf("==========================\n");
	
	printf("your choose:");
	int choose = 0;
	scanf("%d", &choose);
	return choose;
}


void Game()
{
	
	int toGuess = rand() % 100 + 1;

	while (1)
	{
		int num = 0;
		printf("guess a num(1-100):");
		scanf("%d", &num);
		if (num < toGuess)
		{
			printf("lower\n");
		}
		else if (num > toGuess)
		{
			printf("higher\n");
		}
		else
		{
			printf("bingo\n");
			break;
		}
	}


}



int main()
{
	while (1)
	{
		int num = Menu();
		if (num == 1)
		{
			Game();
		}
		else
		{
			printf("bye!!!\n");
			break;
		}
	}
	system("pause");
	return 0;
	
}