#include "heap.h"

int main()
{
	int v = (0 - 1) / 2;
	int arr[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int n = sizeof(arr) / sizeof(arr[0]);
	MinHeap mp;
	HeapInit(&mp);
	//HeapCreate(&mp, arr, n);

	for (int i = 0; i < n; i++)
	{
		HeapInsert(&mp, arr[i]);
	}
	HeapShow(&mp);
	system("pause");
	return 0;
}
