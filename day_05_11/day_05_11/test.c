#include <stdio.h>
#include <windows.h>
#include <math.h>

#pragma warning(disable:4996)
//写一个函数，可以逆序一个字符串的内容
/*void Reve(char* str)
{
	char* star = str;
	char* end = str + strlen(str)-1;
	while (star < end)
	{
		char temp = *star;
		*star = *end;
		*end = temp;
		star++;
		end--;
	}
}
int main()
{
	char str[] = " njf 123";
	printf("befor:%s\n",str);
	Reve(str);
	printf("after:%s\n", str);
	system("pause");
	return 0;
}*/
//求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，
//例如：2 + 22 + 222 + 2222 + 22222

/*int Sum(int num,int num1)
{
	int temp = num;
	int sum = 0;
	int s = 0;
	for (int i = 0; i < num1; i++)
	{
		sum = (sum * 10 + temp);
		s += sum;
	}
	return s;
}

int main()
{
	int num = 0;
	int num1 = 0;
	printf("请输入两个数字：");
	scanf("%d%d", &num, &num1);
	printf("sum = %d\n", Sum(num, num1));
	system("pause");
	return 0;
}*/

/*void nurNum()
{
	
	for (int i = 0; i < 100000; i++)
	{
		int temp = 0;
		int count = 1;
		//int i = 0;
		int sum = 0;
		temp = i;
		while (temp / 10)
		{
			count++;
			temp /= 10;
		}
		temp = i;
		while (temp)
		{
			sum += pow(temp % 10, count);
			temp /= 10;
		}
		if (i == sum)
		{
			printf("%d\n", i);
		}
	}
}
int main()
{
	nurNum();
	system("pause");
	return 0;
}*/
/*用C语言在屏幕上输出菱形
*/
void print(int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		
		int j = 0;
		for (j =0; j < num - 1 - i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * i +1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 0; i < num - 1; i++)
	{
		int k = 0;
		for (k = 0; k <= i; k++)
		{
			printf(" ");
		}
		for (k = 0; k < 2 * num - 2 * i - 3; k++)
		{
			printf("*");
		}
		printf("\n");

	}
}
int main()
{
	int num = 0;
	printf("请输入一个正整数：");
	scanf("%d", &num);
	print(num);
	system("pause");
	return 0;
}