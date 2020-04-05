#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

void PrimeNumber()
{
	int num ,i;
	for ( num = 100; num <= 200; num++)
	{
		for ( i = 2; i <= num - 1; i++)
		{
			if (num % i == 0)
			{
				break;
			}
		}
		if (i == num)
		{
			printf("%d ", num);
		}
	}
}

int main()
{
	PrimeNumber();
	system("pause");
	return 0;
}