#if 0
//题目ID：45840-不要二
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int W, H, count = 0;
	cin >> W >> H;
	vector<vector<int>> a;
	a.resize(W);
	for (auto& e : a)
	{
		e.resize(H, 1);
	}
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < H; j++)
		{
			if (a[i][j] == 1)
			{
				count++;

				if ((i + 2) < W)
				{
					a[i + 2][j] = 0;
				}
				if ((j + 2) < H)
				{
					a[i][j + 2] = 0;
				}
			}
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}
#endif
#if 0
class Solution {
public:
	int StrToInt(string str) {
		if (str.empty())
		{
			return 0;
		}
		int flag = 1;
		int sum = 0;
		if (str[0] == '-')
		{
			flag = -1;
			str[0] = '0';
		}
		if (str[0] == '+')
		{
			flag = 1;
			str[0] = '0';
		}
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] < '0' || str[i] > '9')
			{
				sum = 0;
				break;
			}
			else
			{
				sum = sum * 10 + (str[i] - '0');
			}
		}
		return sum*flag;
	}
};
#endif
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	if (str.empty())
		cout << 0 << endl;
	int flag = 1;
	if (str[0] == '-')
	{
		flag = -1;
		str[0] = '0';
	}
	if (str[0] == '+')
	{
		flag = 1;
		str[0] = '0';
	}
	int sum = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			cout << 0 << endl;
		}
		else
		{
			sum = sum * 10 + str[i] - '0';
		}
	}
	cout << flag * sum << endl;
	system("pause");
	return 0;
}