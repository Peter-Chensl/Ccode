#pragma once

#include "commit.h"
//直接插入排序
void InsertSort(int *arr, int left, int right);
//改进版的插入排序算法
void InsertSort1(int *arr, int left, int right);
//带哨兵位的插入排序算法
void InsertSort2(int *arr, int left, int right);
//二分插入排序
void BinInsertSort(int *arr, int left, int right);

void Print(int *arr, int left, int right);
//测试效率
void testEfficiency();

void InsertSort(int *arr, int left, int right)
{
	for (int i = left + 1; i < right; i++)
	{
		int end = i;
		while (end > left && arr[end] < arr[end - 1])
		{
			swap(arr[end], arr[end - 1]);
			end--;
		}
	}
}
//改进版的插入排序算法
void InsertSort1(int *arr, int left, int right)
{
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
//带哨兵位的插入排序算法
void InsertSort2(int *arr, int left, int right)
{
	for (int i = left + 1; i < right; i++)
	{
		arr[0] = arr[i];
		int end = i;
		while (arr[0] < arr[end-1])
		{
			arr[end] = arr[end - 1];
			end--;
		}
		arr[end] = arr[0];
	}
}
//二分插入排序
void BinInsertSort(int *arr, int left, int right)
{
	for (int i = left + 1; i < right; ++i)
	{
		int temp = arr[i];
		int low = 0;
		int heigh = i - 1;
		while (low <= heigh)
		{
			int m = (low + heigh) / 2;
			if (temp < arr[m])
			{
				heigh = m - 1;
			}
			else
			{
				low = m + 1;
			}
		}
		for (int j = i - 1; j >= heigh + 1; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[heigh + 1] = temp;
	}
}
//打印排序好的数组，传入起始位置和末尾位置
void Print(int *arr,int left,int right)
{
	for (int i = left; i < right; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void testEfficiency()
{
	int n = 50000;
	int *a = (int *)malloc(sizeof(int)*n);
	int *a1 = (int *)malloc(sizeof(int)*n);
	int *a2 = (int *)malloc(sizeof(int)*n);
	int *a3 = (int *)malloc(sizeof(int)*n);
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand();
		a1[i] = a[i];
		a2[i] = a[i];
		a3[i] = a[i];
	}
	time_t start = clock();
	InsertSort(a, 0, n);
	time_t end = clock();
	cout << "InsertSort:" << end - start << endl;

	start = clock();
	InsertSort1(a1, 0, n);
	end = clock();
	cout << "InsertSort1:" << end - start << endl;

	start = clock();
	InsertSort2(a2, 0, n);
	end = clock();
	cout << "InsertSort2:" << end - start << endl;

	
	start = clock();
	BinInsertSort(a3, 0, n);
	end = clock();
	cout << "BinInsertSort:" << end - start << endl;
}