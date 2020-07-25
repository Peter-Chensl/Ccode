#include"delist.h"

int main()
{
	DCList list;
	DCListInit(&list);
	DCListNode* p = NULL;

	ElemType item = 0;
	int select = 1;
	while (select)
	{
		printf("**********************************************\n");
		printf("*     [1] push_back           [2] push_front *\n");
		printf("*     [3] show                [4] pop_back   *\n");
		printf("*     [5] pop_front           [0] exit       *\n");
		printf("*     [6] length              [0] exit       *\n");
		printf("*     [7] front               [8] back       *\n");
		printf("*     [9] clear               [10] find      *\n");
		printf("*     [11] erasebyval         [12] insertval *\n");
		printf("*     [13] reverse            [14] sort      *\n");
		printf("**********************************************\n");
		printf("��ѡ�񡷣�\n");
		scanf("%d", &select);
		if (select == 0)
		{
			break;
		}
		switch (select)
		{
		case 1:
			printf("������Ҫ��������ݣ���-1������\n");
			while (scanf("%d", &item),item != -1)
			{
				
				DCListPushBack(&list, item);
			}
			printf("β���������ݳɹ���\n");
			break;
		case 2:
			printf("������Ҫ��������ݣ���-1������\n");
			while (scanf("%d", &item), item != -1)
			{

				DCListPushfront(&list, item);
			}
			printf("ͷ�����������ݳɹ���\n");
			break;
		case 3:
			DCListShow(list);
			break;
		case 4:
			DCListPopBack(&list);
			printf("β��ɾ���ɹ���\n");
			break;
		case 5:
			DCListPopfront(&list);
			printf("ͷ��ɾ���ɹ���\n");
			break;
		case 6:
			printf("����ó���Ϊ:%d\n",DCListlength(list));
			break;
		case 7:
			printf("�����ͷԪ��Ϊ:%d\n", DCListfront(list));
			break;
		case 8:
			printf("�����ĩβԪ��Ϊ:%d\n", DCListback(list));
			break;
		case 9:
			DCListClear(&list);
			break;
		case 10:

			printf("������Ҫ���ҵĹؼ�ֵ:>");
			scanf("%d", &item);
			p = find(list, item);
			if (p == NULL)
				printf("���ݲ���ʧ��.\n");
			else
				printf("���ݲ��ҳɹ�.\n");
			break;
		case 11:

			printf("������Ҫɾ���Ĺؼ�ֵ:>");
			scanf("%d", &item);
			DCListEraseByVal(list, item);
			break;
		case 12:

			printf("������Ҫ����Ĺؼ�ֵ:>");
			scanf("%d", &item);
			DCListInsertByVal(list, item);
			break;
		case 13:
			reveser(list);
			break;
		case 14:
			DCListSort(list);
			break;
		default :
			printf("�������ѡ���ȷ�����������룡");
			break;
		}

	}
	DCListDestroy(&list);
	system("pause");
	return 0;
}