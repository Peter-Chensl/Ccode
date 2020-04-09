#include <stdio.h>

void Print()//打印乘法口诀表
{
	int i = 0;
	for (i = 1; i <= 9; i++)
	{
		int j = 0;
		for (j = 1; j <= 9; j++)
		{
			printf("%d*%d=%2d ", i, j, i*j);
		}
		printf("\n");
	}
}

int main()
{
	Print();
	system("pause");
	return 0;
}