#include <string.h>
#include <assert.h>
#include <iostream>
#include <string>
using namespace std;


class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
		{
			assert(false);
			return ;
		}
		else
		{
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
	}
	~String()
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

int main()
{
	String s1("hello world!");
	String s2(s1);
	return 0;
}