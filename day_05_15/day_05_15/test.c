#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

/*喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水（编程实现）。*/
int DringNum(int money)
{
	int count = money;
	int empty = money;
	int temp = 0;
	while (empty > 1 )
	{
		count += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	return count;
}
int main()
{
	int money;
	printf("输入你用于买饮料的金额：");
	scanf("%d", &money);
	printf("花费%d元可以喝%d瓶饮料\n",money,  DringNum(money));
	system("pause");
	return 0;
}