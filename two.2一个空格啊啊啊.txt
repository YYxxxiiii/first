#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr[] = {2,3,4,5,6,8,9};
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int mid = (left + right) / 2;
	int num;
	scanf("%d", &num);
	while (left <= right)
	{
		if (num < arr[mid])
		{
			right = mid - 1;
		}
		else if(num > arr[mid])
		{
			left = mid + 1;
		}
		else
		{
			printf("ok,下标是%d",mid);
			break;
		}
	}

	system("pause");
	return 0;
}