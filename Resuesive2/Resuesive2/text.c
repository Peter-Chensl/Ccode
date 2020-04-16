#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)
//编写一个函数实现n^k，使用递归实现代码效果
int square(int n, int k)
{
	if (k == 1)
	{
		return n;
	}
	else
	{
		return (square(n, k - 1)*n);
	}
}

int main()
{
	int n, k;
	printf("请输入一个正整数：\n");
	scanf("%d", &n);
	printf("请输入这个数的次方：\n");
	scanf("%d", &k);
	printf("%d\n", square(n, k ));
	system("pause");
	return 0;
}