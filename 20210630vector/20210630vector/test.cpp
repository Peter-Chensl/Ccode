#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

#if 0

void PrintVector(const vector<int> & v)
{
	vector<int>::const_iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

}
int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	//使用反向迭代器进行遍历
	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	PrintVector(v);
	system("pause");
	return 0;
}
#endif
#if 0
//vector的增删改查
int main()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	v.pop_back();
	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	it = find(v.begin(), v.end(), 3);
	v.insert(it, 30);//在it前插入30
	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	it = find(v.begin(), v.end(), 3);
	//删除it位置的数据
	v.erase(it);
	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	system("pause"); 
	return 0;
}
#endif
#if 0
int main()
{
	vector<int> v{ 1, 2, 3, 4 };
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			it = v.erase(it);
		else
			++it;
	}
	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	system("pause");
	return 0;
}
#endif
vector<vector<int>> yanghui(int numrows)
{
	vector<vector<int>> vv;
	vv.resize(numrows);
	for (size_t i = 1; i <= numrows; ++i)
	{
		vv[i - 1].resize(i, 0);

		vv[i - 1][0] = 1;
		vv[i - 1][i - 1] = 1;
	}
	for (size_t i = 0; i < vv.size(); ++i)
	{
		for (size_t j = 0; j < vv[i].size(); ++j)
		{
			if (vv[i][j] == 0)
			{
				vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
			}
		}
	}
	return vv;
}

int main()
{
	vector<vector<int>> vv = yanghui(5);
	for (int i = 0; i < vv.size(); i++)
	{
		for (int j = 0; j < vv[i].size(); ++j)
		{
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	//迭代器遍历
	vector<int>::iterator it;
	vector<vector<int>>::iterator iter;
	vector<int> temp;
	for (iter = vv.begin(); iter != vv.end(); ++iter)
	{
		temp = *iter;
		for (it = temp.begin(); it != temp.end(); ++it)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}