#include "dynamicSequence.h"
#include <stdlib.h>
#include <stdio.h>
bool InitList_Sq(SqList& Sq)
{
	Sq.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!Sq.elem)exit(OVER_FLOW);
	Sq.length = 0;
	Sq.listSize = LIST_INIT_SIZE;
	return OK;
}

void DestroyList(SqList &Sq)
{
	if (Sq.elem) 
	{
		free(Sq.elem);
		Sq.elem = NULL;
	}
}

bool ListEmpty(SqList Sq)
{
	return (0 == Sq.length);
}

bool ListInsert_Sq(SqList &Sq, int i, ElemType e)
{
	if (i < 1 || i > Sq.length + 1) return ERROR;

	if (Sq.length >= Sq.listSize)
	{	
		ElemType* newBase = (ElemType*)realloc(Sq.elem, (Sq.listSize + LIST_INCREASE) * sizeof(ElemType));
		if (NULL == newBase)return ERROR;
		Sq.elem = newBase;
		Sq.listSize += LIST_INCREASE;
		
	}

/*
	for (int looper = 0; looper < Sq.length - i + 1; looper++)
	{
		Sq.elem[Sq.length - looper] = Sq.elem[Sq.length - looper - 1];
	}
	Sq.elem[i - 1] = e;
*/
	
	ElemType* q = &(Sq.elem[i - 1]);
	ElemType* p = &(Sq.elem[Sq.length - 1]);
	for (; p >= q; --p)
	{
		*(p+1) = *p;
		//printf("p+1:addre:%p, value: %d\np:addre:%p, value: %d\n", p+1, *(p+1), p, *p);
	}
	*q = e;

/*
	printf("index(length): %d\n", Sq.length+1);
	for (int ha = 0; ha <= Sq.length; ha++)
		printf("Sq.elem[%d]: addr :%p, value: %d\n", ha, &(Sq.elem[ha]), Sq.elem[ha]);
	printf("\n\n");
*/

	Sq.length++;
	
	return OK;
}

bool ListDelete_Sq(SqList& Sq, int i, ElemType& e)
{
	if (i < 1 || i > Sq.length)return ERROR;

	e = Sq.elem[i-1];

	for (int loop = 0; loop < Sq.length - i; loop++)
	{
		Sq.elem[i - 1 + loop] = Sq.elem[i + loop];
	}

	Sq.length--;
	return OK;
}

bool Compare(ElemType e1, ElemType e2)
{
	return (e1 == e2);
}

int LocateElem_Sq(SqList Sq, ElemType e)
{
	/*
	int i = 0;
	while (i < Sq.length && !Compare(e, Sq.elem[i], i)) i++;
	return(i >= Sq.length ? 0 : i+1);
	*/

	int i = 1;
	ElemType* p = Sq.elem;
	while (i <= Sq.length && !Compare(*p++, e)) i++;
	return(i <= Sq.length? i : 0);
}

bool MergeList_Sq(SqList SqA, SqList SqB, SqList& SqC)
{
	ElemType *pa = SqA.elem, *pb = SqB.elem, *pc = NULL;
	pc = SqC.elem = (ElemType*)malloc((SqA.listSize + SqB.listSize) * sizeof(ElemType));
	if (NULL == pc)return ERROR;

	SqC.length = SqC.listSize  = SqA.length + SqB.length;

	while (pa <= &SqA.elem[SqA.length - 1] && pb <= &SqB.elem[SqB.length - 1])
	{
		if (*pa < * pb) *pc++ = *pa++;
		else *pc++ = *pb++;
	}

	while ( pa <= &SqA.elem[SqA.length - 1])*pc++ = *pa++;
	while (pb <= &SqB.elem[SqB.length - 1])*pc++ = *pb++;

	return OK;
}

void printSq(SqList Sq, const std::string& title)
{
	std::cout << title << ":" << std::endl;
	if (ListEmpty(Sq))printf("empty sequence!\n");
	for (int i = 0; i < Sq.length; i++)
		printf("Sq.elem[%2d] :addre: %p, value:%c (%2d)\n", i, &Sq.elem[i], Sq.elem[i], Sq.elem[i]);
	printf("length:%d\n", Sq.length);
	printf("\n\n");
}