#include <stdio.h>
#include <windows.h>



void Init(int arr[],int ze,int set)//��ʼ������
{
	for (int i = 0; i < ze; i++)
	{
		arr[i] = set;
	}
}
void Print(int array[],int ze,int set)//��ӡ�����е�ֵ
{
	for (int i = 0; i < ze; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
void Reverse(int array[], int sz)//����Ԫ�ص�����
{
	for (int i = sz-1; i >= 0; i--)
	{
		printf("%d ", array[i]);
	}
}
int main()
{
	int se;
	int array[] = { 1, 2, 3, 4, 5 };
	se = sizeof(array) / sizeof(array[0]);
	printf("����������Ϊ��");
	Reverse(array, se);
	int set = 0;
	Init(array, se, set);
	printf("\n");
	Print(array, se, set);
	system("pause");
	return 0;
}