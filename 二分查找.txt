#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void main()
{
	//二分查找(数组必须得有序)
	//在整型有序数组中查找想要的数字,找到了返回下标,找不到返回
	int arr[] = { 2,3,4,5,6,8,23 };
	int num = 0;
	scanf("%d", &num);
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	//整个长度减去单个的长度就是个数 再减去一就是下标

	//如果待查找区间不为空,那就继续
	while (left <= right)
		{
		int mid = (left + right) / 2;
		if (arr[mid] < num)
		{
			left = mid + 1;//去右边找他
		}
		else if (arr[mid] > num)
		{
			right = mid - 1;
		}
		else
		{
			printf("找到了,下标就是%d", mid);
			break;
		}

	}


	system("pause");
	return 0;
}