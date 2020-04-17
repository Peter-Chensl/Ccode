/*#include <stdio.h>
#include <math.h>
#include <windows.h>

#pragma warning(disable:4996)

int PrimeFun(int n)//判断一个数是不是素数
{
	int i = 0;
	for (i = 2; i < sqrt(n); i++)
	{
		if (0 == n%i)
			return 0;
	}
	return 1;
}

int main()
{
	int num,flag = 0;
	for (num = 100; num <= 200; num++)
	{
		flag = PrimeFun(num);
		if (1 == flag)
		{
			printf("%d ", num);
		}
		else
		{

		}
	}
	system("pause");
	return 0;
}*/
#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

/*void LeapYear() //打印1000-2000的闰年
{
int year = 1000;
while (year <= 2000)
{
if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
{
printf("%d ", year);
}
++year;
}

}
int main()
{
LeapYear();
system("pause");
return 0;
}*/
int LeapYear(int year)
{
	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
	{
		return 1;
	}
	else
		return 0;
}
int main()
{
	int falg = 0;
	int year;
	scanf("%d", &year);
	falg = LeapYear(year);
	if (1 == falg)
	{
		printf("shi");
	}
	else
	{
		printf("NO");
	}
	system("pause");
	return 0;
}