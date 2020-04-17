#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

/*void LeapYear() //´òÓ¡1000-2000µÄÈòÄê
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
}*/
int LeapYear(int year)
{
	if((year%400==0)||(year%4==0&&year%100!=0))
	{
		return 1;
	}
	else 
	return 0;
 } 
 int main()
{
	int falg = 0;
	int year;
	scang("%d",&year);
	falg=LeapYear(year);
	if(1 == falg)
	{
		printf("shi"); 
	}
	else
	{
		printf("NO");
	}
	system("pause");
	return 0;
}
