#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void Figure(int x)
{
	for (int i = 1; i <= x; i++)
	{
		for (int j = 1; j <= 2 * i - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	for (int i = x - 1; i > 0; i--)
	{
		for (int j = 1; j <= 2 * i - 1; j++)
			printf("*");
		printf("\n");
	}
}
void main()
{
	int x;
	scanf("%d", &x);
	Figure(x);
	system("pause");

}
