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
		printf("请选择：");
		scanf("%d", &select);
		if (select == 0)
		{
			break;
		}
		switch (select)
		{
		case 1:
			printf("请输入要插入的元素（以-1结束）:\n");
			while (scanf("%d", &item), item != -1)
			{
				SListpushBack(&list, item);
			}
			break;
		case 2:
			printf("请输入要插入的元素（以-1结束）:\n");
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
			printf("尾部删除数据成功！\n");
			break;
		case 6:
			SListpopFront(&list);
			printf("头部删除数据成功！\n");
			break;
		case 7:
			printf("链表的长度为：%d\n", SListLength(&list));
			break;
		case 8:
			printf("请输入要查找的元素：");
			scanf("%d", &item);
			s = SListFind(list, item);
			if (s != NULL)
			{
				printf("找到了！\n");
			}
			else
			{
				printf("链表中没有该元素，查找失败！\n");
			}
			break;
		case 9:
			printf("请输入要删除的元素：");
			scanf("%d", &item);
			SListEraseByVal(&list, item);
			break;
		case 10:
			SListSort(&list);
			break;
		case 11:
			printf("表头元素为%d\n", SListFront(list));
			break;
		case 12:
			printf("表尾元素为%d\n", SListback(list));
			break;
		case 13:
			DeleteAll(&list);
			break;
		case 14:
			SListReverse(&list);
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	}
	
	system("pause");
	return 0;
}