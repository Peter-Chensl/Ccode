#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Com
{
public:
	bool operator()(const pair<string, size_t>& left, const pair<string, size_t>& right)
	{
		return left.second < right.second;
	}
};

void TestMap1()
{
	map<int, string> m1;

	//�б��췽ʽ
	map<string, string>m2{{ "oring", "����" }, { "apple", "ƻ��" }, { "peach", "����" }};
	
	//��������Ҫ�������������е�Ԫ�ؽ��б����ġ�������㷨������ʹ��
	//����������������б���
	//std::map<std::string, std::string>::iterator it = m2.begin();
	//���������
	auto it = m2.begin();
	while (it != m2.end())
	{
		cout << "{"<< (*it).first << "," << it->second << "}" << endl;
		++it;
	}
	cout << endl;

	//���������
	auto rit = m2.rbegin();
	while (rit != m2.rend())
	{
		cout << "{" << rit->first << "," << rit->second << "}" << endl;
	}
	cout << endl;

	//��Χfor
	for (auto& e : m2)
	{
		cout << "{" << e.first << "," << e.second << "}" << endl;
	}
	cout << endl;
}

void TestMap2()
{
	map<string, string> m;

	//��Ҫ��map�ֲ���Ԫ��
	m.insert(pair<string, string>("oringe", "����"));
	m.insert(make_pair("apple", "ƻ��"));
	m.insert(make_pair("peach", "����"));

	cout << m.size() << endl;

	cout << m["apple"] << endl;

	//[]Ҳ�����������в���
	cout << m["banana"] << endl;
	m["banana"] = "�㽶";

	cout << m["banana"] << endl;

	cout << m.erase("apple") << endl;
}
//map��Ӧ��
//���裺ÿ������衪����˾��һ�ָ���
//ÿ���˽��Լ�ϲ���Ե�����ˮ��д��ֽ�ϡ������ݴ�ҵ�ϲ�ý��вɹ�
//�ó�Ա����ϲ���Ե�����ˮ����ʲô

//1.ͳ��ÿ��ˮ�����ֵĴ���
//2.ͨ�����ȼ������ҳ�Ա����ϲ���Ե�K��ˮ��
void TestMap3()
{
	string Firuits[] = { "ƻ��", "�㽶", "�㽶", "����", "⨺���", "����", "��ݮ", "�㽶", "����", "⨺���", "����", "��ݮ", "ƻ��", "�㽶", "�㽶", "����" };
	map<string, size_t> m;
	for (auto& e : Firuits)
	{
		m[e]++;
	}
	//ͨ�����ȼ������ҵ�top-k
	priority_queue<pair<string, size_t>, vector<pair<string, size_t>>, Com> p;

	//�����ҪK������Ԫ��Ӧ�ô���С��
	//��ǰK��Ԫ�ش���һ��С��
	int k = 0;
	for (auto& e : m)
	{
		if (k < 3)
		{
			p.push(e);
		}
		else
		{
			if (e.second > p.top().second)
			{
				p.pop();
				p.push(e);
			}
		}
		k++;
	}
	//ǰK��ˮ�����ڶ���
	//�Ӷ��ֻ�ȡǰK��ˮ��
	vector<string> vRet;
	while (!p.empty())
	{
		vRet.push_back(p.top().first);
		p.pop();
	}
}
int main()
{
	//TestMap();
	//TestMap2();
	TestMap3();
	system("pause");
	return 0;
}