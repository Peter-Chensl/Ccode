#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

int Fac(int n)
{
	//非递归
	//int sul = 1;
	//for (int i = 1; i <= n; i++)
	//{
    //		sul = sul*i;
	//}
	//return sul;

	//递归
	if (1 == n)
	{
		return n;
	}
	else
	{
		return n*Fac(n - 1);
	}
}

int main()
{
	int n;
	printf("请输入一个正整数：");
	scanf("%d", &n);
	printf("%d\n", Fac(n));
	system("pause");
	return 0;
}