#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

/*����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ�֣���*/
int DringNum(int money)
{
	int count = money;
	int empty = money;
	int temp = 0;
	while (empty > 1 )
	{
		count += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	return count;
}
int main()
{
	int money;
	printf("���������������ϵĽ�");
	scanf("%d", &money);
	printf("����%dԪ���Ժ�%dƿ����\n",money,  DringNum(money));
	system("pause");
	return 0;
}