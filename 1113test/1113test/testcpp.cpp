//打印菱形
/*#include <iostream>
using namespace std;

int main()
{
	int num;//输入的整数（0-20）
	while (cin >> num)
	{
		for (int i = 0; i <= num; i++)
		{
			for (int j = num; j>i; j--)
			{
				printf(" ");
			}
			for (int k = 0; k <= i; k++)
			{
				printf("* ");
			}
			printf("\n");
		}
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				printf(" ");
			}
			for (int k = num; k > i; k--)
			{
				printf("* ");
			}
			printf("\n");
		}
	}
	return 0;
}*/
//打印K形
/*
#include <iostream>
using namespace std;

int main()
{
	int num;//输入的整数
	while (cin >> num)
	{
		for (int i = 0; i <= num; i++)
		{
			for (int j = num; j >= i; j--)
			{
				cout << "* ";
			}
			cout << endl;
		}
		for (int i = 1; i <= num; i++)
		{
			for (int j = 0; j<=i; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
	}
	return 0;
}*/
//打印箭头
/*#include <iostream>
using namespace std;

int main()
{
	/*int num;//输入的整数
	while (cin >> num)
	{
		/*for (int i = 0; i <= num; i++)
		{
			for (int j = num; j >= i; j--)
			{
				cout << " ";
			}
			//cout << endl;
			for (int k = 0; k <= i; k++)
				cout << "*";
			cout << endl;
		}*/
		/*for (int j = 1; j < num; j++)
		{
			for (int i = 1; i <= 2 * (num - j + 1); i++){
				printf(" ");
			}
			for (int k = 1; k <= j; k++){
				printf("*");
			}
			printf("\n");
		}
		for (int i = 0; i <= num; i++){
			printf("*");
	}*/

/*	return 0;
}*/
#include<stdio.h>
int main(){
	int n;
	while (scanf("%d", &n) != EOF){
		for (int j = 1; j <= n; j++){
			for (int i = 1; i <= 2 * (n - j + 1); i++){
				printf(" ");
			}
			for (int k = 1; k <= j; k++){
				printf("*");
			}
			printf("\n");
		}
		for (int i = 0; i <= n; i++){
			printf("*");
		}
		printf("\n");
		for (int j = 1; j <= n; j++){
			for (int i = 1; i <= 2 * j; i++){
				printf(" ");
			}
			for (int k = 1; k <= n - j + 1; k++){
				printf("*");
			}
			printf("\n");
		}
	}

	return 0;
}