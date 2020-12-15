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

	 //将string中的有效字符清空
	 s.clear();
	 cout << s.size() << endl;
	 cout << s.capacity() << endl;

	 //将s中的有效字符增加到10个，多出的部分用'a'填充
	 s.resize(10,'a');
	 s.size();
	 s.capacity();
	 cout << s << endl;

	 //将s中的有效字符增加到15个，多出的部分用缺省值'\0'填充
	 s.resize(15);
	 cout << s.size() << endl;
	 cout << s.capacity() << endl;
	 cout << s << endl;

	 //将s中的有效字符缩减到5个
	 s.resize(5);
	 cout << s.size() << endl;
	 cout << s.capacity() << endl;
	 cout << s << endl;
}
 void Teststring2()
 {
	 string s;
	 //测试reserve是否会改变string中有效元素的个数
	 s.reserve(100);
	 cout << s.size() << endl;
	 cout << s.capacity() << endl;

	 //测试reserve参数小于strlen的底层空间大小时，是否会将空间缩小
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
 //string的遍历操作
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