#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

int Binsearch(int a[],int num,int x)
{
	int left = 0;
	int right = num - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (x > a[mid])
		{
			left = mid + 1;
		}
		else if (x < a[mid])
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int num = sizeof(a) / sizeof(a[0]);
	int x;
	printf("��������Ҫ���ҵ�����:");
	scanf("%d", &x);
	int index = Binsearch(a, num, x);
	if (index == -1)
	{
		printf("û���ҵ���Ҫ������!\n");
	}
	else
		printf("�ҵ��ˣ������ֵ��±�Ϊ��%d\n", index);
	system("pause");
	return 0;
}