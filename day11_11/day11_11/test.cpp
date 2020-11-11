#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;


/*int FirstMeet(string  s)
{
	int countchar[256] = { 0 };
	for (int i = 0; i < s.size(); i++)
	{
		countchar[s[i]]++;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (countchar[s[i]] == 1)
			return i;
	}
	return -1;
}

int main()
{
	string str;
	while (getline(cin, str))
	{
		int j = FirstMeet(str);
		if (j != -1)
		{
			cout << str[j] << endl;
		}
		else
		{
			cout << j << endl;
		}
	}
	return 0;
}*/
/*class string

{

public:

	string(const char* str = "")
	{
		if (str == nullptr)
		{
			assert(false);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	string(const string &s)
		:_str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}

	string& operator=(const string &s)
	{
		if (this != &s)
		{
			delete[]_str;
			_str = new char[strlen(s._str + 1)];
			strcpy(_str, s._str);
		}
		return *this;
	}

	~string()
	{
		delete[]_str;
		_str = nullptr;
	}

private:

	char *_str;

};

int main()
{
	return 0;
}*/
class string

{

public:

	string(const char* str = "")
	{
		if (nullptr == str)
		{
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	string(const string &s)
		:_str(nullptr)
	{
		string strTemp(s._str);
		swap(_str, strTemp._str);
	}

	string& operator=(const string &s)
	{
		if (this != &s)
		{
			string strTemp(s._str);
			swap(_str, strTemp._str);
		}
		return *this;
	
	}

	~string()
	{
		if (_str)
		{
			delete[]_str;
			_str = nullptr;
	}
	}

private:

	char *_str;

};