#pragma once
 
#include<stdio.h>
#include<stdlib.h>

#include <assert.h>
#include "binary.h"
typedef BTNode* StDataType;
typedef struct Stack
{
	StDataType* array; // ָ��̬���ٵ����飬˳���
	size_t size; // ��Ч���ݸ���
	size_t capicity; // �����ռ�Ĵ�С
}Stack;//һ������
// ������ɾ��Ľӿ�
void StackInit(Stack* psl, size_t capacity);
void StackDestory(Stack* psl);
void CheckCapacity(Stack* psl);
void StackPush(Stack* psl, StDataType x);
void StackPop(Stack* psl);
int  Stackisempty(Stack* psl);
StDataType StackTop(Stack* psl);

 