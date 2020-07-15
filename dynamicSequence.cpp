#include "dynamicSequence.h"
#include <stdlib.h>
#include <stdio.h>
bool InitList_Sq(SqList& L)
{
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)exit(OVER_FLOW);
	L.length = 0;
	L.listSize = LIST_INIT_SIZE;
	return OK;
}

void DestroyList(SqList &L)
{
	free(L.elem);
	L.elem = NULL;
}

bool ListEmpty(SqList L)
{
	return (0 == L.length);
}

bool InsertFirstElem(SqList &L, int i, ElemType e)
{
	if (i != 1)
		return ERROR;
	L.elem[0] = e;
	L.length++;
	return OK;
}

bool ListInsert_Sq(SqList &L, int i, ElemType e)
{
	if (i < 1 || i > L.length + 1) return ERROR;

	if (L.length >= L.listSize)
	{	
		ElemType* newBase = (ElemType*)realloc(L.elem, (L.listSize + LIST_INCREASE) * sizeof(ElemType));
		if (NULL == newBase)return ERROR;
		L.elem = newBase;
		L.listSize += LIST_INCREASE;
		
/*
		ElemType* newBase = (ElemType*)malloc((L.listSize + LIST_INCREASE) * sizeof(ElemType));
		if (NULL == newBase)return ERROR;

		for (int i = 0; i < L.length; i++)
			newBase[i] =  L.elem[i];
		free(L.elem);
		L.elem = newBase;
		L.listSize = LIST_INIT_SIZE + LIST_INCREASE;
*/
	}

/*
	for (int looper = 0; looper < L.length - i + 1; looper++)
	{
		L.elem[L.length - looper] = L.elem[L.length - looper - 1];
	}
	L.elem[i - 1] = e;
*/
	
	ElemType* q = &(L.elem[i - 1]);
	ElemType* p = &(L.elem[L.length - 1]);
	for (; p >= q; --p)
	{
		*(p+1) = *p;
		//printf("p+1:addre:%p, value: %d\np:addre:%p, value: %d\n", p+1, *(p+1), p, *p);
	}
	*q = e;

/*
	printf("index(length): %d\n", L.length+1);
	for (int ha = 0; ha <= L.length; ha++)
		printf("L.elem[%d]: addr :%p, value: %d\n", ha, &(L.elem[ha]), L.elem[ha]);
	printf("\n\n");
*/

	L.length++;
	
	return OK;
}

bool ListDelete_Sq(SqList& L, int i, ElemType& e)
{
	if (i < 1 || i > L.length)return ERROR;

	e = L.elem[i-1];

	for (int loop = 0; loop < L.length - i; loop++)
	{
		L.elem[i - 1 + loop] = L.elem[i + loop];
	}

	L.length--;
	return OK;
}

bool Compare(ElemType e1, ElemType e2)
{
	return (e1 == e2);
}

int LocateElem_Sq(SqList L, ElemType e)
{
	/*
	int i = 0;
	while (i < L.length && !Compare(e, L.elem[i], i)) i++;
	return(i >= L.length ? 0 : i+1);
	*/

	int i = 1;
	ElemType* p = L.elem;
	while (i <= L.length && !Compare(*p++, e)) i++;
	return(i <= L.length? i : 0);
}

bool MergeList_Sq(SqList La, SqList Lb, SqList& Lc)
{
	ElemType *pa = La.elem, *pb = Lb.elem, *pc = NULL;
	pc = Lc.elem = (ElemType*)malloc((La.listSize + Lb.listSize) * sizeof(ElemType));
	if (NULL == pc)return ERROR;

	Lc.length = Lc.listSize  = La.length + Lb.length;

	while (pa <= &La.elem[La.length - 1] && pb <= &Lb.elem[Lb.length - 1])
	{
		if (*pa < * pb) *pc++ = *pa++;
		else *pc++ = *pb++;
	}

	while ( pa <= &La.elem[La.length - 1])*pc++ = *pa++;
	while (pb <= &Lb.elem[Lb.length - 1])*pc++ = *pb++;

	return OK;
}

void printL(SqList L, const std::string& title)
{
	std::cout << title << ":" << std::endl;
	if (ListEmpty(L))printf("empty sequence!\n");
	for (int i = 0; i < L.length; i++)
		printf("L.elem[%d] :addre: %p, value:%d\n", i, &L.elem[i], L.elem[i]);
	printf("length:%d\n", L.length);
	printf("\n\n");
}