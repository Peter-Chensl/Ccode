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
		printf("请选择>");
		scanf("%d", &select);
		if (0 == select)
		{
			break;
		}
		switch (select)
		{
		case 1:
			printf("请输入要插入的数据<以-1结束>:");
			while (scanf("%d", &item), item != -1)
			{
				SListPushBack(&list, item);
			}
			printf("尾部插入数据成功！\n");
			break;
		case 2:
			printf("请输入要插入的数据<以-1结束>:");
			while (scanf("%d", &item), item != -1)
			{
				SListPushFront(&list, item);
			}
			printf("头部插入数据成功！\n");
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
			printf("请输入要删除数据的元素：>");
			scanf("%d", &item);
			SlistEraseByval(&list, item);
			break;
		case 8:
			break;
		case 9:
			printf("请输入要插入元素的值：");
			scanf("%d", &item);
			SeqListSort(&list);
			SeqListInsertVal(&list, item);
			break;
		case 10:
			printf("请输入要查找元素的值：");
			scanf("%d", &item);
			p = find(list, item);
			if (NULL == p){
				printf("查找失败！\n");
			}
			else
			{
				printf("查找成功！\n");
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
			printf("输入错误请重新输入！\n");
			break;

		}
		system("pause");
		system("cls");

	}
	SeqListDestroy(&list);
	return 0;
}