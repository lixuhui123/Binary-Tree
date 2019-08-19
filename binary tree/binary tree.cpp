#include "binary.h"
#include "queue.h"
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
