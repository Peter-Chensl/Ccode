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
//��������ʹ��
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
	//ʹ�õ����������޸�
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		*it = 2;
		++it;
	}
	PrintVector(v);
	//ʹ�÷�����������б�����ӡ

	system("pause");
	return 0;
}
#endif
#if 0
//vector�ռ���������
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
//vector��ɾ�Ĳ�
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

	//����3����λ�õ�iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	//��3��λ�ò���30
	v.insert(pos, 30);

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	pos = find(v.begin(), v.end(), 3);
	v.erase(pos);//ɾ��posλ�õ�����

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
// operator[]+index �� C++11��vector����ʽfor+auto�ı���
// vectorʹ�������ֱ�����ʽ�ǱȽϱ�ݵġ�

int main()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));

	//ͨ��[]��д��0��λ��
	v[0] = 10;
	cout << v[0] << endl;

	//ͨ��[i]�ķ�ʽ����vector
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
	cout << "�������ݣ�";

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

	//����ЧԪ�ظ������ӵ�100�����������λ����8��䣬�����ڼ�ײ������
	v.resize(100, 8);
	//|reserve�������Ǹı����ݴ�С������ı���ЧԪ�ظ����������ڼ���ܻ�����ײ������ı�
	v.reserve(100);
	//����Ԫ���ڼ䣬���ܻ��������ݣ�������ԭ�ռ䱻�ͷ�
	v.insert(v.begin(), 0);
	v.push_back(8);
	//��vector���¸�ֵ�����ܻ�����ײ������ı�
	/*
	����ԭ�����ϲ��������п��ܻᵼ��vector���ݣ�Ҳ����˵vector�ײ�ԭ��ɿռ䱻�ͷ�
	�������ڴ�ӡʱ��it����ʹ�õ����ͷ�֮ǰ�ĵľɿռ䣬�ڶ�it���������в���ʱ��ʵ�ʲ�
	������һ���Ѿ����ͷŵ��Ŀռ䣬�������������ʱ������
	��������������ϲ���֮�������Ҫ����ͨ������������vector�е�Ԫ�أ�ֻ��Ҫ��it���¸�ֵ����*/
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