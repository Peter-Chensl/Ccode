#include <stdio.h>
#include <windows.h>



void Init(int arr[],int ze,int set)//初始化数组
{
	for (int i = 0; i < ze; i++)
	{
		arr[i] = set;
	}
}
void Print(int array[],int ze,int set)//打印数组中的值
{
	for (int i = 0; i < ze; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
void Reverse(int array[], int sz)//数组元素的逆序
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
	printf("逆序后的数组为：");
	Reverse(array, se);
	int set = 0;
	Init(array, se, set);
	printf("\n");
	Print(array, se, set);
	system("pause");
	return 0;
}