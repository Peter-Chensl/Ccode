#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

//��ٷ�
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
//	printf("����������������");
//	scanf("%d%d", &a, &b);
//	k = Div(a, b);
//	printf("%d��%d�����Լ���ǣ�%d\n",a,b,k);
//	system("pause");
//	return 0;
//}

//�����
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
//	printf("����������������");
//	scanf("%d%d", &a, &b);
//	k = Div(a, b);
//	printf("%d��%d�����Լ���ǣ�%d\n",a,b,k);
//	system("pause");
//	return 0;
//}
//շת�����
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
	printf("����������������");
	scanf("%d%d", &a, &b);
	k = Div(a, b);
	printf("%d��%d�����Լ���ǣ�%d\n",a,b,k);
	system("pause");
	return 0;
}