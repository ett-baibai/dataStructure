// linerList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "dynamicSequence.h"
#include "linkList.h"
#include "doubleLinkList.h"
#include "ccLinkList.h"
#include "train.h"
#include "stackSequence.h"
#include "stackLinkList.h"
#include "ccQueueSequence.h"
#include "queueLinkList.h"

void  TestSequence()
{
	SqList La, Lb, Lc;
	InitList_Sq(La);
	InitList_Sq(Lb);
	for (int i = 0; i < 10; i++)
	{
		if (!ListInsert_Sq(La, La.length + 1, 2 * i + 1) || !ListInsert_Sq(Lb, Lb.length + 1, 2 * i))
			printf("insert error!\n");
	}
	printSq(La, "La");
	printSq(Lb, "Lb");

	ElemType e = 0;
	ListDelete_Sq(La, 7, e);
	printf("La delete :%d\n\n\n", e);
	ListInsert_Sq(Lb, 11, 20);

	if(!MergeList_Sq(La, Lb, Lc)) printf("merge error!\n");
	else printSq(Lc, "Lc");

	DestroyList(La);
	DestroyList(Lb);
	DestroyList(Lc);
}

void TestLinkList()
{
	/*
	LinkList La, Lb, Lc;
	InitList_L(La);
	InitList_L(Lb);
	InitList_L(Lc);

	//test insert
	printf("###test insert:\n");
	int i = 1;
	for (; i < 6; i++)
	{
		if (!ListInsert_L(La, i, i))
			printf("loop insert error, index = %d\n", i);
	}
	if (!ListInsert_L(La, 7, 100))printf("La single insert error!\n");
	printL(La, "La");

	//test delete
	printf("###test delete:\n");
	ElemType e = 0; int position = 1;
	for (int j = 0; j <8; j++)
	{
		if (!ListDelete_L(La, position, e))
			printf("delete error!\n");
		else
			printf("index: %d has been deleted, value is %d\n", position, e);
	}
	printL(La, "La");
	
	//test merge
	printf("###test merge:\nmerge before:\n");
	for (i = 1; i < 6; i++)
	{
		if (!ListInsert_L(La, i, 2 * i - 1) || !ListInsert_L(Lb, i, 2 * i))
			printf("loop insert error, index = %d\n", i);
	}
	if (!ListInsert_L(La, i, 2 * i - 1))printf("single insert error, i = %d\n", i);
	printL(La, "La");
	printL(Lb, "Lb");
	printL(Lc, "Lc");

	//MergeList_L(La, Lb, Lc);
	MergeList_L(La, Lb);
	printf("merged:\n");
	printL(La, "La");
	printL(Lb, "Lb");
	printL(Lc, "Lc");

	DestoryList_L(La);
	DestoryList_L(Lb);
	DestoryList_L(Lc);
	*/

	//test no head Node
	printf("###test withoutHead:\n");
	LinkList L;
	if (!InitList_L(L, 0))
	{
		printf("初始化失败\n");
		exit(0);
	}
	int k = 1;
	for (; k <= 5; k++)
	{
		if (!ListInsert_L(L, k, k))printf("loop insert error! k =%d\n", k);
	}
	if (!ListInsert_L(L, 6, 6))printf("single insert error!\n");

	printL(L,"L");
	DestoryList_L(L);
	
}

void TestDoubleLinkList()
{
	//test insert
	printf("###test insert:\n");
	DuLinkList L;
	InitList_DuL(L);
	int i = 1;
	for (; i < 6; i++)
	{
		if (!ListInsert_DuL(L, i, i))
			printf("loop insert error, index: %d\n", i);
	}
	if (!ListInsert_DuL(L, i, 100))
		printf("single insert error\n");
	printDuL(L, "La");

	//test delete
	ElemType deleteElem = -1;
	printf("###test delete:\n");
	if (!ListDelete_DuL(L, 6, deleteElem))
		printf("single delete error\n");
	else
		printf("signle delete ok, delete value = %d\n", deleteElem);
	printDuL(L, "La");
	DestoryList_DuL(L);
}

void TestCirculaiLinkList()
{
	//test insert
	printf("###test insert:\n");
	CcLinkList L;
	InitList_CcL(L);
	
	int i = 1;
	for (; i < 4; i++)
	{
		if (!ListInsert_CcL(L, i, i))
			printf("loop insert error, index: %d\n", i);
	}
	if (!ListInsert_CcL(L, 5, 100))
		printf("single insert error\n");
	printCcL(L, "La");
	
	//test delete
	DestoryList_CcL(L);
}

void TestStackSq()
{
	SqStack S;
	InitStack_Sq(S);
	printf("####Push_Sq:\n");
	for (int i = 0; i < 15; i++)
		if (!Push_Sq(S, i+1))printf("Push_Sq error!\n");		
	printStackSq(S, "S");

	printf("####Pop_Sq:\n");
	SElemType e = 0;
	for (int i = 0; i < 8; i++)
	{
		if (!Pop_Sq(S, e))printf("Push_Sq error!\n");
		else printf("Pop_Sq succ, value: %d\n", e);
	}
	printf("\n\n");
	printStackSq(S, "S");

	DestroyStack_Sq(S);
}

void TestStackLinkList()
{
	StackLinkList StackL;
	InitStack_L(StackL);
	printf("####Push_L:\n");
	for (SElemType i = 0; i < 15; i++)
		if (!Push_L(StackL, i + 1))printf("Push_L error!\n");
	printStackL(StackL, "StackL");

	printf("####Pop_L:\n");
	ElemType e = 0;
	for (ElemType i = 0; i < 8; i++)
	{
		if (!Pop_L(StackL, e))printf("Push_L error!\n");
		else printf("Pop_L succ, value: %d\n", e);
	}
	printf("\n\n");
	printStackL(StackL, "StackL");
	DestroyStack_L(StackL);
}

void TsetCcQueueSq()
{
	SqQueue S;
	InitQueue_Sq(S);
	printf("####Enqueue_Sq:\n");
	for (int i = 0; i < 15; i++)
		if (!EnQueue_Sq(S, i + 1))printf("EnQueue_Sq error!\n");
	printQueueSq(S, "S");

	printf("####Dequeue_Sq:\n");
	QElemType e = 0;
	for (int i = 0; i < 8; i++)
	{
		if (!DeQueue_Sq(S, e))printf("DeQueue_Sq error!\n");
		else printf("DeQueue_Sq succ, value: %d\n", e);
	}
	printf("\n\n");
	printQueueSq(S, "S");

	DestroyQueue_Sq(S);
}

void TestQueueLinkList()
{
	LinkQueue L;
	InitQueue_L(L);
	printf("####Enqueue_L:\n");
	for (int i = 0; i < 15; i++)
		if (!EnQueue_L(L, i + 1))printf("EnQueue_L error!\n");
	printQueueL(L, "L");

	printf("####Dequeue_L:\n");
	QElemType e = 0;
	for (int i = 0; i < 18; i++)
	{
		if (!DeQueue_L(L, e))printf("DeQueue_L error!\n");
		else printf("DeQueue_L succ, value: %d\n", e);
	}
	printf("\n\n");
	printQueueL(L, "L");

	DestroyQueue_L(L);
}

void Ftrain()
{
	//Train_2_10();
	//Train_2_11();
	//Train_2_12();
	//Train_2_13();
	//Train_2_15();
	//Train_2_19();
	//Train_2_20();
	//Train_2_21();
	//Train_2_22();
	//Train_2_23();
	//Train_2_24();
	//Train_3_9();
	//Train_3_10();
	//Train_3_21();
	//Train_3_24();
	//Train_3_25();
	//Train_2_29();
	//Train_2_30();
	//Train_3_31();

}

int main()
{
	//Ftrain();
	//TestSequence();
	//TestLinkList();
	//TestDoubleLinkList();
	//TestCirculaiLinkList();
	
	//TestStackSq();
	//TestStackLinkList();
	//TsetCcQueueSq();
	//TestQueueLinkList();
	//Practice_3_2_2_CheckOfBrackets();
	//Practice_3_2_2_InfixExpressionEvaluation();
	Practice_4_3_MatchPatternString();
	return 0;
}
