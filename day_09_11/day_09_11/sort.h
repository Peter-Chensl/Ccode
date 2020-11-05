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

//直接插入排序
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
//折半插入排序
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
//二路插入排序
void TwoWayInsertSprt(int *arr, int left, int right)
{
	int n = right - left;
	int *temp = (int *)malloc(sizeof(int)*n);
	assert(temp != NULL);

	temp[0] = arr[left];
	int first = 0, finish = 0;

	for (int i = left + 1; i < right; i++)
	{
		if (arr[i] < temp[first])
		{
			first = (first - 1 + n) % n;
			temp[first] = arr[i];
		}
		else if (arr[i]>temp[finish])
		{
			temp[++finish] = arr[i];
		}
		else
		{
			int end = finish;
			while (arr[i] < temp[end])
			{
				temp[(end + 1)%n] = temp[end];
				end = (end - 1 + n) % n;
			}
			temp[(end + 1) % n] = arr[i];
			finish++;
		}
	}
	int k = 0;
	for (int i = first; k < n; ++k)
	{
		arr[k] = temp[i];
		i = (i + 1) % n;
	}
	free(temp);
	temp = NULL;
}
//希尔排序
void ShellInsert(int *arr, int left, int right,int dk)
{
	for (int i = left + dk; i < right; i++)
	{
		if (arr[i] < arr[i - dk])
		{
			int temp = arr[i];
			int end = i - dk;
			while (end >= left&&temp < arr[end])
			{
				arr[end+dk] = arr[end];
				end-=dk;
			}
			arr[end+dk] = temp;
		}
	}
}
int data[] = { 5, 3, 2, 1 };
void ShellSort(int *arr, int left, int right)
{
	int t = sizeof(data) / sizeof(data[0]);
	for (int i = 0; i < t; ++i)
	{
		ShellInsert(arr, left, right,data[i]);
	}
}
//直接选择排序
void SelectSort(int *arr, int left, int right)
{
	for (int i = left; i < right; i++)
	{
		int min = arr[i];
		int pos = i;
		for (int j = left + 1; j < right; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				pos = j;
			}
			if (pos != i)
			{
				Swap(&arr[i], &arr[pos]);
			}
		}
	}
}
//快速排序
int _partition(int *arr, int left, int right)
{
	int key = arr[left];
	while (left < right)
	{

		while (left < right&&arr[right] >= key)
		{
			right--;
		}
		Swap(&arr[left], &arr[right]);
		while (left < right&&arr[left] < key)
		{
			left++;
		}
		Swap(&arr[left], &arr[right]);
	}
	return left;
}
//快速排序挖坑法
int _partion_1(int *arr, int left, int right)
{
	int key = arr[left];
	while (left < right)
	{
		while (left < right&&arr[right] >= key)
			right--;
		arr[left] = arr[right];
		while (left < right&&arr[left] < key)
			left++;
		arr[right] = arr[left];
	}
	return left;
}
//快速排序，快慢指针法
int _partion_2(int *arr, int left, int right)
{
	int key = arr[left];
	int pos = left;
	for (int i = left + 1; i < right; ++i)
	{
		if (arr[i] < key)
		{
			pos++;
			if (pos != i)
			{
				Swap(&arr[pos], &arr[i]);
			}
		}
	}
	Swap(&arr[left], &arr[pos]);
	return left;
}
void QuickSort(int *arr, int left, int right)
{
	if (left >= right - 1)
	{
		return;
	}
	int pos = _partion_1(arr, left, right);
	QuickSort(arr, left, pos);
	QuickSort(arr, pos+1, right);
}

void TestSort(int *arr, int left, int right)
{
	//InsertSort(arr, left, right);
	//BinInsertSort(arr, left, right);
	//TwoWayInsertSprt(arr, left, right);
	ShellSort(arr, left, right);
	//QuickSort(arr, left, right);
	//printf("%d\n", i);
}

#endif