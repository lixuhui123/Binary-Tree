#pragma once
 
#include<stdio.h>
#include<stdlib.h>

#include <assert.h>
#include "binary.h"
typedef BTNode* StDataType;
typedef struct Stack
{
	StDataType* array; // 指向动态开辟的数组，顺序表
	size_t size; // 有效数据个数
	size_t capicity; // 容量空间的大小
}Stack;//一个数组
// 基本增删查改接口
void StackInit(Stack* psl, size_t capacity);
void StackDestory(Stack* psl);
void CheckCapacity(Stack* psl);
void StackPush(Stack* psl, StDataType x);
void StackPop(Stack* psl);
int  Stackisempty(Stack* psl);
StDataType StackTop(Stack* psl);

 