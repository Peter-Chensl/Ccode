#include "dclist.h"

int main()
{
	DCListNode* dclist;
	DCListNode *p = NULL;
	DCListInit(&dclist);
	Elemtype item;
	int select = 1;
	while (select)
	{
		printf("##########################################\n");
		printf("#   [1] push_back      [2] push_front    #\n");
		printf("#   [3] show           [4] exit          #\n");
		printf("#   [5] pop_back       [6] pop_front     #\n");
		printf("#   [7] lengh          [8] find          #\n");
		printf("#   [9] insertbyval    [10] Erasebypval  #\n");
		printf("#   [11] frontval      [12] lastval      #\n");
		printf("##########################################\n");
		printf("请选择：");
		scanf("%d", &select);
		switch (select)
		{
			case 1:
				printf("请输入你要插入的数据，以-1结束\n");
				while (scanf("%d", &item), item != -1)
				{
					DCListPushback(&dclist, item);
				}
				printf("尾部插入数据成功！\n");
				break;
			case 2:
				printf("请输入你要插入的数据，以-1结束\n");
				while (scanf("%d", &item), item != -1)
				{
					DCListPushfront(&dclist, item);
				}
				printf("头部插入数据成功！\n");
				break;
			case 3:
				DCListDisplay(dclist);
				break;
			case 4:
				select = 0;
				break;
			case 5:
				DCListpopback(&dclist);
				printf("尾部删除成功！\n");
				break;
			case 6:
				DCListpopfront(&dclist);
				printf("头部删除成功！\n");
				break;
			case 7:
				printf("链表的长度为%d\n",DCListLength(dclist));
				break;
			case 8:
				printf("请输入你要查找的数字！\n");
				scanf("%d", &item);
				p = DCListfind(dclist,item);
				if (p == NULL)
				{
					printf("没有找到i！\n");
				}
				else
					printf("找到了！\n");
				break;
			case 10:
				printf("请输入你要删除的数字！\n");
				scanf("%d", &item);
				DCListErasebyval(dclist, item);
				//printf("删除成功！\n");
				break;
			case 11:
				printf("FrontVal:%d\n", DCListFrontVal(dclist));
				break;
			case 12:
				printf("LastVal:%d\n", DCListlastVal(dclist));
				break;
			case 13:
				DCListClear(&dclist);
				break;
			default:
				break;
		}
	}
	return 0;
}