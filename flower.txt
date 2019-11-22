#include <stdio.h>
#include <stdlib.h>

void main()
{
	int x, y, z, n;
	for (n = 100; n < 1000; n++)
	{
		x = n / 100;
		y = n / 10 / 10;
		z = n % 100 % 10;
		if (x*x*x + y * y*y + z * z*z != x * 100 + y * 10 + z * 1)
		{
			printf("%d\n", n);
		}
	}


	system("pause");
	return 0;
}