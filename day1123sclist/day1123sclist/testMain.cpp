#include "sclist.h"


int main()
{
	SCListNode* sclist;
	SClistInit(&sclist);
	Elemtype item;
	SCListNode* s = NULL;
	int select = 1;
	while (select)
	{
		printf("##########################################\n");
		printf("#   [1] push_back      [2] push_front    #\n");
		printf("#   [3] show           [4] exit          #\n");
		printf("#   [5] pop_back       [6] pop_front     #\n");
		printf("#   [7] lengh          [8] find          #\n");
		printf("#   [9] insertbypos    [10] Erasebypos   #\n");
		printf("##########################################\n");
		printf("��ѡ��");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("��������Ҫ��������֣���-1������:\n");
			while (scanf("%d", &item), item != -1)
			{
				SCListpushfront(&sclist, item);
			}
			break;
		case 2:
			printf("��������Ҫ��������֣���-1������:\n");
			while (scanf("%d", &item), item != -1)
			{
				SCListpushback(&sclist, item);
			}
			break;
		case 3:
			SClistdisplay(sclist);
			break;
		case 4:
			select = 0;
			break;
		case 5:
			SCListpopback(&sclist);
			printf("β��ɾ�����ݳɹ���\n");
			break;
		case 6:
			SCListpopfront(&sclist);
			printf("ͷ��ɾ�����ݳɹ���\n");
			break;
		case 7:
			printf("����ĳ���Ϊ��%d\n", SCListLength(sclist));
			break;
		case 8:
			printf("��������Ҫ���ҵ�Ԫ��:\n");
			scanf("%d", item);
			s = SCListFind(sclist, item);
			if (s!=NULL)
			{
				printf("�ҵ��ˣ�\n");
			}
			else
				printf("û���ҵ���\n");
			break;
		default:
			printf("����������������룡\n");
			break;
		}
	}
	return 0;
}