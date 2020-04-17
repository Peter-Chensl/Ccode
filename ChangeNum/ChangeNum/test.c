#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

void ChangeNum(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int a, b;
	printf("请输入两个整数：\n");
	scanf("%d%d", &a, &b);
	ChangeNum(&a, &b);
	printf("交换后的数字为：\n");
	printf("%d %d\n", a, b);
	system("pause");
	return 0;
}