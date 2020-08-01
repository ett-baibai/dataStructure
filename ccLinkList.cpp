#include "ccLinkList.h"
#include <stdlib.h>
#include <stdio.h>

bool InitList_CcL(CcLinkList& L, bool withHead)
{
	if (!withHead)
	{
		printf("do not support link list with no head node temporarily!\n");
		return ERROR;
	}
	L = (CcNode*)malloc(sizeof(CcNode));
	if (!L)return ERROR;
	L->next = L;
	L->prior = L;

	return OK;
}

bool ListEmpty_CcL(CcLinkList L)
{
	return (L == L->next && L == L->prior);
}

void DestoryList_CcL(CcLinkList L)
{
	if (!L)return;
	CcNode* p = L, * freeNode = NULL;
	do
	{
		freeNode = p;
		p = p->next;
		free(freeNode);
	} while (p != L);
	L = NULL;
}

bool LocateNode_CcL(CcLinkList L, int i, CcNode*& p)
{
	int j = 1;
	while (j < i)
	{
		p = p->next;
		j++;
		if (p == L)return ERROR;
	}
	return OK;
}

bool ListInsert_CcL(CcLinkList& L, int i, ElemType e)
{
	CcNode* p = L, * insertNode = NULL;
	if (!LocateNode_CcL(L, i, p))return ERROR;

	insertNode = (CcNode*)malloc(sizeof(CcNode));
	if (!insertNode)return ERROR;

	insertNode->data = e;
	insertNode->next = p->next;
	//if (p->next)//p is not a tail node
	p->next->prior = insertNode;
	p->next = insertNode;
	insertNode->prior = p;

	return OK;

}

bool ListDelete_CcL(CcLinkList& L, int i, ElemType& e)
{
	CcNode* p = L;
	if (!LocateNode_CcL(L, i, p))return ERROR;

	CcNode* deleteNode = p->next;
	if (deleteNode != L)//the node to be deleted is not NULL
	{
		p->next = deleteNode->next;
		//if (deleteNode->next)
		deleteNode->next->prior = p;//q is not the tail node			

		e = deleteNode->data;
		free(deleteNode);
		deleteNode = NULL;
	}
	return OK;
}

void printCcL(CcLinkList L, std::string title)
{
	std::cout << "list " << title << ": self addr: " << L << ", prior addre: " << L->prior << ", next addre: " << L->next << std::endl;
	if (ListEmpty_CcL(L))printf("empty list!\n");

	CcNode* showNode = L->next;

	int i = 1;
	while (showNode != L)
	{
		printf("StackNode%d : self addr: %p, prior addre: %p, next addre: %p, value:%d\n",
			i, showNode, showNode->prior, showNode->next, showNode->data);

		showNode = showNode->next;
		i++;
	}
	printf("\n");
}