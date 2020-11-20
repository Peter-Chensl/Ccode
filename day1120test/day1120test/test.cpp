/*#include<iostream>
using namespace std;

int main()
{
	int ret;
	int count = 0;
	for (int i = 1; i <= 2019; ++i)
	{
		int j = i;
		while (j!= 0)
		{
			ret = j % 10;
			j /= 10;
			if (ret == 9)
			{
				count++;
				break;
			}
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}*/
/*
#include <iostream>
using namespace std;

int main()
{
	int N;//输入的数字
	cin >> N;
	int count1 = 0;//统计奇数
	int count2 = 0;//统计偶数
	for (int i = 1; i <= N; i++)
	{
		if (i % 2 == 0)
			count2++;
		else
			count1++;
	}
	cout << count1 << " " << count2 << endl;
	return 0;
}*/
/*
#include <iostream>
using namespace std;

int main()
{
int n;
float sum;
float max = 0,min = 100.0;
cin>>n;
float a[n];//n个成绩
for(int i = 0;i<n;i++)
{
cin>>a[i];
}
for(int i = 0;i<n;i++)
{
if(a[i]>max)
max = a[i];
if(a[i]<min)
min = a[i];
sum += a[i];
}
printf("%.2f %.2f %.2f\n",max,min,sum/n);
return 0;
}*/
/*
#include <iostream>
using namespace std;

int main()
{
int n;
cin>>n;
int a[55];
for(int i = 0;i<n;++i)
{
cin>>a[i];
}
int num;//要插入的数据
cin>>num;
for(int i = n-1;i>=-1;i--)
{
if(num<a[i])
{
a[i+1] = a[i];
}
else{
a[i+1] = num;
break;
}
if(i == -1)
{
a[i+1] = num;
break;
}
}
for(int i = 0;i<n+1;++i)
{
cout<<a[i]<<" ";
}
return 0;
}*/
/*
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
string paw;
string paw1;
cin>>paw>>paw1;
if(paw == paw1)
{
cout<<"same"<<endl;
}
else{
cout<<"different"<<endl;
}
return 0;
}*/
/*
#include <iostream>
using namespace std;

int main()
{
int n,m;
int sum = 0;
cin>>n>>m;
int a[n][m];
for(int i = 0;i<n;i++)
{
for(int j = 0;j<m;j++)
{
cin>>a[i][j];
}
}
for(int i = 0;i<n;i++)
{
for(int j = 0;j<m;j++)
{
if(a[i][j]>0)
{
sum += a[i][j];
}
}
}
cout<<sum<<endl;
return 0;
}*/