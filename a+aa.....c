#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void main()
{
	int i, j, a, n; 
	int sum = 0;
	int tmp = 0;

	printf("please input a number:");
	scanf("%d", &a);
	printf("please input n number:");
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		tmp = tmp * 10 + a;
		sum = sum + tmp;
	}

	printf("S=%d", sum);
	system("pause");
	return 0;
}