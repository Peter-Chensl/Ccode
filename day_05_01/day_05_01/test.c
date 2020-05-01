#include <stdio.h>
#include <windows.h>

int main(){
	int arr[] = { 1, 2, 3, 4, 5 };
	int se = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int *p = arr;
	for (; i < se; i++)
	{
		printf("%d ", *p);
		p++;
	}
	printf("\n");
	system("pause");
	return 0;
}