#pragma once
#include "typedef.h"
#include <iostream>

typedef struct DuLNode
{
	ElemType data;
	struct DuLNode* next;
	struct DuLNode* prior;
}DuLNode, * DuLinkList;

bool InitList_DuL(DuLinkList& L, bool withHead = 1);
bool ListEmpty_DuL(DuLinkList L);
void DestoryList_DuL(DuLinkList L);
bool LocateNode_DuL(DuLinkList L, int i, DuLNode* &p);//what will be located is the (i-1)th node
bool ListInsert_DuL(DuLinkList& L, int i, ElemType e);
bool ListDelete_DuL(DuLinkList& L, int i, ElemType& e);
void MergeList_DuL(DuLinkList La, DuLinkList Lb, DuLinkList& Lc);
void MergeList_DuL(DuLinkList& La, DuLinkList Lb);
void printDuL(DuLinkList L, std::string title);
