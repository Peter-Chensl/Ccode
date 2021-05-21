#pragma once

#include "commit.h"
//ֱ�Ӳ�������
void InsertSort(int *arr, int left, int right);
//�Ľ���Ĳ��������㷨
void InsertSort1(int *arr, int left, int right);
//���ڱ�λ�Ĳ��������㷨
void InsertSort2(int *arr, int left, int right);
//���ֲ�������
void BinInsertSort(int *arr, int left, int right);


//ϣ������
void ShellSort(int *arr, int n, int dlta[], int t);
void ShellInsert(int *arr, int n, int dk);
int dlta[] = { 5, 3, 2, 1 };
void shellSort(int *arr, int left, int right);

//ð������
void BubleSort(int *arr, int left, int right);
//�Ľ����ð������
void BubleSort1(int *arr, int left, int right);

//��������
void quickSort(int *arr, int left, int right);
//�����м�λ�õ��±�
//hoare�汾
int Partition(int *arr, int left, int right);
//�ڿӷ�
int Partition1(int *arr, int left, int right);
//����ָ�뷨
int Partition2(int *arr, int left, int right);

//�鲢����
void _MergeSort(int *arr)

//�����м�λ�õ��±�
//hoare�汾
int Partition(int *arr, int left, int right)
{
	int key = arr[left];
	while (left < right)
	{
		while (left < right && key > arr[left])
			left++;
		swap(key, arr[left]);
		while (left < right && key < arr[right])
			right--;
		swap(key, arr[right]);
	}
	return left;
}
//�ڿӷ�
int Partition1(int *arr, int left, int right)
{
	int key = arr[left];
	while (left < right)
	{
		while (left < right && key > arr[left])
			left++;
		arr[right] = arr[left];
		while (left < right && key < arr[right])
			right--;
		arr[left] = arr[right];
	}
	arr[left] = key;
	return left;
}
int Partition2(int *arr, int left, int right)
{
	int key = arr[left];
	int pos = left;
	for (int i = left + 1; i <= right; i++)
	{
		if (key > arr[i])
		{
			pos++;
			if (pos != i)
			{
				swap(arr[pos], arr[i]);
			}
		}
	}
	swap(arr[left], arr[pos]);
	return pos;
}
//��������
void quickSort(int *arr, int left, int right)
{
	if (left >= right - 1)
	{
		return;
	}
	int pos = Partition2(arr, left, right - 1);
	quickSort(arr, left, pos);
	quickSort(arr, pos +1 , right);
}

//ð������
void BubleSort(int *arr, int left, int right)
{
	int n = right - left;
	for (int i = left; i < n - 1; i++)
	{
		for (int j = left; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

//�Ľ����ð������
void BubleSort1(int *arr, int left, int right)
{
	int n = right - left;
	bool flag = false;//�������һ����������û�н������ݣ���û�У�ֱ��ֹͣ����
	for (int i = left; i < n - 1; i++)
	{
		for (int j = left; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				flag = true;
			}
		}
		if (!flag)
		{
			break;
		}
		else
		{
			flag = false;
		}
	}
	

}
//ֱ��ѡ������
int MinIndex(int *arr, int left, int right);//��ȡ��С�±�
void selectSort(int *arr, int left, int right);
int MinIndex(int *arr, int left, int right)
{
	int minindex = left;
	int min = arr[left];
	for (int i = left; i < right; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			minindex = i;
		}
	}
	return minindex;
}
void selectSort(int *arr, int left, int right)
{
	for (int i = left; i < right - 1; i++)
	{
		int mininIndex = MinIndex(arr, i, right);
		if (i != mininIndex)
		{
			swap(arr[i], arr[mininIndex]);
		}
	}
}

void ShellSort(int *arr, int n, int dlta[], int t)
{
	for (int i = 0; i < t; i++)
	{
		ShellInsert(arr, n, dlta[i]);
	}
}
void ShellInsert(int *arr, int n, int dk)
{
	for (int i = dk; i < n; i++)
	{
		if (arr[i] < arr[i - dk])
		{
			int temp = arr[i];
			int j;
			for (j = i - dk; j > 0; j -= dk)
			{
				arr[j + dk] = arr[j];
			}
			arr[j + dk] = temp;
		}
	}
}
void shellSort(int *arr, int left, int right)
{
	int dk = right - left;
	while (dk > 1)
	{
		dk = dk / 3 + 1;
		for (int i = left + dk; i < right; i++)
		{
			if (arr[i] < arr[i - dk])
			{
				int temp = arr[i];
				int end = i - dk;
				while (end >= left && temp < arr[end])
				{
					arr[end + dk] = arr[end];
					end -= dk;
				}
				arr[end + dk] = temp;
			}
		}
	}
}

void Print(int *arr, int left, int right);
//����Ч��
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
//�Ľ���Ĳ��������㷨
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
//���ڱ�λ�Ĳ��������㷨
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
//���ֲ�������
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
//��ӡ����õ����飬������ʼλ�ú�ĩβλ��
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