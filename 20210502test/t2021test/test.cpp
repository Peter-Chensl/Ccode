#if 0
#include <iostream>
using namespace std;

struct A
{
	int a;
	char b;
	char c;
};
class B
{
	int a;
	char b;
	char c;
};
struct S1
{
	char c1;
	int i;
	char c2;
};
struct S2
{
	char a1;
	struct S1 s1;
	int i;
};
int main()
{
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	//cout << sizeof(S1) << endl;
	//cout << sizeof(S2) << endl;
	system("pause");
	return 0;
}
#endif
#include <stdio.h>
#include <Windows.h>
#pragma pack(8)//设置默认对齐数为8
struct S1
{
	char c1;
	int i;
	char c2;
};
#pragma pack()//取消设置的默认对齐数，还原为默认
#pragma pack(1)//设置默认对齐数为1
struct S2
{
	char c1;
	int i;
	char c2;
};
#pragma pack()//取消设置的默认对齐数，还原为默认
int main()
{
	//输出的结果是什么？
	printf("%d\n", sizeof(struct S1));
	printf("%d\n", sizeof(struct S2));
	system("pause");
	return 0;
}