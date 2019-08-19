#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#include "queue.h"
 
void QueueInit(Queue* plist)
{
	plist->_head =plist->_rear= NULL;

}//链表初始化，头结点赋成空；
void QueueDestory(Queue* plist)
{
	QueueNode *tmp;//链表节点
	while (plist->_head)
	{
		tmp = plist->_head;//不断任命新头，释放旧头
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}
 void QueuePop(Queue* plist)
{
	//头删
	QueueNode *tmp;
	if (plist->_head)
	{

		tmp = plist->_head;
		plist->_head = plist->_head->_next;//每个链表的第一个是它的头，头可以是很多的指针
		//next指向的是头结点之后的结点，将这个结点的cur赋值给头指针，即改变了头指针的指向，
		free(tmp);//释放掉第一个cur
	}
}
 void QueuePush(Queue * plist, QuDataType x)
 {
	 QueueNode* cur = (QueueNode*)malloc(sizeof(QueueNode));
	 cur->_data = x;
	 cur->_next = NULL;
	 if (Queueisempty(plist))
	 {
		 
		 plist->_head = plist->_rear = cur;
		 return;
	 }
	 plist->_rear->_next = cur;
	 plist->_rear = cur;//先把尾巴接上，然后把尾巴后移
 }
 int Queueisempty(Queue* plist)
 {
	 return plist->_head == NULL;
 }
//void QueuePrint(Queue* plist)
//{
//	assert(plist);
//
//	QueueNode* cur;
//	for (cur=plist->_head;cur;cur=cur->_next)
//	{
//		printf("%d->", cur->_data);
//	}
//	printf("NULL\n");
//}
QuDataType QueueTop(Queue* plist)
{
	if (Queueisempty(plist))
	{
		return (QuDataType)0;
	}
	return plist->_head->_data; 
}
		