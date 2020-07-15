#include "linkList.h"
#include <stdlib.h>
#include <stdio.h>

bool InitList_L(LinkList& L)
{
	L = (LNode*)malloc(sizeof(LNode));
	if (NULL == L)return ERROR;

	L->next = (LNode*)malloc(sizeof(LNode)); //attach tail node
	if(NULL == L->next)return ERROR;

	L->next->next = NULL;
	return OK;
}

bool ListEmpty_L(LinkList L)
{
	return (NULL == L->next->next);
}

void DestoryList_L(LinkList L)
{
	LNode *tempNode = L->next->next, *freeNode = NULL;

	while (tempNode)
	{
		freeNode = tempNode;
		tempNode = tempNode->next;
		free(freeNode);
	}

	free(L->next);
	free(L);
}

bool ListInsert_L(LinkList& L, int i, ElemType e)
{
	/*
	if (i < 1)return ERROR;

	LNode* tempNode = L->next, *insertNode = NULL;
	
	int loop = 1;
	for (; loop < i; loop++)
	{
		if (!tempNode)return ERROR;
		else tempNode = tempNode->next;			
	}
	if (!tempNode)return ERROR;
	*/

	int j = 1;
	LNode* tempNode = L->next, * insertNode = NULL;
	while (tempNode && j < i)
	{
		tempNode = tempNode->next;
		j++;
	}
	if (!tempNode || j > i )return ERROR;

	insertNode = (LNode*)malloc(sizeof(LNode));
	if (!insertNode)return ERROR;
	insertNode->data = e;
	insertNode->next = tempNode->next;
	tempNode->next = insertNode;	 
	
	return OK;
}


bool ListDelete_L(LinkList& L, int i, ElemType& e)
{
	int j = 1;
	LNode* tempNode = L->next, *deleteNode = NULL;
	while (tempNode && j < i)
	{
		tempNode = tempNode->next;
		j++;
	}
	if (!tempNode || j > i)return ERROR;

	deleteNode = tempNode->next;
	if (!deleteNode)return NULL;
	tempNode->next = deleteNode->next;
	deleteNode->next = NULL;
	e = deleteNode->data;
	free(deleteNode);
	deleteNode = NULL;

	return OK;
}

void printL(LinkList L, std::string title)
{
	std::cout << title << ":" << std::endl;
	if (ListEmpty_L(L))printf("empty list!\n");

	LNode* showNode = L->next->next;

	int i = 1;
	while (showNode)
	{
		printf("LNode%d :addre: %p, value:%d\n", i, showNode, showNode->data);
		showNode = showNode->next;
		i++;
	}
}
