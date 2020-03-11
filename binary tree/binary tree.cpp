#include "binary.h"
#include "queue.h"
#include "stack.h"
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
	if (root == NULL)
		return;
	putchar(root->data);
	BinaryTreePrevOrder(root->lchild);
	BinaryTreePrevOrder(root->rchild);
	/*if (root)
	{
		putchar(root->data);
		BinaryTreePrevOrder(root->lchild);
		BinaryTreePrevOrder(root->rchild);
	}*/
	
}
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->lchild);
	putchar(root->data);
	BinaryTreeInOrder(root->rchild);
	/*if (root)
	{
		BinaryTreeInOrder(root->lchild);
		putchar(root->data);
		BinaryTreeInOrder(root->rchild);
	}*/
	
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
/* 递归真的是很费脑子，目前粗浅的总结一下，先用最简单的例子实现然后再注意细节。*/
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
	//层序遍历
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
void BinaryTreePrevOrderNonR(BTNode* root)
{
	//前序非递归
	Stack st;
	BTNode* cur = root;
	StackInit(&st, 100);
	while (cur)
	{
		putchar(cur->data);
		if (cur->rchild)
		{
			StackPush(&st, cur->rchild);

		}
		if (cur->lchild)
		{
			cur = cur->lchild;
		}
		else
		{
			cur = StackTop(&st);
			StackPop(&st);
		}

	}


	StackDestory(&st);

}
void BinaryTreeInOrderNonR(BTNode* root)
{
	//中序非递归,左根右，中序用栈，循环的条件是当前节点与上栈不为空，首先将左边支全部入栈，然后取栈顶
	//判断cur不为空的情况里，打印，出栈cur指向右孩子
	Stack st;
	StackInit(&st,100);
	//BTNode *cur = (BTNode *)malloc(sizeof(BTNode));
	BTNode * cur = root;/* 创建二叉树节点保存根节点  */
	while (cur||Stackisempty(&st))
	{
		for (;cur;cur=cur->lchild)
		{
			StackPush(&st, cur);
		}
		/* 左孩子入栈*/
		cur = StackTop(&st);
		/* 取栈顶，目的是去访问它的右孩子*/
		if (cur)
		{
			putchar(cur->data);
			StackPop(&st);
			cur = cur->rchild;
		}
		/* 打印出栈，访问右孩子*/
	}
	StackDestory(&st);
}

void BinaryTreePostOrderNonR(BTNode* root)
{
	//后序非递归
	char tag[60];
	Stack st;
	BTNode* cur = root;
	StackInit(&st, 100);
	do 
	{
		for (; cur; cur = cur->lchild)
		{
			StackPush(&st, cur);

			tag[st.size - 1] = 0;
		}

		/* 左孩子入栈，并将tag标记置0，*/
		while (Stackisempty(&st)&& tag[st.size - 1])
		{
			cur = StackTop(&st);
			putchar(cur->data);
			StackPop(&st);
        /*循环访问栈顶，打印，出栈，条件是tag为1，并且栈不为空 */
		}
		if (Stackisempty(&st))
		{
			cur = StackTop(&st);
			tag[st.size - 1] = 1;
			cur = cur->rchild;

		}
		/* 访问栈顶，将它的tag置1，访问右孩子*/
	} while (Stackisempty(&st));
	 
	
	StackDestory(&st);
}


