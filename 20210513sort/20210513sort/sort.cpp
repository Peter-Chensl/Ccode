#include "sort.h"

int main()
{
	int arr[] = { 8, 9, 2, 7, 3, 52, 46, 82 };
	int len = sizeof(arr) / sizeof(arr[0]);
	shellSort(arr, 0, len);
	cout << "ϣ�������Ľ����";
	Print(arr, 0, len);
	
	InsertSort(arr, 0, len);
	cout << "���������Ľ����";
	Print(arr, 0, len);
	
	
	InsertSort1(arr, 0, len);
	cout << "�Ľ����������Ľ����";
	Print(arr, 0, len);
	
	BinInsertSort(arr, 0, len);
	cout << "���ֲ��������Ľ����";
	Print(arr, 0, len);

	shellSort(arr, 0, len);
	cout << "ϣ�������Ľ����";
	Print(arr, 0, len);

	int arr1[] = { 0, 8, 9, 2, 7, 3, 52, 46, 82 };
	len = sizeof(arr1) / sizeof(arr1[0]);
	InsertSort2(arr1, 1, len);
	cout << "���ڱ�λ�Ĳ��������Ľ����";
	Print(arr1, 1, len);
	testEfficiency();
	*/
	system("pause");
	return 0;
}