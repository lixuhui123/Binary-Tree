#pragma once
#include "binary.h"//���������е�BTNod������
//typedef int QuDataType;
typedef BTNode* QuDataType;
typedef struct QueueNode
{
	QuDataType _data;//���Ա�
	struct QueueNode* _next;

}QueueNode;//����ڵ㣬���������еĵ����飬������һ��Ҫ�洢�ı�������һ��ָ�룬����_data
//��ֵ��ʱ����Ҫ��̬���ٸ��ڴ棬�������ʹ�õ��Ƕѿռ�
typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _rear;

}Queue;//������������ʼ�� Queue test;plist=&test;������¼ͷ��㣻
 //�ṹ��Ķ���ͳ�ʼ��
void QueueInit(Queue* plist);
void QueueDestory(Queue* plist);
//QueueNode* BuyQueueNode(QuDataType x);
 void QueuePop(Queue* plist);
 // ��pos�ĺ�����в���
 // ��pos��ǰ����в���
  void QueuePrint(Queue* plist);
  QuDataType QueueTop(Queue* plist);
 void QueuePush(Queue * plist, QuDataType x);
 int Queueisempty(Queue* plist);
 
 