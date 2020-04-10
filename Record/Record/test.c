#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#pragma warning (disable:4996) 

#define SIZE 128
#define TRY_COUNT 3

#define TRY_NAME "小龙" 
#define TRY_PSD "nihao"

int main()
{
	//编写代码实现模拟用户的登录场景，并且只能登录三次
	char name[SIZE];//用户名
	char password[SIZE];//密码
	int count = 0;//输入的次数
	START:
	count = TRY_COUNT;
	while (count > 0)
	{
		printf("请输入你的账号：");
		scanf("%s", name);
		printf("请输入你的密码：");
		scanf("%s", password);

		if (strcmp(name, TRY_NAME) == 0 && strcmp(password, TRY_PSD) == 0)
		{
			printf("欢迎 %s进入！\n", name);
			break;
		}
		else
		{
			count--;
			printf("登录失败，请检查你的用户名或密码是否正确！您还剩【%d】次机会!\n", count);
		}
	}
	if (count == 0)
	{
		printf("登录失败！请在60S后再试！\n");
		int _time = 60;
		while (_time > 0)
		{
			printf("还剩...%ds\r", _time);
			Sleep(1000);
			_time--;
		}
		printf("\n");
		goto START;
	}
	system("pause");
	return 0;
}