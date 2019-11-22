#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int IsLeap(int x) 
{
	if ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0))
		return 1;
	else
		return 0;
}


int main()
{
	int a;
	scanf("%d", &a);
	if (IsLeap(a) == 1)
		printf("是闰年\n");
	else
		printf("不是闰年\n");

	system("pause");
	return 0;
}
