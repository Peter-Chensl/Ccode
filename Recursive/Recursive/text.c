#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

//�ݹ�ʵ�����n��쳲�������
int febo(int n)
{
	int f1 = 1;
	if (n == 1 || n==2)
	{
		return f1;
	}
	else
	{
		return febo(n - 1) + febo(n - 2);
	}
}

int main()
{
	int n;
	printf("������n��ֵ��");
	scanf("%d", &n);
	printf("%d \n", febo(n));
	system("pause");
	return 0;
}