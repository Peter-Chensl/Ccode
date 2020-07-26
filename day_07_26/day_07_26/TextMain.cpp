#include"stack.h"

int main()
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
}