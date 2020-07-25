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
		printf("请选择》：\n");
		scanf("%d", &select);
		if (select == 0)
		{
			break;
		}
		switch (select)
		{
		case 1:
			printf("请输入要插入得数据，以-1结束！\n");
			while (scanf("%d", &item),item != -1)
			{
				
				DCListPushBack(&list, item);
			}
			printf("尾部插入数据成功！\n");
			break;
		case 2:
			printf("请输入要插入得数据，以-1结束！\n");
			while (scanf("%d", &item), item != -1)
			{

				DCListPushfront(&list, item);
			}
			printf("头部部插入数据成功！\n");
			break;
		case 3:
			DCListShow(list);
			break;
		case 4:
			DCListPopBack(&list);
			printf("尾部删除成功！\n");
			break;
		case 5:
			DCListPopfront(&list);
			printf("头部删除成功！\n");
			break;
		case 6:
			printf("链表得长度为:%d\n",DCListlength(list));
			break;
		case 7:
			printf("链表的头元素为:%d\n", DCListfront(list));
			break;
		case 8:
			printf("链表的末尾元素为:%d\n", DCListback(list));
			break;
		case 9:
			DCListClear(&list);
			break;
		case 10:

			printf("请输入要查找的关键值:>");
			scanf("%d", &item);
			p = find(list, item);
			if (p == NULL)
				printf("数据查找失败.\n");
			else
				printf("数据查找成功.\n");
			break;
		case 11:

			printf("请输入要删除的关键值:>");
			scanf("%d", &item);
			DCListEraseByVal(list, item);
			break;
		case 12:

			printf("请输入要插入的关键值:>");
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
			printf("您输入的选项不正确，请重新输入！");
			break;
		}

	}
	DCListDestroy(&list);
	system("pause");
	return 0;
}