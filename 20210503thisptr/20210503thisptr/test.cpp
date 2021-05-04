#if 0
#include <iostream>
#include <string>

using namespace std;
class student
{
public :
	void Init(string id,string name,int age)
	{
		id_ = id;
		name_ = name;
		age_ = age;
	}
	void print()
	{
		cout << id_ << endl;
		cout << name_ << endl;
		cout << age_ << endl;
	}
public:
	string id_;
	string name_;
	int age_;
};

int main()
{
	student s1, s2;
	s1.Init("001", "张三", 18);
	s1.print();
	s1.Init("002", "李四", 18);
	s1.print();
	s2.Init("001", "王五", 18);
	s2.print();
	s2.Init("002", "丽萨", 18);
	s2.print();
	system("pause");
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

struct student
{
	char _id[20];
	char _name[20];;
	int age_;
};
//初始化
void InitStudent(student *s,char *id, char *name, int age)
{
	strcpy(s->_id, id);
	strcpy(s->_name, name);
	s->age_ = age;
}
void PrintStudent(student *s)
{
	printf("%s-%s-%d\n", s->_id, s->_name, s->age_);
}

int main()
{
	struct student s1, s2;
	InitStudent(&s1, "001", "Peter", 18);
	InitStudent(&s2, "001", "lisa", 18);
	system("pause");
	return 0;
}
#endif
#include <iostream>
#include <string>

using namespace std;
class student
{
public:
	void Init(string id, string name, int age)
	{
		this->id_ = id;
		this->name_ = name;
		this->age_ = age;
	}
	void print()
	{
		cout << this->id_ << endl;
		cout << this->name_ << endl;
		cout << this->age_ << endl;
	}
public:
	string id_;
	string name_;
	int age_;
};

int main()
{
	student s1, s2;
	s1.Init("001", "张三", 18);
	s1.print();
	s1.Init("002", "李四", 18);
	s1.print();
	s2.Init("001", "王五", 18);
	s2.print();
	s2.Init("002", "丽萨", 18);
	s2.print();
	system("pause");
	return 0;
}