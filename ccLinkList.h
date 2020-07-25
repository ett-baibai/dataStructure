#pragma once
#include "typedef.h"
#include <iostream>

typedef struct CcNode
{
	ElemType data;
	struct CcNode* next;
	struct CcNode* prior;
}CcNode, * CcLinkList;

bool InitList_CcL(CcLinkList& L, bool withHead = 1);
bool ListEmpty_CcL(CcLinkList L);
void DestoryList_CcL(CcLinkList L);
bool LocateNode_CcL(CcLinkList L, int i, CcNode*& p);//what will be located is the (i-1)th node
bool ListInsert_CcL(CcLinkList& L, int i, ElemType e);
bool ListDelete_CcL(CcLinkList& L, int i, ElemType& e);
void printCcL(CcLinkList L, std::string title);
