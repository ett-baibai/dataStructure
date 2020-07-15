// linerList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "dynamicSequence.h"


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
	printL(La, "La");
	printL(Lb, "Lb");

	ElemType e = 0;
	ListDelete_Sq(La, 7, e);
	printf("La delete :%d\n\n\n", e);
	ListInsert_Sq(Lb, 11, 20);

	if(!MergeList_Sq(La, Lb, Lc)) printf("merge error!\n");
	else printL(Lc, "Lc");

	DestroyList(La);
	DestroyList(Lb);
	DestroyList(Lc);
}

int main()
{
	TestSequence();

}
