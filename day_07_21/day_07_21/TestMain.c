#include"slist.h"

int main()
{
	Slist list;
	SListInit(&list);
	SListNode *p = NULL;
	ElemType item;
	int pos = 0;
	bool flag;
	int select = 1;
	while (select)
	{
		printf("******************************************\n");
		printf("* [1] push_back           [2] push_front *\n");
		printf("* [3] show_list           [0] quit       *\n");
		printf("* [4] pop_back            [5] pop_front  *\n");
		printf("* [6] erase_pos           [7] erase_val  *\n");
		printf("* [8] insert_pos         [9] insert_val*\n");
		printf("* [10] find               [11] length    *\n");
		printf("* [12] sort               [13] capacity   *\n");
		printf("* [14]  reverse           [15] close      *\n");
		printf("******************************************\n");
		printf("��ѡ��>");
		scanf("%d", &select);
		if (0 == select)
		{
			break;
		}
		switch (select)
		{
		case 1:
			printf("������Ҫ���������<��-1����>:");
			while (scanf("%d", &item), item != -1)
			{
				SListPushBack(&list, item);
			}
			printf("β���������ݳɹ���\n");
			break;
		case 2:
			printf("������Ҫ���������<��-1����>:");
			while (scanf("%d", &item), item != -1)
			{
				SListPushFront(&list, item);
			}
			printf("ͷ���������ݳɹ���\n");
			break;
		case 3:
			SListShow(&list);
			break;
		case 4:
			SListPopback(&list);
			break;
		case 5:
			SListPopfront(&list);
			break;
		case 6:
			break;
		case 7:
			printf("������Ҫɾ�����ݵ�Ԫ�أ�>");
			scanf("%d", &item);
			SlistEraseByval(&list, item);
			break;
		case 8:
			break;
		case 9:
			printf("������Ҫ����Ԫ�ص�ֵ��");
			scanf("%d", &item);
			SeqListSort(&list);
			SeqListInsertVal(&list, item);
			break;
		case 10:
			printf("������Ҫ����Ԫ�ص�ֵ��");
			scanf("%d", &item);
			p = find(list, item);
			if (NULL == p){
				printf("����ʧ�ܣ�\n");
			}
			else
			{
				printf("���ҳɹ���\n");
			}
			break;
		case 11:
			printf("length = %d\n", SListlength(&list));
			break;
		case 12:
			SlistSort(&list);
			break;
		case 13:
			break;
		case 14:
			SListReverse(&list);
			break;
		default:
			printf("����������������룡\n");
			break;

		}
		system("pause");
		system("cls");

	}
	SeqListDestroy(&list);
	return 0;
}