#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

//穷举法
//int Div(int a, int b)
//{
//	int i, q;
//	q = a>b ? b : a;
//	for (i = q; i > 0 && (b%i || a%i); i--);
//	return i;
//}
//int main()
//{
//	int a, b, k;
//	printf("请输入两个整数：");
//	scanf("%d%d", &a, &b);
//	k = Div(a, b);
//	printf("%d和%d的最大公约数是：%d\n",a,b,k);
//	system("pause");
//	return 0;
//}

//相减法
//int Div(int a, int b)
//{
//	while (a - b)
//	{
//		if (a > b)
//		{
//			a = a - b;
//
//		}
//		else
//		{
//			b = b - a;
//		}
//	}
//	return a;
//}
//int main()
//{
//	int a, b, k;
//	printf("请输入两个整数：");
//	scanf("%d%d", &a, &b);
//	k = Div(a, b);
//	printf("%d和%d的最大公约数是：%d\n",a,b,k);
//	system("pause");
//	return 0;
//}
//辗转相除法
int Div(int a, int b)
{
	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int main()
{
	int a, b, k;
	printf("请输入两个整数：");
	scanf("%d%d", &a, &b);
	k = Div(a, b);
	printf("%d和%d的最大公约数是：%d\n",a,b,k);
	system("pause");
	return 0;
}