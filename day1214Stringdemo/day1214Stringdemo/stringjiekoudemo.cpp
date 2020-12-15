#include <iostream>
#include <string>
using namespace std;


 void TestString1()
{
	 string s("hello aqi!");
	 cout << s.size() << endl;
	 cout << s.length() << endl;
	 cout << s.capacity() << endl;
	 cout << s << endl;

	 //��string�е���Ч�ַ����
	 s.clear();
	 cout << s.size() << endl;
	 cout << s.capacity() << endl;

	 //��s�е���Ч�ַ����ӵ�10��������Ĳ�����'a'���
	 s.resize(10,'a');
	 s.size();
	 s.capacity();
	 cout << s << endl;

	 //��s�е���Ч�ַ����ӵ�15��������Ĳ�����ȱʡֵ'\0'���
	 s.resize(15);
	 cout << s.size() << endl;
	 cout << s.capacity() << endl;
	 cout << s << endl;

	 //��s�е���Ч�ַ�������5��
	 s.resize(5);
	 cout << s.size() << endl;
	 cout << s.capacity() << endl;
	 cout << s << endl;
}
 void Teststring2()
 {
	 string s;
	 //����reserve�Ƿ��ı�string����ЧԪ�صĸ���
	 s.reserve(100);
	 cout << s.size() << endl;
	 cout << s.capacity() << endl;

	 //����reserve����С��strlen�ĵײ�ռ��Сʱ���Ƿ�Ὣ�ռ���С
	 s.reserve(10);
	 cout << s.size() << endl;
	 cout << s.capacity() << endl;
 }
 void Testpush_back()
 {
	 string s;
	 int sz = s.capacity();
	 cout << "before capacity is:" << s.capacity() << endl;
	 cout << "change capacity" << endl;
	 for (int i = 0; i < 100; ++i)
	 {
		 s.push_back('c');
		 if (sz != s.capacity())
		 {
			 sz = s.capacity();
			 cout << "capscity change:" << sz << endl;
		 }
	 }
 }
 void TestPushBackReserve()
 {
	 string s;
	 s.reserve(100);
	 size_t sz = s.capacity();
	 cout << "make capacity grow!" << endl;
	 for (int i = 0; i < 100; ++i)
	 {
		 s.push_back('c');
		 if (sz != s.capacity())
		 {
			 sz = s.capacity();
			 cout << "capacity is chenge:" << sz << endl;
		 }
	 }
 }
 //string�ı�������
 void Teststring3()
 {
	 string s("hello aqi!");
	 const string s2("hello aqi!");
	 cout << s << " " << s2 << endl;
	 cout << s[0] << " " << s2[0] << endl;

	 s[0] = 'H';
	 cout << s << endl;
 }
 void Teststring4()
 {
	 string s("hello aqi!");
 }
 int main()
 {
	 //TestString1();
	 //Teststring2();
	 //Testpush_back();
	 TestPushBackReserve();
	 system("pause");
 }