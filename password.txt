#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void main()
{
	int i = 0;
	char password[9];
	for (i = 0; i < 3; i++)
	{
		printf("请输入密码:");
		scanf("%s", password);
		if (strcmp(password, "123456") == 0)
		{
			printf("login");
			break;
		}
		else
		{
			printf("error\n");
		}

		if (i = 3)
		{
			printf("login falied\n");
		}

	}
	system("pause");
	return 0;
}