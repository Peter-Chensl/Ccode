#include "SList.h"

int main()
{
	SList list;
	SListInit(&list);
	ElemType item;
	SListNode *s;
	int select = 1;
	while (select)
	{
		printf("##########################################\n");
		printf("#   [1] push_back      [2] push_front    #\n");
		printf("#   [3] show           [4] exit          #\n");
		printf("#   [5] pop_back       [6] pop_front     #\n");
		printf("#   [7] lengh          [8] find          #\n");
		printf("#   [9] deletebyval    [10] sort         #\n");
		printf("#   [11] frontval      [12] lastval      #\n");
		printf("#   [12] clear         [14] Reverse      #\n");
		printf("##########################################\n");
		printf("��ѡ��");
		scanf("%d", &select);
		if (select == 0)
		{
			break;
		}
		switch (select)
		{
		case 1:
			printf("������Ҫ�����Ԫ�أ���-1������:\n");
			while (scanf("%d", &item), item != -1)
			{
				SListpushBack(&list, item);
			}
			break;
		case 2:
			printf("������Ҫ�����Ԫ�أ���-1������:\n");
			while (scanf("%d", &item), item != -1)
			{
				SListpushFront(&list, item);
			}
			break;
		case 3:
			SListDisplay(&list);
			break;
		case 4:
			select = 0;
			break;
		case 5:
			SListpopBack(&list);
			printf("β��ɾ�����ݳɹ���\n");
			break;
		case 6:
			SListpopFront(&list);
			printf("ͷ��ɾ�����ݳɹ���\n");
			break;
		case 7:
			printf("����ĳ���Ϊ��%d\n", SListLength(&list));
			break;
		case 8:
			printf("������Ҫ���ҵ�Ԫ�أ�");
			scanf("%d", &item);
			s = SListFind(list, item);
			if (s != NULL)
			{
				printf("�ҵ��ˣ�\n");
			}
			else
			{
				printf("������û�и�Ԫ�أ�����ʧ�ܣ�\n");
			}
			break;
		case 9:
			printf("������Ҫɾ����Ԫ�أ�");
			scanf("%d", &item);
			SListEraseByVal(&list, item);
			break;
		case 10:
			SListSort(&list);
			break;
		case 11:
			printf("��ͷԪ��Ϊ%d\n", SListFront(list));
			break;
		case 12:
			printf("��βԪ��Ϊ%d\n", SListback(list));
			break;
		case 13:
			DeleteAll(&list);
			break;
		case 14:
			SListReverse(&list);
			break;
		default:
			printf("����������������룡\n");
			break;
		}
	}
	
	system("pause");
	return 0;
}