#include <iostream>
#include <vector>
using namespace std;

#if 0
int main()
{
	vector<int> first;
	vector<int> second(4, 100);
	vector<int> third(second.begin(), second.end());
	vector<int> fourth(third);

	int mynums[] = { 11, 52, 6, 8, 6, 89 };
	vector<int> fifth(mynums, mynums + sizeof(mynums) / sizeof(mynums[0]));

	for (vector<int>::iterator it = fifth.begin(); it < fifth.end(); it++)
	{
		cout << *it<<" ";
	}
	cout << endl;
	system("pause");
	return 0;
}

#endif
#if 0
//迭代器的使用
void PrintVector(const vector<int>& v)
{
	vector<int>::const_iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
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
	v.push_back(5);
	v.push_back(6);
	PrintVector(v);
	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	//使用迭代器进行修改
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		*it = 2;
		++it;
	}
	PrintVector(v);
	//使用反向迭代器进行遍历打印

	system("pause");
	return 0;
}
#endif
#if 0
//vector空间增长问题
int main()
{
	size_t sz;
	vector<int> vv;
	sz = vv.capacity();
	cout << "making vv grow:\n";
	for (int i = 0; i < 100; i++)
	{
		vv.push_back(i);
		if (sz != vv.capacity())
		{
			sz = vv.capacity();
			cout << "capacity changed:" << sz << endl;
		}
	}
	vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);
	cout << "making bar grow:\n";
	for (int i = 0; i < 100; i++)
	{
		bar.push_back(i);
		if (sz != bar.capacity())
		{
			sz = bar.capacity();
			cout << "capsctiy change:" << sz << endl;
		}
	}
	system("pause");
	return 0;
}
#endif
//resize
int main()
{
	vector<int> myvector;

	for (int i = 1; i < 10; i++)
	{
		myvector.push_back(i);
	}
	myvector.resize(5);
	myvector.resize(8, 100);
	myvector.resize(12);
	cout << "myvector contains:";
	for (int i = 0; i < myvector.size(); i++)
	{
		cout << myvector[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}