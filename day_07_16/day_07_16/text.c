#include<stdio.h>
#include <assert.h>
#include <stdlib.h>
#include<Windows.h>

#pragma warning(disable:4996)
void Reverse(char *str, int start, int end){
	while (start < end){
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++, end--;
	}
}
void LeftRotate(char *str, int len, int num){
	assert(str);
	assert(len > 0);
	assert(num >= 0);

	num %= len;//去重
	//方法三

	//方法二
	/*Reverse(str, 0, num - 1);
	Reverse(str, num, len - 1);
	Reverse(str, 0, len - 1);*/
	//方法一
	/*while (num){
		char temp = str[0];
		int i = 0;
		for (i; i < len - 1; i++){
			str[i] = str[i + 1];
		}
		str[i] = temp;
		num--;
	}*/
}
int main()
{
	char str1[] = "1234abcd";
	char str2[] = "abcd1234";
	int len = strlen(str1);
	int num = 3;

	char *men = (char*)malloc(2 * len + 1);
	if (men == NULL){
		return -1;
	}
	strcpy(men, str1);
	strcat(men, str1);
	if (strstr(men, str2) != NULL){
		printf("YES!\n");
	}
	else
	{
		printf("NO!\n");
	}
	free(men);
	/*printf("before:%s\n",str1);
	for (int i = 0; i < len; i++)
	{
		if (strcmp(str1, str2) == 0){
			printf("YES!\n");
			break;
		}
		LeftRotate(str1, len, 1);
		if (i == len){
			printf("no!\n");
		}
	}*/
	system("pause");
	return 0;
}
