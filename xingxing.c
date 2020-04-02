#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void main()
{
	int i = 1;
	int j = 1;
	int x;
	scanf("%d", &x);
	for (i = 1; i <= x; i++)
	 {
		for (j = 1; j <= 2 * i - 1; j++)  
			printf("*");
			printf("\n");
	 }
		

	 for (i = x-1; i > 0; i--)
	 {
	   for (j = 1; j <= 2 * i - 1; j++)  
		printf("*");
		printf("\n");
	 }

		system("pause");
		return 0;
}