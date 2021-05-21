#include <iostream>
using namespace std;

//显示声明得
/*
class Date
{
public:
	Date(int year = 2021, int month = 05, int day = 21)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date & d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	d1.Print();
	Date d2(d1);
	d2.Print();
	system("pause");

	return 0;
}
*/
/*
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	Date d2(d1);
	return 0;
}*/

/*
//不显示声明，调用系统默认生成得
class Date
{
public:
	Date(int year = 2021, int month = 05, int day = 21)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	Date d2(d1);//浅拷贝
	d1.Print();
	d2.Print();
	system("puase");
	return 0;
}
*/
//字符串类型的拷贝
#if 0
#include <string.h>

class String
{
public:
	String(const char* str = "kjnsd")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		cout << "~String" << endl;
		free(_str);
		_str = NULL;
	}
	void Print()
	{
		cout << _str << endl;
	}
private:
	char* _str;
};

int main()
{
	String s1 = ("hello");
	String s2(s1);
	s1.Print();
	s2.Print();
	system("pause");
	return 0;
}
#endif
//赋值运算符重载
//全局的==
#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//private:
	int _year;
	int _month;
	int _day;
};
bool operator==(const Date& d1, const Date& d2)
{
	return d1._year == d2._year && d1._month == d2._month && d1._day == d2._day;
}
void Test()
{
	Date d1(2021, 05, 21);
	Date d2(2021, 05, 21);
	cout << (d1==d2) << endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}
#endif
#if 0
class Date
{
public:
	Date(int year = 2021, int month = 05 , int day = 21)
	{
		_year = year;
		_month = month;
		_day = day;
	}
/*	Date(const Date &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	*/
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
	}
private:
	int _year;
	int _month;
	int _day;
};
#endif
//日期类的实现
class Date
{
public:
	//获取某月的天数
	int Getmonthdays(int year, int month)
	{
		static int monthDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = monthDays[month];
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			day += 1;
		}
		return day;
	}
	//构造函数
	Date(int year = 2021,int month = 05,int day = 21)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//拷贝构造函数
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._year;
	}
	//赋值运算符重载
	Date& operator=(const Date &d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
	}
	//析构函数
	~Date()
	{
		cout << "~Date()" << endl;
	}
	//日期+=天数
	Date& operator+=(int day)
	{
		_day += day;
		while (_day > Getmonthdays(_year, _month))
		{
			_day -= Getmonthdays(_year, _month);
			_month += 1;
			if (_month > 12)
			{
				_month -= 12;
				_year += 1;
			}
		}
		return *this;
	}
	// 日期+天数
	Date operator+(int day)
	{
		Date temp(*this);
		temp += day;
		return temp;
	}
	// 日期-天数
	Date operator-(int day)
	{
		Date temp(*this);
		temp -= day;
		return temp;
	}
	//日期-=天数
	Date& operator-=(int day)
	{
		_day -= day;
		while (_day < 0)
		{
			_day = Getmonthdays(_year, _month)+ _day;
			_month -= 1;
			if (_month < 0)
			{
				_month = 12;
				_year -= 1;
			}
		}
		return (*this);
	}
	// 前置++
	Date& operator++()
	{
		*this += 1;
		return *this;
	}
	// 后置++
	Date operator++(int)
	{
		Date temp(*this);
		*this += 1;
		return temp;
	}
	// 后置--
	Date operator--(int)
	{
		Date temp(*this);
		*this -= 1;
		return temp;
	}

	// 前置--
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}

	// >运算符重载
	bool operator>(const Date& d)
	{
		if (_year == d._year)
		{
			if (_month == d._month)
			{
				if (_day > d._day)
				{
					return true;
				}
			}
			else if (_month > d._month)
			{
				return true;
			}
		}
		else if (_year > d._year)
		{
			return true;
		}
		return false;
	}
	// ==运算符重载
	bool operator==(const Date& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}
	// >=运算符重载
	inline bool operator >= (const Date& d)
	{
		return !(*this<d);
	}

	// <运算符重载
	bool operator < (const Date& d)
	{
		if (_year == d._year)
		{
			if (_month == d._month)
			{
				if (_day < d._day)
					return true;
			}
			else if (_month < d._month)
				return true;
		}
		else if (_year < d._year)
		{
			return true;
		}
		return false;
	}
	// <=运算符重载
	bool operator <= (const Date& d)
	{
		return !(*this > d);
	}
	// !=运算符重载
	bool operator != (const Date& d)
	{
		return !(*this == d);
	}
	// 日期-日期 返回天数
	int operator-(const Date& d)
	{
		Date max(*this);
		int flag = 1;
		Date min(d);
		if ((*this)<d)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		int count = 0;
		while (max != min)
		{
			min++;
			count++;
		}
		return count;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{

}