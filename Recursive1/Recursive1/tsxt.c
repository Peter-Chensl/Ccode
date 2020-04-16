#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，  例如，调用DigitSum(1729)，则应该返回1+7+2+9，它的和是19

int  DigitSum(int n){
	if (n < 9)
	{
		return n;
	}
	else
	{
		return DigitSum(n / 10) + n % 10;           //完成累加值       
	}
}
int main(){
	int number;
	printf("请输入一个数字:\n");
	scanf("%d", &number);
	printf("%d", DigitSum(number));
	printf("\n");
	system("pause");
	return 0;
}
