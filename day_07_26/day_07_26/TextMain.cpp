//#include"stack.h"
#include "queue.h"

/*int main()
{
	SeqStack st;
	SeqStackInit(&st,10);

	SeqStackPush(&st, 1);
	SeqStackPush(&st, 2);
	SeqStackPush(&st, 3);
	SeqStackPush(&st, 4);
	SeqStackPush(&st, 5);
	SeqStackShow(&st);

	SeqStackPush(&st, 1);
	SeqStackShow(&st);

	int top_val;
	while (!IsEmpety(&st))
	{
		//top_val = SeqStackTop(&st);
		SeqStacktop(&st, &top_val);
		SeqStackpop(&st);
		printf("%d ³öÕ»\n", top_val);
	}
	SeqStackDestroy(&st);
	system("pause");
	return 0;
}*/
/*int main()
{
	LinkStack st;
	LinkStackInit(&st);

	LinkStackPush(&st, 1);
	LinkStackPush(&st, 2);
	LinkStackPush(&st, 3);
	LinkStackPush(&st, 4);
	LinkStackPush(&st, 5);
	LinkStackShow(&st);

	LinkStackPop(&st);
	LinkStackShow(&st);

	printf("top = %d\n", LinkStackTop(&st));

	printf("size = %d\n", LinkStacksize(&st));
	LinkStackDestroy(&st);
	system("pause");
	return 0;
}*/
int main()
{
	LinkQueue Q;
	LinkQueueInit(&Q);
	LinkQueueEn(&Q, 1);
	LinkQueueEn(&Q, 2);
	LinkQueueEn(&Q, 3);
	LinkQueueEn(&Q, 4);
	LnkQueueShow(&Q);
	LinkQueueDe(&Q);
	LnkQueueShow(&Q);
	int val = 0;
	while (!LinkQueueEmpty(&Q))
	{
		val = LinkQueueFront(&Q);
		 LinkQueueDe(&Q);
		 printf("%d³ö¶Ó\n", val);
	}
	system("pause");
	return 0;
}