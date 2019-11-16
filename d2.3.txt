#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int d2p3()
{
	int year, leap;

	printf("输1000-2000之间的整数：");
	scanf("%d", &year);

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		printf("是闰年");
	else
		printf("不是闰年");
	
	system("pause");
	return 0;
}
