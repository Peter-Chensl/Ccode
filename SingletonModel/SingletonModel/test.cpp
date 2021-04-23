#if 0
#include <iostream>

using namespace std;
class Singleton
{
public:
	static Singleton* GetInstence()
	{
		return &m_instence;
	}
private:
	Singleton()
	{

	}
	//c++98防拷贝
	Singleton(Singleton const&);
	Singleton& operator = (Singleton const&);
	//c++11防止拷贝
	/*
	Singleton(Singleton const&) = delete;
	Singleton& operator = (Singleton const&) = delete;
	*/
	static Singleton m_instence;
};
Singleton Singleton::m_instence;
int main()
{
	Singleton :: GetInstence();
	return 0;
}
#endif
#if 0
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

class Singleton
{
public:
	static Singleton* GetInstrance()
	{
		//多加一个if语句的原因是：假如单例类的实例已经被创建好了，
		//现在有多个线程调用该方法，有一个线程拿到锁以后，其它线程
		//就会处于等待状态，这样的效率会大大降低，但是如果我们加上
		//一个if语句则后面的线程不需要执行里面的代码，也就不会等待
		if (nullptr == m_instrance)
		{
			//m_mutex.lock();
			if (nullptr == m_instrance)
			{
				m_instrance = new Singleton;
			}
			//m_mutex.unlock();
		}
		return m_instrance;
	}
	//因为实例是new出来的，所以我们需要写一个析构函数来释放资源
	/*
	~Singleton()
	{
		if (nullptr == m_instrance)
		{
			m_mutex.lock();
			if (m_instrance != nullptr)
			{
				delete m_instrance;
				m_instrance = nullptr;
			}
			m_mutex.unlock();
		}
	}
	*/
	/*但是考虑到单例的生命周期是跟随程序的生命周期的，
	一旦程序终止，我们就无法控制了，所以我们采用内部类
	的方法来释放资源*/
	class CGarbo
	{
	public:
		~CGarbo()
		{
			if (Singleton::m_instrance)
			{
				delete Singleton::m_instrance;
			}
		}
	};
	static CGarbo CG;
private:
	Singleton()
	{}
	//防止拷贝
	Singleton(Singleton& const);
	Singleton& operator = (const Singleton&);
	static Singleton* m_instrance;
	static mutex m_mutex;
};
Singleton* Singleton::m_instrance = nullptr;
mutex Singleton::m_mutex;
Singleton::CGarbo CG;

void func(int n)
{
	cout << Singleton::GetInstrance() << endl;
}
int main()
{
	thread t1(func, 10);
	thread t2(func, 10);
	t1.join();
	t2.join();
	cout << Singleton::GetInstrance() << endl;
	cout << Singleton::GetInstrance() << endl;
	system("pause");
	return 0;
}
#endif
#if 0
class Singleton
{
public:
	static Singleton& getInstance()
	{
		static Singleton m_instance;//局部静态变量，第一次使用的时候创建
		return m_instance;
	}
private:
	Singleton()
	{}
	Singleton(const Singleton& other);
};
#endif
template<typename T>
class Singleton
{
public:
	static T& getInstance()
	{
		static T value_;
		return value_;
	}
private:
	Singleton();
	~Singleton();
	Singleton(const Singleton&);
	Singleton& operator = (const Singleton&);
};