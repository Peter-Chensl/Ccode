#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)
//��дһ������ʵ��n^k��ʹ�õݹ�ʵ�ִ���Ч��
int square(int n, int k)
{
	if (k == 1)
	{
		return n;
	}
	else
	{
		return (square(n, k - 1)*n);
	}
}

int main()
{
	int n, k;
	printf("������һ����������\n");
	scanf("%d", &n);
	printf("������������Ĵη���\n");
	scanf("%d", &k);
	printf("%d\n", square(n, k ));
	system("pause");
	return 0;
}