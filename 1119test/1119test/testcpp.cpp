/*有序的插入一个数*/
/*
#include <iostream>
using namespace std;

int main()
{
	int num;//数字的个数
	cin >> num;
	int a[55];
	for (int i = 0; i<num; i++)
	{
		cin >> a[i];
	}
	int num2;//要插入的数字
	cin >> num2;
	for (int i = num - 1; i >= -1; i--)
	{
		if (a[i] >= num2)
		{
			a[i + 1] = a[i];
		}
		else
		{
			a[i + 1] = num2;
			break;
		}
		if (i == -1)
		{
			a[i + 1] = num2;
			break;
		}
	}
	//输出结果
	for (int j = 0; j<num + 1; j++)
	{
		cout << a[j] << " ";
	}
	return 0;
}*/
//筛选法求素质
/*#include <iostream>
using namespace std;

int issushu(int num)
{
    int k=1;
    for(int i = 2;i<num;i++)
    {
        if(num%i==0)
            k = 0;
    }
    return k;
}
int main()
{
    int num;
    while(cin>>num)
    {
        int t = 0;
        for(int i = 2;i<num +1;i++)
        {
            if(issushu(i) == 1)
                cout<<i<<" ";
            else 
                t++;
            
        }
        cout<<"\n"<<t;
    }
}
*/
/*#include <iostream>
using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	int a[m][n], b[m][n];
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++)
		{
			cin >> b[i][j];
		}
	}
	int count = 0;
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++)
		{
			if (a[i][j] == b[i][j])
				count++;
		}
	}
	printf("%.2lf\n", (100.0*count) / (m*n));
	return 0;
}*/
//登录验证
/*#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string user;
    string password;
    while(cin>>user>>password)
    {
        if(user == "admin" && password == "admin")
        {
            cout<<"Login Success!"<<endl;
        }
        else{
            cout<<"Login Fail!"<<endl;
        }
    }
    return 0;
	}*/