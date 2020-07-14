// linerList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "dynamicSequence.h"

int main()
{
	/*
	SqList L;
	InitList_Sq(L);

	for (int i = 1; i <= 5; i++)
		ListInsert_Sq(L, 1, i);
	printL(L);
	
	ElemType e = 0;
	for (int j = 0; j < 6; j++)
	{
		if (ListDelete_Sq(L, 1, e))
		{
			printf("e = %d\n", e);
			printL(L);
		}
		else
			printf("delete error\n");
	}

	for (int i = 1; i <= 5; i++)
	{
		if(!ListInsert_Sq(L, i , i))
			printf("insert error\n");
	}
	printL(L);

	int index = 0, elem = 1;
	index = LocateElem_Sq(L, elem);
	printf("locate %d, index: %d\n", elem, index);
	DestroyList(L);
	*/
	
	SqList La, Lb, Lc;
	InitList_Sq(La);
	InitList_Sq(Lb);
	InitList_Sq(Lc);
	for (int i = 0; i < 10; i++)
	{
		if(!ListInsert_Sq(La, La.length + 1, 2 * i +1 ) || !ListInsert_Sq(Lb, Lb.length + 1, 2 * i))
			printf("insert error!\n");		
	}
	ListInsert_Sq(Lb, 11, 20);
	printL(La, "La");
	printL(Lb, "Lb");
	MergeList_Sq(La, Lb, Lc);
	printL(Lc, "Lc");

	DestroyList(La);
	DestroyList(Lb);
	DestroyList(Lc);

}
