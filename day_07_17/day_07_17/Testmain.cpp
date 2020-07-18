#include "seqlist.h"

int main()
{
	SeqList list;
	SeqListInit(&list);
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
			while(scanf("%d", &item),item != -1)
			{
				SeqListPushBack(&list, item);
			}
			printf("尾部插入数据成功！\n");
			break;
		case 2:
			printf("请输入要插入的数据<以-1结束>:");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushFont(&list, item);
			}
			printf("头部插入数据成功！\n");
			break;
		case 3:
			SeqListShow(&list);
			break;
		case 4:
			SeqlListPopBack(&list);
			break;
		case 5:
			SeqlListPopfront(&list);
			break;
		case 6:
			printf("请输入要删除数据的位置：>");
			scanf("%d", &pos);
			SeqlListErsePos(&list,pos);
			break;
		case 7:
			printf("请输入要删除数据的元素：>");
			scanf("%d", &item);
			SeqlListErseval(&list, item);
			break;
		case 8:
			printf("请输入要插入的位置：");
			scanf("%d", &pos);
			printf("请输入要插入的元素：");
			scanf("%d", &item);
			flag = SeqListinsertpos(&list, item, pos);
			if (flag){
				printf("插入成功！");
			}
			else
			{
				printf("插入失败！");
			}
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
			pos = find(&list,item);
			if (-1 == pos){
				printf("查找失败！\n");
			}
			else
			{
				printf("查找成功！\n");
			}
			SeqListInsertVal(&list, item);
			break;
		case 11:
			printf("length = %d\n", SeqListLength(&list));
			break;
		case 12:
			SeqListSort(&list);
			break;
		case 13:
			printf("顺序表的容量为： %d\n", SeqListCapacity(&list));
			break;
		case 14:
			Reveser(&list);
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