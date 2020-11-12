#include "seqList.h"

int main()
{
	SeqList list;
	SeqListInit(&list);
	ElemType item;
	int pos;
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
		if (select == 0)
		{
			break;
		}
		switch(select)
		{
		case 1:
			printf("��������Ҫ�����Ԫ�أ�(��-1����)\n");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushBack(&list, item);
			}
			break;
		case 2:
			printf("��������Ҫ�����Ԫ�أ�(��-1����)\n");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushFront(&list, item);
			}
			break;
		case 3:
			SeqListDisplay(&list);
			break;
		case 5:
			SeqListPopBack(&list);
			break;
		case 6:
			SeqListPopfront(&list);
			break;
		case 7:
			printf("SeqList Length = %d\n", SeqListLeng(&list));
			break;
		case 8:
			printf("��������Ҫ���ҵ�Ԫ�أ�");
			scanf("%d", &item);
			pos = SeqListFind(&list, item);
			if (pos != -1)
			{
				printf("�ҵ��ˣ�\n");
			}
			else
			{
				printf("û�и�Ԫ�أ�\n");
			}
			break;
		case 9:
			printf("������Ҫ�����λ��:");
			scanf("%d", &pos);
			printf("\n������Ҫ�����Ԫ��:");
			scanf("%d", &item);
			SeqListInsert(&list, pos, item);
			break;
		case 10:
			printf("������Ҫɾ��Ԫ�ص�λ��:");
			scanf("%d", &pos);
			SeqListErase(&list, pos);
			break;
		default:
			printf("����������������룡\n");
			break;
		}
		system("pause");
		system("cls");//�����Ļ
		
	}
	return 0;
}