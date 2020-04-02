#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Primenum(int x)
{
	for (int i = 2; i < x - 1; i++)
	{
		if (x % i == 0)
			return 0;
	}
	return 1;
}

void main()
{
	int a = 0;
	scanf("%d", &a);

	if (Primenum(a) == 1)
	{
		printf("是素数\n");
	}
	else
	{
		printf("不是素数\n");
	}

	system("pause");
	return 0;
}
