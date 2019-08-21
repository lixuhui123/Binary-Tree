#pragma once
#include "binary.h"//将二叉树中的BTNod引进来
//typedef int QuDataType;
typedef BTNode* QuDataType;
typedef struct QueueNode
{
	QuDataType _data;//线性表
	struct QueueNode* _next;

}QueueNode;//链表节点，这是链表当中的单个块，包含了一个要存储的变量，和一个指针，当给_data
//赋值的时候需要动态开辟个内存，因此链表使用的是堆空间
typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _rear;

}Queue;//链表，用它来初始化 Queue test;plist=&test;用来记录头结点；
 //结构体的定义和初始化
void QueueInit(Queue* plist);
void QueueDestory(Queue* plist);
//QueueNode* BuyQueueNode(QuDataType x);
 void QueuePop(Queue* plist);
 // 在pos的后面进行插入
 // 在pos的前面进行插入
  void QueuePrint(Queue* plist);
  QuDataType QueueTop(Queue* plist);
 void QueuePush(Queue * plist, QuDataType x);
 int Queueisempty(Queue* plist);
 
 