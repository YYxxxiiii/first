#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 1;
	int j = 1;
	int num = 0;
	scanf("%d", &num);
	for (i = 1; i <= num; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d * %d = %-4d", j, i, i*j);
		}
		printf("\n");
	}

	system("pause");
	return 0;

}
