#pragma once
#include "typedef.h"
#include <iostream>

typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode, *LinkList;

bool InitList_L(LinkList &L, bool withHead = 1);
bool ListEmpty_L(LinkList L);
void DestoryList_L(LinkList L);
bool ListInsert_L(LinkList& L, int i, ElemType e);
bool ListDelete_L(LinkList& L, int i, ElemType &e);
void MergeList_L(LinkList La, LinkList Lb, LinkList& Lc);
void MergeList_L(LinkList &La, LinkList Lb);
void printL(LinkList L, std::string title);
