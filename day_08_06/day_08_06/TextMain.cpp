//#include "heap.h"
#include "bst.h"
int main()
{
	int arr[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int n = sizeof(arr) / sizeof(arr[0]);

	BSTree bs;
	BSTInit(&bs);

	for (int i = 0; i < n; i++)
	{
		BstInsert(&bs, arr[i]);
	}
	printf("min = %d \n", BstMin(&bs));
	printf("max = %d \n", BstMax(&bs));
	BstSortPrint(&bs);
	system("pause");
	return 0;
}
/*int main()
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
	HeapErase(&mp);
	HeapShow(&mp);
	system("pause");
	return 0;
}*/
