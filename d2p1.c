#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 0, j = 0;

	for (i = 100; i <= 200; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
				break;
		}
		if (j == i)
		{
			printf("%d \n", i);
		}
	}

	system("pause");
	return 0;
}





#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int n;
	int i;
	int tmp;
	//scanf("%d", &n);

	for (n = 100; n < 200; n++)
	{
		tmp = sqrt(n);
		for (i = 2; i <= tmp; i++)
		{
			if (n % i == 0)
			{
				break;
			}
		}

		if (i > tmp)
		{
			printf("%d\n", n);
		}
	}
	system("pause");
	return 0;
}