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
	char ISBN[21];//ͼ����
	char bookTitle[21];//ͼ������
	char author[21];//����
	char publisher[21];//������
	int inventory;//�����
	double price;//�۸�
};
//�����������
ostream& operator << (ostream & out, book data)
{
	out << "ͼ����Ϣ���£�" << endl;
	out << "\tͼ���ţ�" << data.ISBN << endl;
	out << "\tͼ�����ƣ�" << data.bookTitle << endl;
	out << "\t��    �ߣ�" << data.author << endl;
	out << "\t�� �� �磺" << data.publisher << endl;
	out << "\t�� �� ����" << data.inventory << endl;
	out << "\t��    ��" << data.price << endl;
	return out;
}
struct Node
{
	book data;
	Node* next;
};
//��������
Node* createList()
{
	Node* list;
	list = (Node*)malloc(sizeof(Node));
	list->next = nullptr;
	return list;
}
//��ӡ����
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

	//��ʾͼ����Ϣ
	void printbookInfo()
	{
		if (list == NULL)
		{
			cout << "��ͼ����Ϣ" << endl;
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