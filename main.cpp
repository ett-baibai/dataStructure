// linerList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "dynamicSequence.h"
#include "linkList.h"

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
	LinkList La;
	InitList_L(La);
	printL(La, "La");
	printf("\n\n");

	for (int i = 1; i < 4; i++)
	{
		if (!ListInsert_L(La, i, i))
			printf("loop insert error, i = %d\n", i);
	}

	printf("\n\n");
	if (!ListInsert_L(La, 5, 5))
		printf("single insert error!\n\n\n");
	printL(La, "La");

	printf("\n\n");
	ElemType e = 0; int index = 1;
	for (int j = 0; j < 5; j++)
	{
		if (!ListDelete_L(La, index, e))
			printf("delete error!\n\n\n");
		else
			printf("index: %d has been deleted, value is %d\n\n\n", index, e);
	}

	printL(La, "La");

	DestoryList_L(La);
}

int main()
{
	//TestSequence();
	TestLinkList();
}
