#include <stdio.h>
#include <windows.h>

#define N 5
void ChangeArray(int arr1[], int arr2[])
{
	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
	}
	printf("\n");
}
void Print(int arr1[], int arr2[])
{
	printf("arr1:");
	for (int i = 0; i < N; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\narr2:");
	for (int i = 0; i < N; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");
}
int main()
{
	int arr1[] = { 1, 2, 3, 4, 5 }, arr2[] = { 6, 7, 8, 9, 10 };
	printf("交换前两数组的值：\n");
	Print(arr1, arr2);
	printf("交换后两数组的值：");
	ChangeArray(arr1, arr2);
	Print(arr1, arr2);
	system("pause");
	return 0;
}