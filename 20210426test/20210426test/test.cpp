#if 0
//糖果
#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int A = (a + c) / 2;
	int B1 = (b + d) / 2;
	int B2 = (c - a) / 2;
	int C = (d - c) / 2;
	if (B1 != B2)
	{
		cout << "NO" << endl;
	}
	else
	{
		cout << a << " " << b << " " << c << " " << d << endl;
	}
	system("pause");
	return 0;
}
#endif
#if 1
//进制转换
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	string table = "0123456789ABCDEF";
	int M, N;
	cin >> M >> N;
	bool flag = false;
	if (M < 0)
	{
		M = -M;
		flag = true;
	}
	while (M != 0)
	{
		s += table[M%N];
		M = M / N;
	}
	if (true == flag)
	{
		s += '-';
	}
	reverse(s.begin(), s.end());
	cout << s << endl;
	system("pause");
	return 0;
}
#endif