#include "sort.h"

int main()
{
	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
	int n = sizeof(arr) / sizeof(arr[0]);
	PrintArray(arr, 0, n);
	TestSort(arr, 0, n);
	PrintArray(arr, 0, n);
	system("pause");
	return 0;
}