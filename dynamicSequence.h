#pragma once
#include "typedef.h"
#include <iostream>

#define LIST_INIT_SIZE  10
#define LIST_INCREASE 1

typedef struct 
{
	ElemType *elem; //base address
	int length;			//current length
	int listSize;			//current storage allocated in "sizeof(ElemType)"
}SqList;

typedef bool (*compare)(ElemType , ElemType );

bool InitList_Sq(SqList &L);
void DestroyList(SqList &L);
bool ListEmpty(SqList L);
bool InsertFirstElem(SqList &L, int i, ElemType e);
bool ListInsert_Sq(SqList &L, int i, ElemType e);
bool ListDelete_Sq(SqList &L, int i, ElemType &e);
bool Compare(ElemType e1, ElemType e2);
int LocateElem_Sq(SqList L,ElemType e);
bool MergeList_Sq(SqList La, SqList Lb, SqList &Lc);
void printL(SqList L, const std::string &title);