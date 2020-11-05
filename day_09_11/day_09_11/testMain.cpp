#include "sort.h"

int main()
{
	int arr[] = { 5, 1, 2, 4, 3, 6, 9, 7,6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	PrintArray(arr, 0, n);
	TestSort(arr, 0, n);
	PrintArray(arr, 0, n);
	system("pause");
	return 0;
}