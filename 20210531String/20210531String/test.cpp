#include <string>
#include <iostream>
using namespace std;

void test1()
{
	string s("hello world!");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//清空
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//扩容到10
	s.resize(10, 'a');
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//扩容15
	s.resize(15);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//扩容5
	s.resize(5);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

}
//测试reserver是否会改变string中有效元素的个数
void test2()
{
	string s;
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(20);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

}
void test3()
{
	string s;
	size_t sz = s.capacity();
	cout << "makeing s grow:\n";
	for (int i = 0; i < 100; i++)
	{
		s.push_back('1');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "容量改变:" << sz << endl;
		}
	}
}

void test4()
{
	string s;
	s.reserve(100);
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; i++)
	{
		s.push_back('w');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "容量改变:" <<  sz << endl;
		}
	}
}

void test5()
{
	string s1("hello world!");
	const string s2("hello world!");
	cout << s1 << " " << s2 << endl;
	cout << s1[0] << " " << s2[0] << endl;

	s1[0] = 'H';
	cout << s1 << endl;
}
//三种遍历方式
void test6()
{
	string s("hello word!");
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i];
	}
	cout << endl;

	for (auto e : s)
	{
		cout << e;
	}
	cout << endl;

	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << endl;
		++it;
	}
}

void test7()
{
	string s;
	s.push_back(' ');
	s.append("hello");//在s后面追加一个人字符
	s += 'b';//在s后面追加一个字符b
	s += 'it';//在s后面追加一个字符串it
	cout << s << endl;
	cout << s.c_str() << endl;

	//获取file的后缀
	string file1("string.cpp");
	size_t pos = file1.rfind('.');
	string suffix(file1.substr(pos, file1.size() - pos));
	cout << suffix << endl;

	string url("http://www.cplusplus.com/reference/string/string/find/");
	cout << url << endl;
	size_t start = url.find("://");
	if (start == string::npos)
	{
		cout << "invalkid url" << endl;
		return;
	}
	start += 3;
	size_t finish = url.find('/', start);
	string address = url.substr(start, finish + start);
	cout << address << endl;

	pos = url.find("://");
	url.erase(0, pos + 1);
	cout << url << endl;

}
int main()
{
	test7();
	system("pause");
	return 0;
}