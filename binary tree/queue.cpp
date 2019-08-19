#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#include "queue.h"
 
void QueueInit(Queue* plist)
{
	plist->_head =plist->_rear= NULL;

}//�����ʼ����ͷ��㸳�ɿգ�
void QueueDestory(Queue* plist)
{
	QueueNode *tmp;//����ڵ�
	while (plist->_head)
	{
		tmp = plist->_head;//����������ͷ���ͷž�ͷ
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}
 void QueuePop(Queue* plist)
{
	//ͷɾ
	QueueNode *tmp;
	if (plist->_head)
	{

		tmp = plist->_head;
		plist->_head = plist->_head->_next;//ÿ������ĵ�һ��������ͷ��ͷ�����Ǻܶ��ָ��
		//nextָ�����ͷ���֮��Ľ�㣬���������cur��ֵ��ͷָ�룬���ı���ͷָ���ָ��
		free(tmp);//�ͷŵ���һ��cur
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
	 plist->_rear = cur;//�Ȱ�β�ͽ��ϣ�Ȼ���β�ͺ���
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
		