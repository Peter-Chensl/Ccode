#if 0
#include <iostream>
using namespace std;

int main()
{
	int hour = 0, mintinue = 0;
	int time;
	scanf("%d:%d", &hour, &mintinue);
	cin >> time;
	hour += time / 60;
	mintinue += time % 60;
	if (mintinue >= 60)
	{
		hour++;
		mintinue = mintinue - 60;
	}
	while (hour >= 24)
	{
		hour = hour - 24;
	}
	printf("%02d:%02d", hour, mintinue);
	return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int time = 0;
	/*if(n < 12)
	{
	time+=2;
	cout<<time<<endl;
	}*/
	while (n >= 12)
	{
		time += 4;
		n = n - 12;
	}
	cout << time + 2 << endl;
	return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;

int main()
{
	long long n, m;//两个正整数
	int temp;//中间变量
	cin >> n >> m;
	int max = n;
	int min = m;
	while (min != 0)
	{
		temp = max%min;
		max = min;
		min = temp;
	}
	printf("%ld\n", max + m*n / max);
	return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;

int f(int n)
{
	if (n == 0 || n == 1)
	{
		return 1;
	}
	else
	{
		return f(n - 1) + f(n - 2);
	}
}
int main()
{
	int n;
	int count = 0;
	cin >> n;
	count = f(n);
	cout << count << endl;

	return 0;
}
#endif