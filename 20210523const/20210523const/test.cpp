#include <iostream>
using namespace std;

#if 0
class Date
{
public:
	void Display()
	{
		cout << "Display()" << endl;
		cout << "_year:" << _year << endl;
		cout << "_month" << _month << endl;
		cout << "_day" << _day << endl << endl;
	}
	void Display() const
	{
		cout << "Display() const" << endl;
		cout << "_year:" << _year << endl;
		cout << "_month" << _month << endl;
		cout << "_day" << _day << endl << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

void test()
{
	Date d;
	d.Display();
	Date d1;
	d1.Display();
}
int main()
{
	test();
	system("pause");
	return 0;
}
#endif
#if 0
//ȡ��ַ�Լ�const������
class Date
{
public:
	Date* operator&()
	{
		return this;
	}
	const Date* operator&()const
	{
		return this;
	}
private:
	int _year;
	int _month;
	int _day;
};
#endif
//��ʼ���б�
/*��ʼ���б���һ��ð�ſ�ʼ��������һ���Զ��ŷָ������ݳ�Ա�б�ÿ��"��Ա����"�����һ��������
���еĳ�ʼֵ����ʽ��*/
#if 0
class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{

	}
private:
	int _year;
	int _month;
	int _day;
};
#endif
/*ע�⣺���������³�Ա��������ڳ�ʼ���б�λ�ý��г�ʼ����
	   ���ó�Ա����
	   const��Ա����
	   �Զ������ͳ�Ա������û��Ĭ�Ϲ��캯����*/
#if 0
class A
{
public:
	A(int a)
		:_a(a)
	{

	}
private:
	int _a;
};
class B
{
	B(int a, int ref)
	:_ab(a)
	, _ref(ref)
	, _n(10)
	{

	}
private:
	A _ab;//û��Ĭ�ϵĹ��캯��
	int& _ref;
	const int _n;
};
#endif
#if 0
class Time
{
public:
	Time(int hour = 0)
		:_hour(hour)
	{
		cout << "Time()" << endl;
	}
private:
	int _hour;
};
class Date
{
public:
	Date(int day)
	{}
private:
	int _day;
	Time _t;
};
int main()
{
	Date d(1);
	system("pause");
	return 0;
}
#endif

class A
{
public:
	A(int a)
		:_a1(a)
		, _a2(_a1)
	{}
	void Print()
	{
		cout << _a1 << _a2 << endl;
	}
private:
	int _a2;
	int _a1;
};
int main()
{
	A aa(1);
	aa.Print();
	system("pause");
	return 0;
}