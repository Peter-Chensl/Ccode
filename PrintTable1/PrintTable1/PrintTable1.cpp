#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

void Print(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			printf("%2d * %2d = %2d ", i, j, i*j);
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	int n;
	printf("请输入一个正整数：");
	scanf("%d", &n);
	Print(n);
	system("pause");
	return 0;
}