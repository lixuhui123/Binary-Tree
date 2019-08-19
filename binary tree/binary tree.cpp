#include "binary.h"
#include "queue.h"
BTNode* BinaryTreeCreate(const BTDataType* src, int n )
{
	//根据一个特殊的串来唯一确定一棵树，前序遍历ABD#GI##J###CE#HK###F##
	//ctrl+f查找，ctrl+h,替换
	//功能和过程分开
	//先实现简单的
	static int s_n = 0;//局部的静态变量，另外一种全局变量的表示方式，安全，生命周期在本文件中
	if (src[s_n]=='#')
	{
		s_n++;
		return NULL;
	}
	BTNode *cur = (BTNode *)malloc(sizeof(BTNode));
	cur->data = src[s_n];
	printf("%c ", cur->data);
	s_n++;
	cur->lchild = BinaryTreeCreate(src, n);
	cur->rchild = BinaryTreeCreate(src, n);
	return cur;
	//在进栈之前这层栈会记住所所有的这层栈当中的所有数据。
	//建立一个二叉树结构而不是一个数组，因为左右孩子也是一个节点类型
}
//递归原则：先入后出原则
//递归实现的方式，递归前面是判断出栈的条件,栈中包含整个函数，出栈会掉到上一层
//在这里想要能够自己自主实现，
/* 递归的层级关系是什么样子，切记一定不要把自己的思维陷入过深，我在写这层栈我就只想
这层栈在干什么，把功能和递归分开想，每层栈的功能是一样的，想最简单的情况*/

/* 求一个数值中第n大的数*/
void BinaryTreePrevOrder(BTNode* root) 
{
	//前序遍历,记怎么做的
 	if (root)
	{
		putchar(root->data);
		BinaryTreePrevOrder(root->lchild);
		BinaryTreePrevOrder(root->rchild);
	}
	
}
void BinaryTreeInOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreeInOrder(root->lchild);
		putchar(root->data);
		BinaryTreeInOrder(root->rchild);
	}
	
}
void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePostOrder(root->lchild);
		BinaryTreePostOrder(root->rchild);
		putchar(root->data);

	}
}
void BinaryTreeDestory(BTNode* root)
{
	if (root)
	{
		BinaryTreeDestory(root->lchild);
		BinaryTreeDestory(root->rchild);
		free(root);
	}
}
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue qu;
	BTNode *cur;
	QueueInit(&qu);
	QueuePush(&qu, root);
	while (!Queueisempty(&qu))
	{

		cur = QueueTop(&qu);
		putchar(cur->data);
		if (cur->lchild)
		{
			QueuePush(&qu,cur->lchild);
		}
		if (cur->rchild)
		{
			QueuePush(&qu,cur->rchild);
		}
		QueuePop(&qu);

	}


	QueueDestory(&qu);

}
