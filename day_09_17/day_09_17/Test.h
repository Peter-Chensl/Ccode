#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func(int a[])
{
	printf("%d\n", sizeof(a));
}
void main()
{
	char str[] = "Welcome to Bit!";
	int Array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	char *p = str;
	int n;

	printf("len = %d\n", strlen(str));
	printf("len = %d\n", sizeof(str));
	printf("len = %d\n", sizeof(Array));
	printf("len = %d\n", sizeof(p));
	printf("%d\n", sizeof(n));
	func(Array);
}