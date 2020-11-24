#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> first;
	vector<int> second(4, 100);
	vector<int> third(second.begin(), second.end());
	vector<int> fourth(third);

	int mynums[] = { 11, 52, 6, 8, 6, 89 };
	vector<int> fifth(mynums, mynums + sizeof(mynums) / sizeof(mynums[0]));

	for (vector<int>::iterator it = fifth.begin(); it < fifth.end(); it++)
	{
		cout << *it<<" ";
	}
	cout << endl;
	system("pause");
	return 0;
}