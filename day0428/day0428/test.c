#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

//���ʵ�֣�����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ�� 
/*int CountDifBit(int m, int n)
{
	int temp = m^n;
	int count = 0;
	while (temp)
	{
		temp = (temp - 1)&temp;
		count++;
	}
	return count;
}*/
//��ӡ���������Ƶ�����λ��ż��λ
/*void Print(int num)
{
	for (int i = 31; i > 0; i -= 2)
	{
		printf("%d", (num >> i) & 1);
	}
	printf("\n");
	for (int i = 32; i > 0; i -= 2)
	{
		printf("%d", (num >> i) & 1);
	}
	printf("\n");
}*/
void change(int num1, int num2)
{
	num1 = num1^num2;
	num2 = num1^num2;
	num1 = num1^num2;
}
int main()
{
	/*int num1, num2;
	printf("����������������");
	scanf("%d%d", &num1,&num2);
	int ret = CountDifBit(num1, num2);
	printf("ret = %d", ret);
	*/
	/*int num;
	printf("������һ�����֣�");
	scanf("%d", &num);
	Print(num);*/
	int num1, num2;
	printf("��������������");
	scanf("%d%d",&num1,&num2);
	printf("befor:%d %d\n", num1, num2);
	change(num1, num2);
	printf("after:%d %d\n", num1,num2);
	system("pause");
	return 0;
}