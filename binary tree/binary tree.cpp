#include "binary.h"
#include "queue.h"
#include "stack.h"
BTNode* BinaryTreeCreate(const BTDataType* src, int n )
{
	//����һ������Ĵ���Ψһȷ��һ������ǰ�����ABD#GI##J###CE#HK###F##
	//ctrl+f���ң�ctrl+h,�滻
	//���ܺ͹��̷ֿ�
	//��ʵ�ּ򵥵�
	static int s_n = 0;//�ֲ��ľ�̬����������һ��ȫ�ֱ����ı�ʾ��ʽ����ȫ�����������ڱ��ļ���
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
	//�ڽ�ջ֮ǰ���ջ���ס�����е����ջ���е��������ݡ�
	//����һ���������ṹ������һ�����飬��Ϊ���Һ���Ҳ��һ���ڵ�����
}
//�ݹ�ԭ��������ԭ��
//�ݹ�ʵ�ֵķ�ʽ���ݹ�ǰ�����жϳ�ջ������,ջ�а���������������ջ�������һ��
//��������Ҫ�ܹ��Լ�����ʵ�֣�
/* �ݹ�Ĳ㼶��ϵ��ʲô���ӣ��м�һ����Ҫ���Լ���˼ά����������д���ջ�Ҿ�ֻ��
���ջ�ڸ�ʲô���ѹ��ܺ͵ݹ�ֿ��룬ÿ��ջ�Ĺ�����һ���ģ�����򵥵����*/

/* ��һ����ֵ�е�n�����*/
void BinaryTreePrevOrder(BTNode* root) 
{
	//ǰ�����,����ô����
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
/* �ݹ�����Ǻܷ����ӣ�Ŀǰ��ǳ���ܽ�һ�£�������򵥵�����ʵ��Ȼ����ע��ϸ�ڡ�*/
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
	//�������
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
	//ǰ��ǵݹ�
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
	//����ǵݹ�,����ң�������ջ��ѭ���������ǵ�ǰ�ڵ�����ջ��Ϊ�գ����Ƚ����֧ȫ����ջ��Ȼ��ȡջ��
	//�ж�cur��Ϊ�յ�������ӡ����ջcurָ���Һ���
	Stack st;
	StackInit(&st,100);
	//BTNode *cur = (BTNode *)malloc(sizeof(BTNode));
	BTNode * cur = root;/* �����������ڵ㱣����ڵ�  */
	while (cur||Stackisempty(&st))
	{
		for (;cur;cur=cur->lchild)
		{
			StackPush(&st, cur);
		}
		/* ������ջ*/
		cur = StackTop(&st);
		/* ȡջ����Ŀ����ȥ���������Һ���*/
		if (cur)
		{
			putchar(cur->data);
			StackPop(&st);
			cur = cur->rchild;
		}
		/* ��ӡ��ջ�������Һ���*/
	}
	StackDestory(&st);
}

void BinaryTreePostOrderNonR(BTNode* root)
{
	//����ǵݹ�
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

		/* ������ջ������tag�����0��*/
		while (Stackisempty(&st)&& tag[st.size - 1])
		{
			cur = StackTop(&st);
			putchar(cur->data);
			StackPop(&st);
        /*ѭ������ջ������ӡ����ջ��������tagΪ1������ջ��Ϊ�� */
		}
		if (Stackisempty(&st))
		{
			cur = StackTop(&st);
			tag[st.size - 1] = 1;
			cur = cur->rchild;

		}
		/* ����ջ����������tag��1�������Һ���*/
	} while (Stackisempty(&st));
	 
	
	StackDestory(&st);
}


