#include <iostream>
using namespace std;

bool sushu(int num)
{
	int i = 2;
	while (num>i)
	{
		if (num%i == 0)
		{
			return false;
		}
		++i;
	}
	return true;
}
int main()
{
	int n;//Ò»¸öÅ¼Êý
	int vul1 = 0;
	int vul2 = 0;
	cin >> n;
	/*while (cin >> n)
	{
		if (n<2)
		{
			return 1;
		}
		else{
			for (int i = 1; i <= n / 2; i++)
			{
				if (sushu(i) && sushu(n - i))
				{
					cout << i << endl;
					cout << n - i << endl;
					vul1 = i;
					vul2 = n - i;
				}
			}
			cout << vul1 << endl;
			cout << vul2 << endl;
		}
	}*/
	for (int i = 2; i < n; i++)
	{
		if (sushu(i))
		{
			cout << i << " ";
		}
	}
	system("pause");
	return 0;
}