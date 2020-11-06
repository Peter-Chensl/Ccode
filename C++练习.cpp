/*#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int sum =0;//计算总和
    int num1,num2;//记录拆分的两个数字
    for(int i = 10000;i<100000;i++)
    {
        for(int j = 1;j<=5;j++)
        {
            num1 = i /(int)pow(10,j);
            num2 = i %(int)pow(10,j);
            sum += num1*num2; 
        }
        if(i == sum)
        {
            printf("%d ",i);
        }
        sum = 0;
    }
    return 0;
}*/
/*#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int sum =0;//计算总和
    int num3 = 10000;
    int num1,num2;//记录拆分的两个数字
    for(int i = 10000;i<100000;i++)
    {
        for(int j = 1;j<=5;j++)
        {
            num1 = i /(int)pow(10,j);
            num2 = i %(int)pow(10,j);
            sum += num1*num2;
        }
        if(sum == i)
        {
            printf("%d ",i);
        }
        sum = 0;
    }
    return 0;
}*/
/*#include <iostream>
using namespace std;

int main()
{
    int num = 0;
    int score = 0;
    int score1[] = {0};
    scanf("%d",&num);
    for(int i = 0;i<num;i++)
    {
        scanf("%d",&score);
        score1[i] = score;
    }
    int n = sizeof(score1)/(score1[0]);
    for(int j = 1;j<n;j++)
    {
    	int max = score1[0];
    	if(score1[j]>max)
    	{
    		score1[j-1] = score1[j];
    		score1[j] = max;
		}
    	
	}
    return 0;
}*/
/*#include <iostream>
using namespace std;

int main()
{
    char ch;
    while(scanf("%c",&ch) != EOF)
    {
        if (isspace(ch))
        {
            continue;
        }
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            printf("Vowel\n");
        }
        else
        {
            printf("Consonant\n");
        }
    }
    return 0;
} */
/*#include <iostream>
using namespace std;

int main()
{
    char c;//定义一个字符
    while(scanf("%c",&c)!=EOF)
    {
        if(c>='a'&&c<='z')
            c-=32;
        else if(c >= 'A' && c <= 'Z')
        {
            c+=32;
        }
        printf("%c\n",c);
    }
     return 0;
}*/
/*#include <iostream>
using namespace std;
#include <math.h>

int main()
{
    float a,b,c;
    while(cin>>a>>b>>c)
    {
        if(a == 0)
        {
            cout<<"Not quadratic equation"<<endl;
        }
        else if((b*b - 4*a*c)==0)
        {
            float result = -b/2*a;
            printf("x1=x2=%.2",result); 
        }
        else if ((b*b - 4*a*c)>0)
        {
            float result1,result2;
            result1 = -b-sqrt((b*b - 4*a*c))/2*a;
            result1 = -b+sqrt((b*b - 4*a*c))/2*a;
            printf("x1=%.2f;x2=%.2f",result1,result2);
            //cout<<"x1="<<result1<<";x2="<<result2<<endl;
        }
        else
        {
            float result1,result2;
            result1 = -b/(2.0*a);
            result2 = sqrt(-(b*b - 4*a*c))/(2.0*a);
            printf("x1=%.2f-%.2f;x2=%.2f+%.2f");
            //cout<<"x1="<<result1<<"-"<<result2<<";x2="<<result1<<"+"<<result2<<endl;
        }
    }
    return 0;
} */
/*#include<iostream>
using namespace std;

int main()
{
    float a,b;//两个操作数
    char c;
    while(cin>>a>>c>>b)
    {
        if(c == '+')
        {
            printf("%.4f+%.4f=%.4f",a,b,a+b);
        }
        else if(c == '-')
        {
            printf("%.4f-%.4f=%.4f",a,b,a-b);
        }
        else if(c == '*')
        {
            printf("%.4f*%.4f=%.4f",a,b,a*b);
        }
        else if(c == '/')
        {
            if(b == 0)
            {
                printf("Wrong!Division by zero!");
            }
            else
            {
                printf("%.4f/%.4f=%.4f",a,b,a/b);
            }
        }
    }
    return 0;
}*/
/*#include <stdio.h>


int main()
{
    int n,i,j;//输入的数字
    while(scanf("%d",&n)!=EOF)
    {
        for(i = 1;i<=n;i++)
        {
            for(j = 1;j<=i;j++)
            {
                printf("* ");
            }
            printf("\n");
        }
    }
    return 0;
}
*/
/*#include<stdio.h>
int main(){
    int i,j,n,k;
    while(scanf("%d",&n)!=EOF){
        for(i = 1;i<=n;i++){
            for(k = 0;k<n-i;k++){
                printf("  ");
            }
            for(j = 0;j<i;j++){
                printf("* ");
            }
            printf("\n");
        }
    }
    
    return 0;
    
}*/
/*#include <iostream>
using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<n-i;j++)
			{
				cout<<" ";
			}
			for(int k = 0;k<i+1;k++)
			{
				cout<<"*";
			}
			cout<<endl;
		}
	}
	return 0;
}*/
/*#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n-i;j++)
            {
                cout<<" ";
            }
            for(int k = 0;k<i+1;k++)
            {
                cout<<"* ";
            }
            cout<<endl;
        }
    }
    return 0;
} */
#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<=i;j++)
            {
                cout<<" ";
            }
            for(int k = 0;k<n-i;k++)
            {
                cout<<"* ";
            }
            cout<<endl;
        }
    }
    return 0;
} 
