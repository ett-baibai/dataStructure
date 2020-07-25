#include "doubleLinkList.h"
#include <stdlib.h>
#include <stdio.h>

bool InitList_DuL(DuLinkList& L, bool withHead)
{
	if (!withHead)
	{
		printf("do not support link list with no head node temporarily!\n");
		return ERROR;
	}
	L = (DuLNode*)malloc(sizeof(DuLNode));
	if (!L)return ERROR;
	L->next = NULL;
	L->prior = NULL;

	return OK;
}

bool ListEmpty_DuL(DuLinkList L)
{
	return (NULL == L->next);
}

void DestoryList_DuL(DuLinkList L)
{
	if (!L)return;
	DuLNode* p = L->next, * freeNode = NULL;
	while (p)
	{
		freeNode = p;
		p = p->next;
		free(freeNode);
	}
	L->next = NULL;
	free(L);
	L = NULL;
}

bool LocateNode_DuL(DuLinkList L, int i, DuLNode*& p)
{
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p)return ERROR;
	else return OK;
}

bool ListInsert_DuL(DuLinkList& L, int i, ElemType e)
{
	DuLNode *p = L, *insertNode = NULL;
	if(!LocateNode_DuL(L, i, p))return ERROR;

	insertNode = (DuLNode*)malloc(sizeof(DuLNode));
	if (!insertNode)return ERROR;

	insertNode->data = e;
	insertNode->next = p->next;
	if(p->next)//p is not a tail node
		p->next->prior = insertNode;
	p->next = insertNode;
	insertNode->prior = p;	

	return OK;

}

bool ListDelete_DuL(DuLinkList& L, int i, ElemType& e)
{
	DuLNode* p = L;
	if (!LocateNode_DuL(L, i, p))return ERROR;

	DuLNode* deleteNode = p->next;
	if (deleteNode)//the node to be deleted is not NULL
	{
		p->next = deleteNode->next;
		if (deleteNode->next)deleteNode->next->prior = p;//q is not the tail node			

		e = deleteNode->data;
		free(deleteNode);
		deleteNode = NULL;
	}
	return OK;
}

void MergeList_DuL(DuLinkList La, DuLinkList Lb, DuLinkList& Lc)
{
}

void MergeList_DuL(DuLinkList& La, DuLinkList Lb)
{
}

void printDuL(DuLinkList L, std::string title)
{
	std::cout << "list " << title << ": self addr: "<<L<<", prior addre: "<<L->prior<<", next addre: " << L->next<<std::endl;
	if (ListEmpty_DuL(L))printf("empty list!\n");

	DuLNode* showNode = L->next;

	int i = 1;
	while (showNode)
	{
		printf("LNode%d : self addr: %p, prior addre: %p, next addre: %p, value:%d\n", 
			i, showNode, showNode->prior, showNode->next,showNode->data);

		showNode = showNode->next;
		i++;
	}
	printf("\n");
}