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

	//列表构造方式
	map<string, string>m2{{ "oring", "橙子" }, { "apple", "苹果" }, { "peach", "桃子" }};
	
	//迭代器主要是用来对容器中的元素进行遍历的——配合算法来进行使用
	//采用正向迭代器进行遍历
	//std::map<std::string, std::string>::iterator it = m2.begin();
	//正向迭代器
	auto it = m2.begin();
	while (it != m2.end())
	{
		cout << "{"<< (*it).first << "," << it->second << "}" << endl;
		++it;
	}
	cout << endl;

	//反向迭代器
	auto rit = m2.rbegin();
	while (rit != m2.rend())
	{
		cout << "{" << rit->first << "," << rit->second << "}" << endl;
	}
	cout << endl;

	//范围for
	for (auto& e : m2)
	{
		cout << "{" << e.first << "," << e.second << "}" << endl;
	}
	cout << endl;
}

void TestMap2()
{
	map<string, string> m;

	//需要想map种插入元素
	m.insert(pair<string, string>("oringe", "橘子"));
	m.insert(make_pair("apple", "苹果"));
	m.insert(make_pair("peach", "桃子"));

	cout << m.size() << endl;

	cout << m["apple"] << endl;

	//[]也可以用来进行插入
	cout << m["banana"] << endl;
	m["banana"] = "香蕉";

	cout << m["banana"] << endl;

	cout << m.erase("apple") << endl;
}
//map的应用
//假设：每天下午茶——公司的一种福利
//每个人将自己喜欢吃的三种水果写在纸上——根据大家的喜好进行采购
//得出员工最喜欢吃的三种水果是什么

//1.统计每个水果出现的次数
//2.通过优先级队列找出员工最喜欢吃的K种水果
void TestMap3()
{
	string Firuits[] = { "苹果", "香蕉", "香蕉", "西瓜", "猕猴桃", "辣条", "草莓", "香蕉", "西瓜", "猕猴桃", "辣条", "草莓", "苹果", "香蕉", "香蕉", "西瓜" };
	map<string, size_t> m;
	for (auto& e : Firuits)
	{
		m[e]++;
	}
	//通过优先级队列找到top-k
	priority_queue<pair<string, size_t>, vector<pair<string, size_t>>, Com> p;

	//如果需要K个最大的元素应该创建小堆
	//用前K个元素创建一个小堆
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
	//前K个水果就在堆种
	//从堆种获取前K种水果
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