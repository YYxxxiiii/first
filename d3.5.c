#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


int d3p51()
{
	int m, n, r;
	printf("请输入两个整数:");
	scanf("%d,%d", &m, &n);
	if (m < n)
	{
		r = m;
		m = n;
		n = r;
	}
	r = m % n;
	while (r != 0)
	{
		m = n;
		n = r;
		r = m % n;
	}
	printf("最大公约数为:%d", n);

	system("pause");
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

int d3p52()
{
	int a, b;
	int max = 1;

	scanf("%d%d", &a, &b);

	int c = a % b;

	while (c)
	{
		a = b;
		b = c;
		c = a % b;
	}

	printf("%d", b);
	system("pause");
	return 0;
}