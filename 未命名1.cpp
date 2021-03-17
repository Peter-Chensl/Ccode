#include <stdio.h>
namespace N
{
	int a = 10;
	int b = 20;
	int Add(int left ,int right)
	{
		return left + right;
	}
	
	int Sub(int left,int right)
	{
		return left - right;
	}
}
using N::Add(int left,int right);
//using namespace N;
int main()
{
	printf("%d\n",N::a);
	printf("%d\n",b);
	int result = Add(10,20);
	printf("%d\n",result);
	return 0;
}
