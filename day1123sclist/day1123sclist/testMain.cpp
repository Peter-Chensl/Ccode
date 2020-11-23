#include "sclist.h"


int main()
{
	SCListNode* sclist;
	SClistInit(&sclist);
	Elemtype item;
	SCListNode* s = NULL;
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
		switch (select)
		{
		case 1:
			printf("请输入你要插入的数字（以-1结束）:\n");
			while (scanf("%d", &item), item != -1)
			{
				SCListpushfront(&sclist, item);
			}
			break;
		case 2:
			printf("请输入你要插入的数字（以-1结束）:\n");
			while (scanf("%d", &item), item != -1)
			{
				SCListpushback(&sclist, item);
			}
			break;
		case 3:
			SClistdisplay(sclist);
			break;
		case 4:
			select = 0;
			break;
		case 5:
			SCListpopback(&sclist);
			printf("尾部删除数据成功！\n");
			break;
		case 6:
			SCListpopfront(&sclist);
			printf("头部删除数据成功！\n");
			break;
		case 7:
			printf("链表的长度为：%d\n", SCListLength(sclist));
			break;
		case 8:
			printf("请输入你要查找的元素:\n");
			scanf("%d", item);
			s = SCListFind(sclist, item);
			if (s!=NULL)
			{
				printf("找到了！\n");
			}
			else
				printf("没有找到！\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	}
	return 0;
}