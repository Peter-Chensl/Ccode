#include "test.h"

//��������һ����λ�����������λ���ַ������
void change(int num)
{
	int gewei = num % 10;
	int shiwei = (num / 10) % 10;
	int baiwei = num / 100;
	printf("�����%d%d%d\n", gewei, shiwei, baiwei);
}
//���������εı߳����������ε������(��� = sqrt(s(s-a)(s- b)(s-c)),s = (a+b+c)/2
double signleArea(int num1, int num2,int num3)
{
	double area = 0.0;
	if ((num1 + num2) > num3 && (num1 + num3) > num3 && (num2 + num3) > num1)
	{
		double s = (num1 + num2 + num3) / 2.0;
		area = sqrt(s * (s - num1)*(s - num2) * (s - num3));
	}
	return area;
}