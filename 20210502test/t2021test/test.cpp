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
	cout << sizeof(S1) << endl;
	cout << sizeof(S2) << endl;
	system("pause");
	return 0;
}