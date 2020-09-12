#ifndef _SORT_H_
#define _SORT_H_

#include "Commone.h"

void PrintArray(int arr[], int left, int right){
	for (int i = left; i < right; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	
}

//Ö±½Ó²åÈëÅÅÐò
void  InsertSort(int *arr, int left, int right)
{
	/*for (int i = left + 1; i < right; ++i)
	{
		int end = i;
		while (end>left && arr[end] < arr[end - 1])
		{
			Swap(&arr[end], &arr[end - 1]);
			end--;
		}
	}*/
	for (int i = left + 1; i < right; i++)
	{
		int temp = arr[i];
		int end = i;
		while (end > left && temp < arr[end - 1])
		{
			arr[end] = arr[end - 1];
			end--;
		}
		arr[end] = temp;
	}
}
/*void InsertSort(int *arr, int left, int right)
{
	for (int i = left + 1; i < right; ++i)
	{
		arr[0] = arr[i];
		int end = i;
		while (arr[end]<arr[end-1])
		{
			arr[end] = arr[end - 1];
			end--;
		}
		arr[end] = arr[0];
	}
}*/
//ÕÛ°ë²åÈëÅÅÐò
void BinInsertSort(int *arr, int left, int right)
 {
	
	for (int i = left+1; i < right; i++)
	{
		int temp = arr[i];
		int start = 0;
		int end = i - 1;
		while (start <= end)
		{
			int mid = (start + end) / 2;
			if (arr[mid] > temp)
			{
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}
		}
		for (int j = i -1; j >= end+1; --j)
		{
			arr[j + 1] = arr[j];
		}
		arr[end+1] = temp;
	}
	

}
void TestSort(int *arr, int left, int right)
{
	//InsertSort(arr, left, right);
	BinInsertSort(arr, left, right);
}

#endif