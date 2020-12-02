#if 0
#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[30][30] = { 0 };
	for (int i = 0; i<n; i++)
	{
		a[i][0] = 1;
	}
	for (int i = 0; i<n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
		}
	}
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%5d", a[i][j]);
		}
		cout << endl;
	}
	return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;

int main()
{
	char a[3][3] = { 'O' };
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			cin >> a[i][j];
		}
	}
	int flag = 0;
	for (int i = 0; i<3; i++)
	{
		if (a[i][0] == 'K'&&a[i][1] == 'K'&&a[i][2] == 'K')
		{
			flag = 1;
			break;
		}
	}
	for (int i = 0; i<3; i++)
	{
		if (a[0][i] == 'K'&& a[1][i] == 'K'&&a[2][i] == 'K')
		{
			flag = 1;
			break;
		}
	}
	if (a[0][0] == 'K'&&a[1][1] == 'K'&&a[2][2] == 'K')
		flag = 1;
	if (a[0][2] == 'K'&&a[1][1] == 'K'&&a[2][0] == 'K')
		flag = 1;
	if (a[0][0] == 'B' &&a[1][1] == 'B' &&a[2][2] == 'B')
		flag = 2;
	if (a[0][2] == 'B' &&a[1][1] == 'B' && a[2][0] == 'B')
		flag = 2;
	for (int i = 0; i<3; i++)
	{
		if (a[i][0] == 'B' && a[i][1] == 'B' && a[i][2] == 'B')
		{
			flag = 2;
			break;
		}
	}
	for (int i = 0; i<3; i++)
	{
		if (a[0][i] == 'B' && a[1][i] == 'B'&&a[2][i] == 'B')
		{
			flag = 2;
			break;
		}
	}
	if (flag == 1)
		cout << "KiKi wins!" << endl;
	else if (flag == 2)
		cout << "BoBo wins!" << endl;
	else
		cout << "No winner!" << endl;
	return 0;

}
#endif
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[10];
	int i = 0;
	int ret = 0;
	while (n)
	{
		i++;
		a[i] = n % 6;
		n /= 6;
	}
	for (; i>0; i--)
	{
		cout << a[i];
	}
	return 0;
}