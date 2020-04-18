#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

void print(int n)
{
	if (n>9)
	{
		print(n / 10);
	}
	printf("%d ", n % 10);
}

int main()
{
	int n;
	printf("请输入一个正整数：");
	scanf("%d", &n);
	print(n);
	system("pause");
	return 0;

}