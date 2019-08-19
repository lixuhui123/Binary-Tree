#include "binary.h"
#include "queue.h"
#include "stack.h"
//队列用线性表，栈用顺序表
int main()
{
	BTNode * root = BinaryTreeCreate("ABD#GI##J###CE#HK###F##", 0);
	printf("%d  ", sizeof(BinaryTreeNode));
	printf("%d  ", sizeof(BTNode));
	BinaryTreePrevOrder(root);
	putchar('\n');
	BinaryTreeInOrder(root);
	putchar('\n');

	BinaryTreePostOrder(root);
	putchar('\n');
	BinaryTreeLevelOrder(root);
	putchar('\n');
	BinaryTreeDestory(root);
	/*Queue qu;
	QueueInit(&qu);
	QueuePush(&qu, 1);
	QueuePush(&qu, 2);
	QueuePush(&qu, 12);
	QueuePush(&qu, 14);
	QueuePush(&qu, 5);
	QueuePrint(&qu);*/


	//Stack st;
	//StackInit(&st, 100);
	//Stackisempty(&st);
	////StackPush(&st,  44);
	//printf("%d ",StackTop(&st));
	//StackDestory(&st);

	system("pause");
	return 0;
}