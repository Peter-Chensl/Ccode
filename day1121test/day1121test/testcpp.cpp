#if 0
#include <iostream>
using namespace std;

int main()
{
	int N;
	int a[50];
	int sum = 0;
	for (int i = 0; i<N; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i<N; i++)
	{
		sum = sum + a[i];
	}
	cout << sum << endl;
}
#endif
#if 0
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[55];
	for (int i = 0; i<n; i++)
	{
		cin >> a[i];
	}
	int num;//要删除的数字
	cin >> num;
	int index;
	for (int i = 0; i<n; i++)
	{
		if (num == a[i])
		{
			continue;
		}
		else
			cout << a[i] << " ";
	}
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int j = 0;
	int a[n];
	for (int i = 0; i<n; i++)
	{
		cin >> a[i];
	}
	int count1 = 0;
	int count2 = 0;
	for (; j<n - 1; j++)
	{
		if (a[j] <= a[j + 1])
		{
			count1++;
		}
		if (a[j] >= a[j + 1])
		{
			count2++;
		}
	}
	if ((count1 == n - 1) || (count2 == n - 1))
		cout << "sorted" << endl;
	else
		cout << "unsorted" << endl;

	return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;

int main()
{
	int n;
	int max = 0, min = 100;
	cin >> n;
	int a[n];
	for (int i = 0; i<n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i<n; i++)
	{
		if (a[i]>max)
		{
			max = a[i];
		}
		if (a[i]<min)
		{
			min = a[i];
		}
	}
	cout << max - min << endl;
	return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int a[N];
	int sum = 0;
	for (int i = 0; i<N; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i<N; i++)
	{
		sum = sum + a[i];
	}
	cout << sum << endl;
}
#endif
#if 0
#include <iostream>
using namespace std;

int main()
{
	int a[10];
	for (int i = 0; i<10; i++)
	{
		cin >> a[i];
	}
	int count1 = 0;//统计正数的个数
	int count2 = 0;//统计负数的个数
	for (int i = 0; i<10; i++)
	{
		if (a[i]>0)
		{
			count1++;
		}
		else{
			count2++;
		}
	}
	cout << "positive:" << count1 << endl;
	cout << "negative:" << count2 << endl;
	return 0;
}
#endif



