#include "linkList.h"
#include <stdlib.h>
#include <stdio.h>

bool InitList_L(LinkList& L, bool withHead)
{
	L = (LNode*)malloc(sizeof(LNode));
	if (NULL == L)return ERROR;

	if (withHead)
	{
		L->data = 1;
		L->next = (LNode*)malloc(sizeof(LNode)); //attach tail node
		if (NULL == L->next)return ERROR;
		L->next->next = NULL;
	}
	else
	{
		L->data = 0;
		L->next = NULL;
	}

	return OK;
}

bool ListEmpty_L(LinkList L)
{
	return (L->data ? NULL == L->next->next : NULL == L->next);
}

void DestoryList_L(LinkList L)
{
	if (NULL == L)return; //do not free again if freed

	LNode *tempNode = NULL, *freeNode = NULL;

	tempNode = L->data ? L->next->next : L->next;

	while (tempNode)
	{
		freeNode = tempNode;
		tempNode = tempNode->next;
		free(freeNode);
	}

	if(L->data)free(L->next);
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
	LNode* tempNode = NULL, * insertNode = NULL;
	tempNode = L->data ? L->next : L;
	
	while (tempNode && j < i)
	{
		tempNode = tempNode->next;
		j++;
	}
	if (!tempNode /*|| j > i*/ )return ERROR;

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
	LNode* tempNode = NULL, *deleteNode = NULL;
	tempNode = L->data ? L->next : L;

	while (tempNode && j < i)
	{
		tempNode = tempNode->next;
		j++;
	}
	if (!tempNode/* || j > i*/)return ERROR;

	deleteNode = tempNode->next;
	if (!deleteNode)return NULL;
	tempNode->next = deleteNode->next;
	deleteNode->next = NULL;
	e = deleteNode->data;
	free(deleteNode);
	deleteNode = NULL;

	return OK;
}

void MergeList_L(LinkList La, LinkList Lb, LinkList& Lc)
{
	LinkList pa = La->next->next, pb = Lb->next->next, pc = Lc->next;

	while (pa && pb)
	{
		if (pa->data < pb->data)
		{
			pc->next = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pb = pb->next;
		}
		pc = pc->next;
	}

	pc->next = pa ? pa : pb;

	La->next->next = NULL;
	Lb->next->next = NULL;
}

void MergeList_L(LinkList& La, LinkList Lb)
{
	LinkList pa = La->next, tempNodeLa = La->next->next, pb = Lb->next->next, tempNodeLb = NULL;

	while (tempNodeLa && pb)
	{
		if (tempNodeLa->data < pb->data)
		{
			tempNodeLa = tempNodeLa->next;			
		}
		else
		{
			tempNodeLb = pb->next;
			pb->next = tempNodeLa;
			pa->next = pb;
			pb = tempNodeLb;
		}
		pa = pa->next;
	}

	if(pb)pa->next = pb;

	Lb->next->next = NULL;
}

void printL(LinkList L, std::string title)
{
	std::cout <<"list "<< title << ":" << std::endl;
	if (ListEmpty_L(L))printf("empty list!\n");

	LNode* showNode = NULL;
	showNode = L->data ? L->next->next : L->next;

	int i = 1;
	while (showNode)
	{
		printf("LNode%d :addre: %p, value:%d\n", i, showNode, showNode->data);
		showNode = showNode->next;
		i++;
	}
	printf("\n");
}

