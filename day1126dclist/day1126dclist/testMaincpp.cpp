#include "dclist.h"

int main()
{
	DCListNode* dclist;
	DCListNode *p = NULL;
	DCListInit(&dclist);
	Elemtype item;
	int select = 1;
	while (select)
	{
		printf("##########################################\n");
		printf("#   [1] push_back      [2] push_front    #\n");
		printf("#   [3] show           [4] exit          #\n");
		printf("#   [5] pop_back       [6] pop_front     #\n");
		printf("#   [7] lengh          [8] find          #\n");
		printf("#   [9] insertbyval    [10] Erasebypval  #\n");
		printf("#   [11] frontval      [12] lastval      #\n");
		printf("##########################################\n");
		printf("��ѡ��");
		scanf("%d", &select);
		switch (select)
		{
			case 1:
				printf("��������Ҫ��������ݣ���-1����\n");
				while (scanf("%d", &item), item != -1)
				{
					DCListPushback(&dclist, item);
				}
				printf("β���������ݳɹ���\n");
				break;
			case 2:
				printf("��������Ҫ��������ݣ���-1����\n");
				while (scanf("%d", &item), item != -1)
				{
					DCListPushfront(&dclist, item);
				}
				printf("ͷ���������ݳɹ���\n");
				break;
			case 3:
				DCListDisplay(dclist);
				break;
			case 4:
				select = 0;
				break;
			case 5:
				DCListpopback(&dclist);
				printf("β��ɾ���ɹ���\n");
				break;
			case 6:
				DCListpopfront(&dclist);
				printf("ͷ��ɾ���ɹ���\n");
				break;
			case 7:
				printf("����ĳ���Ϊ%d\n",DCListLength(dclist));
				break;
			case 8:
				printf("��������Ҫ���ҵ����֣�\n");
				scanf("%d", &item);
				p = DCListfind(dclist,item);
				if (p == NULL)
				{
					printf("û���ҵ�i��\n");
				}
				else
					printf("�ҵ��ˣ�\n");
				break;
			case 10:
				printf("��������Ҫɾ�������֣�\n");
				scanf("%d", &item);
				DCListErasebyval(dclist, item);
				//printf("ɾ���ɹ���\n");
				break;
			case 11:
				printf("FrontVal:%d\n", DCListFrontVal(dclist));
				break;
			case 12:
				printf("LastVal:%d\n", DCListlastVal(dclist));
				break;
			case 13:
				DCListClear(&dclist);
				break;
			default:
				break;
		}
	}
	return 0;
}