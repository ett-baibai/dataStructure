#include "stackSequence.h"

void InitStack_Sq(SqStack& S)
{
	S.base = (SElemType*)malloc(sizeof(SqStack) * STACK_INIT_SIZE);
	if (!S.base)exit(OVER_FLOW);
	S.top = S.base;
	S.stackSize = STACK_INIT_SIZE;
}

void DestroyStack_Sq(SqStack& S)
{
	if (S.base)
	{
		free(S.base);
		S.base = NULL;
	}
}

bool StackEmpty_Sq(SqStack S)
{
	return (S.base == S.top);
}

int GetStackLength_Sq(SqStack S)
{
	return(S.top - S.base);
}

bool GetPop_Sq(SqStack S, SElemType& e)
{
	return OK;
}

bool Push_Sq(SqStack& S, SElemType e)
{
	if (GetStackLength_Sq(S) + 1 >= S.stackSize)
	{
		SElemType *newBase = (SElemType*)realloc(S.base, 
			sizeof(SElemType) * (S.stackSize + STACK_INCREASE));
		if (!newBase)return ERROR;
		else
		{
			S.base = newBase;
			S.stackSize += STACK_INCREASE;
		}
	}
	*S.top++ = e;
	return OK;
}

bool Pop_Sq(SqStack& S, SElemType& e)
{
	if (StackEmpty_Sq(S))return ERROR;
	e = *--S.top;
	return OK;
}

void printStackSq(SqStack S, const std::string& title)
{
	std::cout <<"Ë³ÐòÕ»"<< title << ":" << std::endl;
	if (StackEmpty_Sq(S))
	{
		printf("¿ÕÕ»\n");
		return;
	}
	printf("Õ»µ× ---> Õ»¶¥\n");
	int length = GetStackLength_Sq(S);
	for (int i = 0; i < length; i++)
		printf("S.base[%2d] :addre: %p, value:%d\n", i, &S.base[i], S.base[i]);
	printf("length:%d\n", length);
	printf("\n\n");
}
