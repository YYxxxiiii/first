#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void main()
{
	char a, b;
	printf("输入一个字母:\n");
	a = getchar();
	if (a >='a'&& a <= 'z')
	{
		b = a + ('A' - 'a');
		printf("%c", b);
	}
	else if(a >= 'A'&& a <= 'Z')
	{
		b = a + ('a' - 'A');
		printf("%c", b);
	}
	else
	{
		printf("error");
	}

	system("pause");
	return ;
}