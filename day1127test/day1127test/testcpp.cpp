#if 0
//矩阵相等判定
#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int a[n][m], b[n][m];
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			cin >> b[i][j];
		}
	}
	int sum = 0;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			if (a[i][j] == b[i][j])
				sum++;
		}
	}
	if (sum == n*m)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	system("pause");
	return 0;
}
#endif
#if 0
//上三角形判定
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n][n];
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			cin >> a[i][j];
		}
	}
	int count = 0;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<i; j++)
		{
			if (a[i][j] == 0)
			{
				count++;
			}
		}
	}
	if (count == n*(n - 1) / 2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
#endif
#if 0
//矩阵逆置
#include <iostream>
using namespace std;

int main()
{
	int n, m, i = 0, j = 0;
	cin >> n >> m;
	int a[n][m], b[m][n];
	for (i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			cin >> a[i][j];
			b[j][i] = a[i][j];
		}
	}
	for (j = 0; j<m; j++)
	{
		for (i = 0; i<n; i++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
#endif