#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int d3p1()
{
	int a, b, t;
	printf("请分别输入a和b的值:");
	scanf("%d %d", &a, &b);

	t = a;
	a = b;
	b = t;

	printf("%d %d\n", a, b);

	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int d3p2()
{
	int a, b;
	printf("请分别输入a和b的值:");
	scanf("%d %d", &a, &b);

	a = a + b;
	b = a - b;
	a = a - b;

	printf("%d %d\n", a, b);


	system("pause");
	return 0;
}


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


int d3p3()
{
	int a[10], i;
	int max = 0;
	printf("请输入10个数:");

	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
	max = a[0];

	for (i = 1; i < 10; i++)
	{
		if (max < a[i])
			max = a[i];
	}
	printf("最大数为:%d\n", max);

	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int d3p4()
{
	int a[3], i, j, k;
	printf("请输入3个数:");
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < 3; i++)
	{
		for (j = i + 1; j < 3; j++)
		{
			if (a[i] < a[j])
			{
				k = a[i];
				a[i] = a[j];
				a[j] = k;
			}
		}
	}
	printf("从大到小排列为:");

	for (i = 0; i < 3; i++)
	{
		printf("%d", a[i]);

	}

	system("pause");
	return 0;
}


