#include "test.h"

int main()
{
	int num = 0;
	int num1 = 0, num2 = 0, num3 = 0;
	/*printf("请输入一个三位数:\n");
	scanf("%d", &num);
	change(num);*/
	printf("请输入三角形的三边：");
	scanf("%d%d%d", &num1, &num2, &num3);
	printf("%.2f", signleArea(num1, num2, num3));
	system("pause");
	return 0;
}