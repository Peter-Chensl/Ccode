#pragma once

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//冒泡排序
void bubbleSort(int arr[],int len)
{
	int i, j;
	for ( i = 0; i < len-1; i++)
	{
		//循环len-1次
		for ( j = 0; j < len-1-i; j++)
		{
			if (arr[j] > arr[j + 1])
				//如果后面一个数子比前面一个小，交换
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
template<typename T>
void select_sort(T arr[], int len)
{
	int i, j;
	for (i = 0; i < len - 1; i++)
	{
		int min = i;
		for (j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		std::swap(arr[min], arr[i]);
	}
}
//插入排序
void insert_sort(int arr[],int len)
{
	for (int i = 1; i < len; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while ((j >= 0) && (key < arr[j]))
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}
//希尔排序
template<typename T>
void shell_sort(T arr[], int len)
{
	int h = 1;
	while (h < len / 3)
	{
		h = 3 * h + 1;
	}
	while (h>0)
	{
		for (int i = h; i < len; i++)
		{
			for (int j = i; (j >= h) && (arr[j] < arr[j - h]); j -= h)
			{
				std::swap(arr[j], arr[j - h]);
			}
		}
			h /= 3;
	}
}