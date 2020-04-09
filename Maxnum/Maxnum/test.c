#include <stdio.h>
#pragma warning(disable:4996)

int MaxNum(int a[])
{
	int max = 0;
	for (int i = 0; i < 10; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}

int main()
{
	int a[10];//定义一个长度为10的数组
	printf("请输入10个整数:\n");
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", a);
	}
	printf("最大的数为：%d\n", MaxNum(a));
	system("pause");
	return 0;
}