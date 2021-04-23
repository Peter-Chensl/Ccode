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
	//c++98������
	Singleton(Singleton const&);
	Singleton& operator = (Singleton const&);
	//c++11��ֹ����
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
		//���һ��if����ԭ���ǣ����絥�����ʵ���Ѿ����������ˣ�
		//�����ж���̵߳��ø÷�������һ���߳��õ����Ժ������߳�
		//�ͻᴦ�ڵȴ�״̬��������Ч�ʻ��󽵵ͣ�����������Ǽ���
		//һ��if����������̲߳���Ҫִ������Ĵ��룬Ҳ�Ͳ���ȴ�
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
	//��Ϊʵ����new�����ģ�����������Ҫдһ�������������ͷ���Դ
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
	/*���ǿ��ǵ����������������Ǹ��������������ڵģ�
	һ��������ֹ�����Ǿ��޷������ˣ��������ǲ����ڲ���
	�ķ������ͷ���Դ*/
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
	//��ֹ����
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
		static Singleton m_instance;//�ֲ���̬��������һ��ʹ�õ�ʱ�򴴽�
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