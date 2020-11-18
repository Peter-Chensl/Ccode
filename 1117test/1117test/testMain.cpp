//打印反斜杠
/*#include <iostream>
using namespace std;

int main()
{
	int num;//输入的数字
	while (cin >> num)
	{
		for (int i = 0; i<num; i++)
		{
			for (int j = 0; j<=i; j++)
			{
				cout << " ";
			}
			cout << "*" << endl;
		}
	}
	return 0;
}*/
//打印正斜杠
/*
#include <iostream>
using namespace std;

int main()
{
	int num;//输入的数字
	while (cin >> num)//实现多组输入
	{
		for (int i = 0; i<num; i++)
		{
			for (int k = num; k>i; k--)
			{
				cout << " ";
			}
			cout << "*" << endl;
		}
	}
	return 0;
}*/
//打印X
/*
#include <iostream>
using namespace std;

int main()
{
	int num;//输入的数字
	while (cin >> num)//实现多组输入
	{
		for (int i = 0; i<num; i++)
		{
			for (int j = 0; j<num; j++)
			{

				if ((i == j) || j + i == num - 1)
					cout << "*";
				else
					cout << " ";
			}
			cout << endl;
		}
	}
	return 0;
}*/
/*空心正方形*/
/*
#include <iostream>
using namespace std;

int main()
{
	int num;//输入的数字
	while (cin >> num)//实现多组输入
	{
		for (int i = 0; i<num; i++)
		{
			for (int k = 0; k<num; k++)
			{
				if ((i == 0 || i == num - 1) || (k == 0) || k == num - 1)
					cout << "* ";
				else
					cout << "  ";
			}
			cout << endl;

		}
	}
	return 0;
}*/
/*平均身高*/
/*
#include <iostream>
using namespace std;
int main()
{
float height[5];//要输入的身高
float sum = 0.0;//所有身高和
for(int i = 0;i<5;i++)//实现循环输入5个身高
{
scanf("%f",&height[i]);
sum += height[i];
}
printf("%.2f\n",sum / 5.0);
return 0;
}
*/
/*HTTP状态码*/
/*#include <iostream>
using namespace std;

int main()
{
    int num;//输入的数字
    while(cin>>num)//实现多组输入
    {
      switch(num)
      {
          case 200:
              cout<<"OK"<<endl;
              break;
          case 202:
              cout<<"Accepted"<<endl;
              break;
          case 400:
              cout<<"Bad Request"<<endl;
              break;
          case 403:
              cout<<"Forbidden"<<endl;
              break;
          case 404:
              cout<<"Not Found"<<endl;
              break;
          case 500:
              cout<<"Internal Server Error"<<endl;
              break;
          case 502:
              cout<<"Bad Gateway"<<endl;
              break;
      }
    }
    return 0;
	}*/
/*数字三角形*/
/*
#include <iostream>
using namespace std;

int main()
{
	int num;//要输入的数字
	while (cin >> num)//实现多组输入
	{
		for (int i = 1; i <= num; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				cout << j << " ";
			}
			cout << endl;
		}
	}
	return 0;
}*/
#include <iostream>
using namespace std;

int main()
{
	float score[7];//7个成绩
	float avg = 0.0;//
	float max = 0, min = 100;//最大成绩，最小成绩
	float sum = 0.0;//存储总成绩
	for (int i = 0; i<7; i++)
	{
		scanf("%f",&score[i]);
		sum += score[i];
	}
	for (int i = 0; i<7; i++)
	{
		if (score[i]>max)
			max = score[i];
		if (score[i]<min)
			min = score[i];
	}
	avg = (sum - max - min) / 5.0;
	printf("%.2f\n", avg);
	return 0;
}