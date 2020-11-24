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
#if 0
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
#endif
#if 0
//vector增删改查
int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12 };
	vector<int> v(a, a+sizeof(a) / sizeof(a[0]));
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl; 
	v.pop_back();
	v.pop_back();
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
//find,insert,erase
int main()
{
	int a[] = { 1, 2, 3, 7, 5 };
	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));

	//查找3所在位置的iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	//在3的位置插入30
	v.insert(pos, 30);

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	pos = find(v.begin(), v.end(), 3);
	v.erase(pos);//删除pos位置的数据

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
// operator[]+index 和 C++11中vector的新式for+auto的遍历
// vector使用这两种遍历方式是比较便捷的。

int main()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));

	//通过[]读写第0个位置
	v[0] = 10;
	cout << v[0] << endl;

	//通过[i]的方式遍历vector
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	vector<int> swapv;
	swapv.swap(v);

	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	cout << "交换数据！";

	for (size_t i = 0; i < v.size(); i++)
	{
		cout << swapv[i] << " ";
	}
	cout << endl;
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5 };
	auto it = v.begin();

	//将有效元素个数增加到100个，多出来的位置用8填充，操作期间底层会扩容
	v.resize(100, 8);
	//|reserve的作用是改变扩容大小但不会改变有效元素个数，操作期间可能会引起底层容量改变
	v.reserve(100);
	//插入元素期间，可能会引起扩容，而导致原空间被释放
	v.insert(v.begin(), 0);
	v.push_back(8);
	//给vector重新赋值，可能会引起底层容量改变
	/*
	出错原因，以上操作，都有可能会导致vector扩容，也就是说vector底层原理旧空间被释放
	掉，而在打印时，it还在使用的是释放之前的的旧空间，在对it迭代器进行操作时，实际操
	作的是一块已经被释放掉的空间，而引起代码运行时崩溃。
	解决方案：在以上操作之后，如果想要继续通过迭代器操作vector中的元素，只需要给it重新赋值即可*/
	/*while (it != v.end())
	{
		cout << *it << " ";
	}
	cout << endl;*/
	return 0;
}
#endif

int main()
{
	int a[] = { 1, 2, 3, 4, 5 };
	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));

	vector<int> ::iterator pos = find(v.begin(), v.end(),3);
	pos = v.erase(pos);
	cout << *pos << endl;
	system("pause");
	return 0;
}