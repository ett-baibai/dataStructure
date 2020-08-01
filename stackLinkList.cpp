#include "stackLinkList.h"

void InitStack_L(StackLinkList& L)
{
	L = (StackNode*)malloc(sizeof(StackNode));
	if (!L)exit(OVER_FLOW);
	L->top = NULL;
}

void DestroyStack_L(StackLinkList& L)
{
	if (L)
	{
		StackNode* deleteNode = L->top;
		while (deleteNode)
		{
			L->top = deleteNode->top;
			free(deleteNode);
			deleteNode = L->top;
		}
		free(L);
	}
}

bool StackEmpty_L(StackLinkList L)
{
	return(NULL == L->top);
}

bool Push_L(StackLinkList& L, SElemType e)
{
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	if (!p)return ERROR;

	p->value = e;
	p->top = L->top;
	L->top = p;
	return OK;
}

bool GetPop_L(StackLinkList L, SElemType& e)
{
	if (StackEmpty_L(L))return ERROR;
	else
	{
		e = L->top->value;
		return OK;
	}
}

bool Pop_L(StackLinkList& L, SElemType& e)
{
	if (StackEmpty_L(L))return ERROR;
	else
	{
		e = L->top->value;
		StackNode* deleteNode = L->top;
		L->top = deleteNode->top;
		free(deleteNode);
		return OK;
	}
}

void printStackL(StackLinkList L, const std::string& title)
{
	std::cout << "Á´Õ»" << title << ":" << std::endl;
	if (StackEmpty_L(L))
	{
		printf("¿ÕÕ»\n");
		return;
	}
	printf("Õ»¶¥ ---> Õ»µ×\n");
	StackNode* showNode = L->top;
	int i = 0;
	while (showNode)
	{
		printf("StackNode%2d :addr: %p, value:%d\n", i, showNode, showNode->value);
		showNode = showNode->top;
		i++;
	}
	printf("length:%d\n", i);
	printf("\n\n");
}
