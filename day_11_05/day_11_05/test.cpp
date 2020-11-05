# if 0
#include <iostream>
using namespace std;

//类型& 引用变量名（对象名） = 引用实体
void TestReft()
{
	/*int a = 10;
	int & ra = a;//定义引用类型

	printf("%p\n", &a);
	printf("%p\n", &ra);*/
	const int a = 10;
	//int& ra = a;
	const int& ra = a;
	//int& b = 20;
	const int& b = 10;
}
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
int& count()
{
	static int n = 0;
	n++;
	return n;
}
int& Add(int a, int b)
{
	int c = a + b;
	printf("c的地址是：%p\n", &c);
	return c;
}
int main()
{
	//TestReft();
	int &ret = Add(1, 2);
	printf("ret的地址是：%p\n", &ret);
	Add(3, 4);
	//cout << "Add(1,2) is :" << ret << endl;
	system("pause");
	return 0;
}
#endif
# if 0
#include <iostream>
using namespace std;

#include <time.h>

struct A{ int a[100000]; };
void TestFunc1(A a){}
void TestFunc2(A &a){}

void TestRefAndValue()
{
	A a;
	size_t begin1 = clock();
	for (int i = 0; i < 100000; i++)
	{
		TestFunc1(a);
	}
	size_t end1 = clock();

	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; i++)
	{
		TestFunc2(a);	
	}
	size_t end2 = clock();
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}
int main()
{
	TestRefAndValue();
	system("pause");
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

#include <time.h>

struct A{ int a[100000]; };

A a;
A TestFunc1(){ return a; }
A& TestFunc2(){ return a; }

void TestReturnByReValue()
{
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; i++)
	{
		TestFunc1();
	}
	size_t end1 = clock();

	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; i++)
	{
		TestFunc2();
	}
	size_t end2 = clock();
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}
int main()
{
	TestReturnByReValue();
	system("pause");
	return 0;
}
#endif

#include <iostream>
using namespace std;

int main()
{
	int a = 10;

	int& ra = a;
	ra = 20;

	int * pa = &a;
	*pa = 20;
	return 0;
}