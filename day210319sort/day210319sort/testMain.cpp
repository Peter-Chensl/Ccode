
#include "sotr.h"

#include <iostream>
using namespace std;

int main()
{
	int arr[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
	int len = sizeof(arr) / sizeof(arr[0]);
	//bubbleSort(arr,len);
	//select_sort(arr, len);
	//insert_sort(arr, len);
	shell_sort(arr, len);
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

