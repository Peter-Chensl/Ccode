#if 0
#include <iostream>
using namespace std;

class  Date
{
public:
	//�޲ι��캯��
	Date()
	{}
	//�������Ĺ��캯��
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout << _year << "��" << _month << "��" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
void TestDate()
{
	Date d1;
	d1.Print();
	Date d2(2021, 05, 04);
	d2.Print();
}
int main()
{
	TestDate();
	system("pause");
	return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;

class Date
{
public:
	//�����幹�캯��
	void Print()
	{
		cout << _year << "��" << _month << "��" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
void Test()
{
	Date d;
	d.Print();
}
int main()
{
	Test();
	system("pause");
	return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;
class Date
{
public:
	/*Date()
	{
		_year = 2021;
		_month = 05;
		_day = 04;
	}*/
	//ֻ��ѡ��һ������������ͬʱ����
	Date(int year = 2021,int month = 05,int day = 04)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout << _year << "��" << _month << "��" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
void test()
{
	Date d1;
	d1.Print();
}
int main()
{
	test();
	system("pause");
	return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;

class Time
{
public:
	Time()
	{
		cout << "Time" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;

	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
private:
	//�������ͣ��������ͣ�
	int  _year;
	int _month;
	int _day;

	//�Զ�������
	Time _t;
};

int main()
{
	Date d;
	system("pause");
	return 0;
}
#endif
#if 0
#include <iostream>
#include <assert.h>

using namespace std;

typedef int DataType;
class SeqList
{
public:
	SeqList(int capacity = 10)
	{
		_pData = (DataType*)malloc(capacity*sizeof(DataType));
		assert(_pData);
		_size = 0;
		_capacity = capacity;
	}
	~SeqList()
	{
		if (_pData)
		{
			free(_pData); // �ͷŶ��ϵĿռ�
			_pData = NULL; //��ָ����Ϊ��
			_capacity = 0;
			_size = 0;
		}
	}
private:
	int* _pData;
	size_t _size;
	size_t _capacity;
};

int main()
{
	SeqList *s;
	s->~SeqList();
	system("pause");
	return 0;

}
#endif
#include <iostream>
#include <assert.h>
#include <string.h>
using namespace std;
class String
{
public:
	String(const char* str = "")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String()
	{
		if (_str)
		{
			free(_str);
			_str = nullptr;
		}
	}
private:
	char* _str;
};


class Person
{
private:
	String _name;
	int _age;
};

void TestPerson()
{
	Person p;
}

int main()
{
	TestPerson();

	String s("hello world");
	return 0;
}

