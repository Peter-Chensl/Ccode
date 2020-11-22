#if 0
#include <iostream>
using namespace std;

int main()
{
	int num;//数字的个数
	cin >> num;
	int a[num];
	for (int i = 0; i<num; i++)
	{
		cin >> a[i];
		for (int j = 0; j<i; j++)
		{
			if (a[i] == a[j])
			{
				a[i] = 0;
			}
		}
	}

	for (int i = 0; i<num; i++)
	{
		if (a[i] != 0)
			cout << a[i] << " ";
	}
	return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;

int main()
{
	int n, m, i, j;
	cin >> n >> m;
	int a[n], b[m];
	for (i = 0; i<n; i++)
		cin >> a[i];
	for (j = 0; j<m; j++)
		cin >> b[j];
	i = 0, j = 0;
	for (int k = 0; k<m + n; k++)
	{
		if ((a[i]>b[j] && j<m) || i == n)
		{
			cout << b[j] << " ";
			j++;
		}
		else
		{
			cout << a[i] << " ";
			i++;
		}
	}
}
#endif
#if 0
#include<iostream>
using namespace std;

int main()
{
	float a[5][5];
	float sum = 0.0;
	for (int i = 0; i<5; i++)
	{
		for (int j = 0; j<5; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i<5; i++)
	{
		for (int j = 0; j<5; j++)
		{
			printf("%.1f ", a[i][j]);
			sum += a[i][j];
		}
		printf("%.1f\n", sum);
		sum = 0.0;
	}
	return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int a[n][m];
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			cin >> a[i][j];
		}
	}
	int x, y;
	cin >> x >> y;
	cout << a[x - 1][y - 1] << endl;
	return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int a[n][m];
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
			cout << a[i][j] << " ";
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
	int n, m;
	cin >> n >> m;
	int a[n][m];
	int max = 0, x = 0, y = 0;
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
			if (a[i][j]>max)
			{
				max = a[i][j];
				x = i;
				y = j;
			}
		}
	}
	cout << x + 1 << " " << y + 1 << endl;
	return 0;
}
#endif
