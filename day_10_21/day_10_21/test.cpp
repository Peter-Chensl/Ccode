/*#include <iostream>
using namespace std;*/
#include<stdio.h>

double Add(double left, double right);
//long Add(long left, long right);
/*int Add(int left, int right)
{
	return left + right;
}
double Add(double left, double right)
{
	return left + right;
}
long Add(long left, long right)
{
	return left + right;
}*/
/*short Add(short left, short right)
{
	return left + right;
}
int Add(short left, short right)
{
	return left + right;
}*/
int main()
{
	Add(10, 20);
	Add(12.12, 12.13);
	Add(12L, 30L);
	return 0;
}
/*class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	int Getmonthday(int year, int month)
	{
		static int monthday[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		{
			monthday[2] = 29;
		}
		else
		{
			monthday[2] = 28;
		}
		return monthday[month];
	}
	Date operator+(int day)
	{
		this->_day += day;
		while (this->_day > Getmonthday(this->_year, this->_month))
		{
			this->_day -= Getmonthday(this->_year, this->_month);
			++this->_month;
			if (this->_month == 13)
			{
				++this->_year;
				this->_month = 1;
			}
		}
		return *this;
	}
	void Display()
	{
		printf("%04d-%02d-%02d\n", _year, _month, _day);
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	int n = 1;
	int year, month, day,days;
	cin >> n;
	while (n)
	{
		while (cin >> year >> month >> day >> days)
		{
			Date d(year, month, day);
			d = (d + days);
			d.Display();
		}
		n--;
	}
	return 0;
}*/

/*int main()
{
	int n, m;
	int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (cin >> n >> m)
	{
		if (n % 400 == 0 || (n % 100 != 0 && n % 400 == 0))
		{
			month[1] = 29;
		}

			int mm = 1;
			for (int i = 0; i < 12; i++)
				if (m>month[i])
				{
				m -= month[i];
				mm++;
				}
		else
			break;
		printf("%.4d-%.2d-%.2d\n", n, mm, m);
		month[1] = 28;
	}
	return 0;
}*/