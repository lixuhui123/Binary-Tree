#include "stack.h"
void StackInit(Stack* psl, size_t capacity)
{
	assert(psl);
	psl->capicity = capacity;
	psl->size = 0;
	psl->array = (StDataType *)malloc(sizeof(StDataType)*capacity);
	assert(psl->array);
}
void StackDestory(Stack* psl)
{
	assert(psl);
	if (psl->array)
	{
		free(psl->array);
		psl->array = NULL;
	}
	psl->capicity = 0;
	psl->size = 0;

}

void CheckCapacity(Stack* psl)
{
	assert(psl);
if (psl->size==psl->capicity)
{
	psl->capicity *= 2;
	psl->array= (StDataType *)realloc(psl->array,sizeof(StDataType)*psl->capicity);
}
}
void StackPush(Stack* psl, StDataType x)
{
	assert(psl);
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}
void StackPop(Stack* psl)
{
	assert(psl || psl->size);
	psl->size--;
}
int Stackisempty(Stack* psl)
{
	 return psl->size;
}
 StDataType StackTop(Stack* psl)
 {
	 if (!Stackisempty(psl))
	 {
		 return (StDataType)0;
	 }
	 return psl->array[psl->size - 1];
 }
