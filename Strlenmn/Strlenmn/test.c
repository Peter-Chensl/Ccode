#include <stdio.h>
#include <windows.h>

int Len(char *str)
{
	//�ǵݹ�
	/*int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;*/
	//�ݹ�
	if (*str != '\0')
	{
		return 1 + Len(str + 1);
	}
	else
	{
		return 0;
	}
}

int main()
{
	char str[] = "cnjd";
	printf("%d\n", Len(str));
	system("pause");
	return 0;
}