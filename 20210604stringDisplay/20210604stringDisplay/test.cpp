#include <assert.h>
#include <iostream>
using namespace std;

namespace myString
{
	class string
	{
	public:
		typedef char* iterator;
	public:
		string(const char* str = "")
		{
			if (nullptr == str)
				str = "";
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity];
			strcpy(_str, str);
		}
		string(size_t n, char ch)
			:_str(new char[n+1])
			, _size(n)
			, _capacity(n)
		{
			memset(_str, n, ch);
			_str[_size] = '\0';
		}
		string(const string &s)
			:_str(new char[s._capacity+1])
			, _size(s._size)
			, _capacity(s._capacity)
		{
			strcpy(_str, s._str);
		}
		template<class Iterator>
		string(Iterator first, Iterator last)
		{
			auto it = first;
			size_t = 0;
			while (it != last)
			{
				count++;
				++it;
			}
			it = first;
			_size = _capacity = count;
			_str = new char[_capacity + 1];
			for (size_t i = 0; i < _size; i++)
			{
				_str[i] = *it++;
			}
			_str[_size] = '\0';
		}
		string& operator = (const string &s)
		{
			strcpy((*this)._str, s._str);
			this->_capacity = s._capacity;
			this->_size = s._size;
			return *this;
		}
		//析构函数
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_capacity = 0;
				_size = 0;
			}
		}
		//迭代器操作
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		//容量相关
		size_t size()const
		{
			return _size;
		}
		size_t capacity()const
		{
			return _capacity;
		}
		bool empty()const
		{
			return 0 == _size;
		}
		void resize(size_t newsize, char ch = char())
		{
			size_t oldesize = size();
			if (newsize > oldesize)
			{
				if (newsize > _capacity)
				{
					reverse(newsize);
				}
				memset(_str + _size, ch, newsize - oldesize);
			}
			_size = newsize;
			_str[_size] = '\0';
		}
		void reverse(size_t newcapactiy)
		{
			size_t oldcapacity = capacity();
			if (newcapactiy > oldcapacity)
			{
				char* temp = new char[newcapactiy];
				strcpy(temp, _str);
				delete[] _str;
				_str = temp;
				_capacity = newcapactiy;
			}
		}
		//元素访问
		char& operator [](int index)
		{
			assert(index < size());
			return _str[index];
		}
		const char& operator[](int index)const
		{
			assert(index < size());
			return _str[index];
		}
		void push_back(char ch)
		{
			*this += ch;
		}
		string& operator+=(char ch)
		{
			if (size() == capacity())
				reverse(capacity() * 2);
			_str[_size++] = ch;
			_str[_size] = '\0';
		}
		string& operator+=(const char*str)
		{
			size_t len = strlen(str);
			char* temp = new char[_size + len + 1];
			strcpy(temp, _str);
			strcat(temp + _size, str);
			delete[] _str;
			_str = temp;
			_size += len;
			_capacity += _size;
			return *this;

		}
		string& operator+=(const string& s)
		{
			*this += s._str;
			return *this;
		}
		string& insert(size_t pos, char ch)
		{
			assert(pos <= _pos);
			if (_size >= _capacity)
			{
				reverse(2 * _capacity);
			}
			for (int i = _size; i > pos; i--)
			{
				_str[i] = _str[i - 1];

			}
			_str[pos] = ch;
			++_size;
		}
		void clear()
		{
			_size = 0;
			_str[0] = '\0';
		}
		//特殊操作
		const char* c_str()const
		{
			return _str;
		}
		size_t find(char ch, size_t pos)
		{
			while (pos < _size)
			{
				if (ch == _str[pos])
					return pos;
				++pos;
			}
			return npos;
		}
		size_t rfind(char ch, size_t pos = npos)
		{
			int cur = (pos == npos) ? _size - 1 : pos;
			while (pos > 0)
			{
				if (_str[cur] == ch)
					return cur;
				cur--;
			}
			return npos;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		static size_t npos;
	};
	size_t string::npos = -1;
}