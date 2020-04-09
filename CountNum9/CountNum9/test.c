#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

int CountNum9()
{
	int i;
	int count = 0;
	for (i = 0; i < 100; i ++)
	{
		if (i % 10 == 9)
		{
			count++;
		}
		if (i / 10 == 9)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	printf("100以内出现9的个数为：");
	int Num9 = CountNum9();
	printf("%d\n", Num9);
	system("pause");
	return 0;
}