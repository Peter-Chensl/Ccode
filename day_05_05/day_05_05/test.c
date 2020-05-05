#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

int maxNum(int num1, int num2)
{
	/*int i = 0;
	if (num1 > num2)
	{ 
		i = num2;
	}
	else
	{
		i = num1;
	}
	for (; i > 0; i--)
	{
		if (num1 % i == 0 && num2 % i == 0)
		{
			return i;
		}
	}*/
	/*while (1)
	{
		if (num1 > num2)
		{
			num1 = num1 - num2;
		}
		else
		{
			num2 = num2 - num1;
		}
		if (0 == num1 - num2)
		{
			break;
		}
	}
	return num1;*/
	while (num1 * num2 != 0)
	{
		if (num1 > num2)
		{
			num1 = num1 % num2;
		}
		else if (num1 < num2)
		{
			num2 = num2 % num1;
		}
		else
		{
			break;
		}
		return num1 == 0 ? num2 : num1;
	}
}
int main()
{
	int num1, num2;
	printf("请输入两个整数：");
	scanf("%d%d", &num1,&num2);
	int result = maxNum(num1,num2);
	printf("%d,%d的最大公约数是：%d\n", num1, num2, result);
	system("pause");
	return 0;
}