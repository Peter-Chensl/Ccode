#if 0

#include <iostream>
using namespace std;

int main()
{
	long n;
	cin >> n;
	long sum = 0;
	for (long i = 1; i <= n; ++i)
	{
		sum += i;
	}
	cout << sum << endl;
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
struct book
{
	char ISBN[21];//图书编号
	char bookTitle[21];//图书名称
	char author[21];//作者
	char publisher[21];//出版社
	int inventory;//库存量
	double price;//价格
};
//输出流的重载
ostream& operator << (ostream & out, book data)
{
	out << "图书信息如下：" << endl;
	out << "\t图书编号：" << data.ISBN << endl;
	out << "\t图书名称：" << data.bookTitle << endl;
	out << "\t作    者：" << data.author << endl;
	out << "\t出 版 社：" << data.publisher << endl;
	out << "\t库 存 量：" << data.inventory << endl;
	out << "\t价    格：" << data.price << endl;
	return out;
}
struct Node
{
	book data;
	Node* next;
};
//创建链表
Node* createList()
{
	Node* list;
	list = (Node*)malloc(sizeof(Node));
	list->next = nullptr;
	return list;
}
//打印链表
void printList(Node* list)
{
	Node* pMove = list->next;
	while (pMove != nullptr)
	{
		cout << pMove->data << endl;
		pMove = pMove->next;
	}
	cout << endl;
}
class BookData
{
public:
	explicit BookData()
	{
		createList();
	}

	//显示图书信息
	void printbookInfo()
	{
		if (list == NULL)
		{
			cout << "无图书信息" << endl;
		}
		else
		{
			printList(list);
		}

	}
protected:
	Node* list;
};
int main()
{
	BookData mybook;
	mybook.printbookInfo();
}
#endif