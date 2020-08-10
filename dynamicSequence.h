#pragma once
#include "typedef.h"
#include <iostream>

#define LIST_INIT_SIZE  10
#define LIST_INCREASE 1

typedef struct 
{
	ElemType *elem; //base address
	int length;		//current length
	int listSize;	//current storage allocated in "sizeof(ElemType)"
}SqList;

typedef bool (*compare)(ElemType , ElemType );

bool InitList_Sq(SqList &Sq);
void DestroyList(SqList &Sq);
bool ListEmpty(SqList Sq);
bool ListInsert_Sq(SqList &Sq, int i, ElemType e);
bool ListDelete_Sq(SqList &Sq, int i, ElemType &e);
bool Compare(ElemType e1, ElemType e2);
int LocateElem_Sq(SqList Sq,ElemType e);
bool MergeList_Sq(SqList SqA, SqList SqB, SqList &SqC);
void printSq(SqList Sq, const std::string &title);