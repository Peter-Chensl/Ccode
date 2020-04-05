#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

void LeapYear() //´òÓ¡1000-2000µÄÈòÄê
{
	int year = 1000;
	while (year <= 2000)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			printf("%d ", year);
		}
		 ++year;
	}

}
int main()
{
	LeapYear();
	system("pause");
	return 0;
}