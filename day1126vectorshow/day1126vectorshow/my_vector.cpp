#include <iostream>
#include <assert.h>
using namespace std;

namespace cl
{
	template<class T>
	class myvector
	{
	public :
		typedef T* myiterator;//vector容器的迭代器
		typedef const T* const_myiterator;

		myiterator begin()
		{
			return _start;
		}
		myiterator end()
		{
			return _finish;
		}
		const_myiterator cbegin()const{
			return _start;
		}
		const_myiterator cend()consr
		{
			return _finish;
		}
		myvector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{}
		myvectator(int n, const T&value = T())
			:_start(nullptr)
			, _finish(nullptr)
			, endOfStrage(nullptr)
		{
			reserve(n);
			while (n--)
			{
				push_back(value);
			}
		}
		template<class inputIterator> 
		myvector(InputIterator first, InputIterator)
		{
			reserve(last - first);
			while (first != last)
			{
				push_back)(*first);
				++first;
			}
		}
		myvector(const myvector<T>&v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStrorage(nullptr)
		{
			reserve(v.capacity);
			myiterator it = begin();
			const_myiterator vit = v.cbegin();
			while (vit != v.cend)
			{
				*it++ = *vit++;
			}

		}
		myvector <T>& operator = (myvector<T> v)
		{
			swap(v);
			return *this;
		}
		~myvector()
		{
			delete[] _start;
			_start = _finish = _endOfStrorage;
		}
		size_t szie()const
		{
			return _finish - _start;
		}
		size_t capacity() const
		{
			return _endOfStrorage-_start;
		}
		bool enpty() const
		{
			return _first == _finish;
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t oldSize = size();
				T* temp = new T(n);
				if (_start)
				{
					for (szie_t i = 0; i < oldsize; i++)
					{
						temp[i] = _start[i];
					}
				}
				_start = temp;
				_finish = _start + size;
				_endOfStrorage = _start + n;
			}
		}
		void resize(size_t n, const T& value = T())
		{
			if (n <= size())
			{
				_finish = _start + n;
				return;
			}
			if (n > capscity())
			{
				reserve(n);
			}
			myiterator it = _finish;
			myiterator _finish = _start + n;
			while (it != _finish)
			{
				*it = value;
				++it;
			}
		}
		T& operator[](size_t pos){ return _start[pos]; }
		const T& operator[] (size_t pos)const{ return _start[pos]; }
		void pubsh_back(const T& x){ insert(end(), x); }
		void pop_back(){ erase(--end()); }
		void swap(myvector<T>&v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endOfStrorage, v._endOfStrorage);
		}
		myiterator insert(myiterator pos, const T& x)
		{
			assert(pos <= _finish);

			if (_finish == _endOfStrorage)
			{
				size_t size = size();
				size_t newCapacity = (0 == capscity() ? 1 : capacity() * 2;
				pos = _start + size;
			}
			myiterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*(end) = x;
			++_finish;
			return pos;
		}

		myiterator erase(Iterator pos)
		{
			myiterator begin pos + 1;
			while (begin != _finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}
		}
		--_finish;
		return pos;

	private:
		myiterator _start;        //指向数据块的开始
		myiterator _finish;		  //指向有效的结尾
		myiterator _endOfStrorage;//指向存储容量的结尾

	};
}

void TestVector1()
{
	cl::myvector<int> first;
	cl::myvector<int> second(4, 100);
	cl::myvector<int> third(second.begin(), second.end());
}
