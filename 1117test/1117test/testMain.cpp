//��ӡ��б��
/*#include <iostream>
using namespace std;

int main()
{
	int num;//���������
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
//��ӡ��б��
/*
#include <iostream>
using namespace std;

int main()
{
	int num;//���������
	while (cin >> num)//ʵ�ֶ�������
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
//��ӡX
/*
#include <iostream>
using namespace std;

int main()
{
	int num;//���������
	while (cin >> num)//ʵ�ֶ�������
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
/*����������*/
/*
#include <iostream>
using namespace std;

int main()
{
	int num;//���������
	while (cin >> num)//ʵ�ֶ�������
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
/*ƽ�����*/
/*
#include <iostream>
using namespace std;
int main()
{
float height[5];//Ҫ��������
float sum = 0.0;//������ߺ�
for(int i = 0;i<5;i++)//ʵ��ѭ������5�����
{
scanf("%f",&height[i]);
sum += height[i];
}
printf("%.2f\n",sum / 5.0);
return 0;
}
*/
/*HTTP״̬��*/
/*#include <iostream>
using namespace std;

int main()
{
    int num;//���������
    while(cin>>num)//ʵ�ֶ�������
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
/*����������*/
/*
#include <iostream>
using namespace std;

int main()
{
	int num;//Ҫ���������
	while (cin >> num)//ʵ�ֶ�������
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
	float score[7];//7���ɼ�
	float avg = 0.0;//
	float max = 0, min = 100;//���ɼ�����С�ɼ�
	float sum = 0.0;//�洢�ܳɼ�
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