#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�  ���磬����DigitSum(1729)����Ӧ�÷���1+7+2+9�����ĺ���19

int  DigitSum(int n){
	if (n < 9)
	{
		return n;
	}
	else
	{
		return DigitSum(n / 10) + n % 10;           //����ۼ�ֵ       
	}
}
int main(){
	int number;
	printf("������һ������:\n");
	scanf("%d", &number);
	printf("%d", DigitSum(number));
	printf("\n");
	system("pause");
	return 0;
}
