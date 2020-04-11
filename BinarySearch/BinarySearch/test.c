#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

int Binsearch(int a[],int num,int x)
{
	int left = 0;
	int right = num - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (x > a[mid])
		{
			left = mid + 1;
		}
		else if (x < a[mid])
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int num = sizeof(a) / sizeof(a[0]);
	int x;
	printf("请输入你要查找的数据:");
	scanf("%d", &x);
	int index = Binsearch(a, num, x);
	if (index == -1)
	{
		printf("没有找到你要的数字!\n");
	}
	else
		printf("找到了，该数字的下标为：%d\n", index);
	system("pause");
	return 0;
}