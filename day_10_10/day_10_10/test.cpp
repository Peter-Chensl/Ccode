#include <iostream>
using namespace std;
#pragma waring(disable:4996);

struct student{
	//�ṹ�����
	char _name[20];
	char _gender[3];
	int _age;

	//�ṹ�庯��
	void InitStudent(char name[], char gender[], int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void PrintStudent()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}
};
int main()
{
	student s1;
	s1.InitStudent("Peter", "��", 22);
	s1.PrintStudent();

	system("pause");
	return 0;
}