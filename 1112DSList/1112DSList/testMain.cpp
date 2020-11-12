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
		printf("请选择：");
		scanf("%d", &select);
		if (select == 0)
		{
			break;
		}
		switch(select)
		{
		case 1:
			printf("请输入你要插入的元素：(以-1结束)\n");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushBack(&list, item);
			}
			break;
		case 2:
			printf("请输入你要插入的元素：(以-1结束)\n");
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
			printf("请输入你要查找的元素！");
			scanf("%d", &item);
			pos = SeqListFind(&list, item);
			if (pos != -1)
			{
				printf("找到了！\n");
			}
			else
			{
				printf("没有该元素！\n");
			}
			break;
		case 9:
			printf("请输入要插入的位置:");
			scanf("%d", &pos);
			printf("\n请输入要插入的元素:");
			scanf("%d", &item);
			SeqListInsert(&list, pos, item);
			break;
		case 10:
			printf("请输入要删除元素的位置:");
			scanf("%d", &pos);
			SeqListErase(&list, pos);
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
		system("pause");
		system("cls");//清空屏幕
		
	}
	return 0;
}