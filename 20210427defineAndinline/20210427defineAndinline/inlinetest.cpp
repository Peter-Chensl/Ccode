#if 0
#include <stdio.h>
#include <Windows.h>
#define PI =3.12 //���滻����=3.12
//int a;#define P 3.14
#define pi 3;
//��double b = 2 * pi;����������ͨ�����룬
//������int a[pi];�Ͳ����ԣ���Ϊpi���滻����3��

int main()
{
	//double a = 2 * PI;
	double b = 2 * pi;
	printf("%lf", b);
	int a[pi];
	system("pause");
	return 0;
}
#endif
#if 0

#include <stdio.h>


#define N (3+3)
#define ch "�л�\
����\
�͹��ǡ���"
int main()
{
	//int a = N * N;
	printf("%s\n", ch);
	system("pause");
	return 0;
}
#endif
#if 0
#include <stdio.h>

#define MAX(a,b) (a > b ? a:b )
int main()
{
	int a = 10, b = 20;
	printf("%d\n", MAX(10,20*2));
	system("pause");
	return 0;
}
#endif
#if 0
#include <stdio.h>
#define MUL(a,b) ((a)*(b))
int main()
{
	int c;
	c = MUL(3, (5 + 1));
	printf("c=%d\n", c);
	system("pause");
	return 0;
}
#endif
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX(a,b) (a > b ? a:b)
int main()
{
	int a = 10, b = 20;
	cout << MAX(++a, b) << endl;
	system("pause");
	return 0;
}