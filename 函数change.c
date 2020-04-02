#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Swap(int* x, int* y) //形参
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	Swap(&a, &b); //实参
	printf("a=%d b=%d\n", a, b);

	system("pause");
	return 0;
}