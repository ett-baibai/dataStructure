#include "train.h"
#include "dynamicSequence.h"
#include "linkList.h"

static void InsertSq_2_29(SqList &La, SqList &Lb, SqList &Lc)
{
	InitList_Sq(La);
	InitList_Sq(Lb);
	InitList_Sq(Lc);

	ElemType arrA[] = { 1, 2, 3 };
	ElemType arrB[] = { 4, 5, 6 };
	ElemType arrC[] = { 7, 8, 8 };
	for (int i = 0; i < sizeof(arrA) / sizeof(ElemType); i++)
	{
		ListInsert_Sq(La, La.length + 1, arrA[i]);
	}
	for (int i = 0; i < sizeof(arrB) / sizeof(ElemType); i++)
	{
		ListInsert_Sq(Lb, Lb.length + 1, arrB[i]);
	}
	for (int i = 0; i < sizeof(arrC) / sizeof(ElemType); i++)
	{
		ListInsert_Sq(Lc, Lc.length + 1, arrC[i]);
	}

	printSq(La, "La");
	printSq(Lb, "Lb");
	printSq(Lc, "Lc");
}

static bool DiscardSameElemSq_2_29(SqList &S, const std::string title)
{
	if (S.length <= 1)return ERROR;
	ElemType e = S.elem[0];
	for (int i = 1; i < S.length;)
	{
		if (e == S.elem[i])
		{
			for (int j = i; j < S.length - 1; j++)
				S.elem[j] = S.elem[j + 1];	
			S.length--;
		}
		else
		{
			e = S.elem[i]; 
			i++;
		}
	}
	printSq(S, title);
	return OK;
}

static bool GetSameSq_2_29(SqList &B, SqList &C)
{
	int i = 0, j = 0, k = 0;
	while (i < B.length && j < C.length)
	{
		if (B.elem[i] == C.elem[j])
		{
			i++;
			j++;
		}
		else if (B.elem[i] < C.elem[j])
		{
			for (k = i; k < B.length - 1; k++)
			{
				B.elem[k] = B.elem[k + 1];
			}
			B.length--;
		}
		else
		{
			j++;
		}
	}
	if (j == C.length && i < B.length)
	{
		B.length = i + 1;
	}
	printSq(B, "same");
	return OK;
}

static void deleteSameSq_2_29(SqList& A, SqList B)
{
	int i = 0, j = 0, k = 0;

	while (i < A.length && j < B.length)
	{
		if (A.elem[i] == B.elem[j])
		{
			for (k = i; k < A.length - 1; k++)
			{
				A.elem[k] = A.elem[k + 1];
			}
			A.length--;
			j++;
		}
		else if (A.elem[i] < B.elem[j])
		{
			i++;
		}
		else
		{
			j++;
		};
	}
	printSq(A, "La");
}

void Train_2_29()
{
	SqList La, Lb, Lc;
	printf("####insert:\n");
	InsertSq_2_29(La, Lb, Lc);
	printf("####discard same elem:\n");
	DiscardSameElemSq_2_29(La, "La");
	DiscardSameElemSq_2_29(Lb, "Lb");
	DiscardSameElemSq_2_29(Lc, "Lc");
	printf("####get same between:\n");
	GetSameSq_2_29(Lb, Lc);
	printf("####delete elem:\n");
	deleteSameSq_2_29(La, Lb);

	DestroyList(La);
	DestroyList(Lb);
	DestroyList(Lc);
}



static void InsertL_2_30(LinkList &A, LinkList& B, LinkList&C)
{
	InitList_L(A);
	InitList_L(B);
	InitList_L(C);

	ElemType arrA[] = { 1, 1, 1, 2, 3 ,4 };
	ElemType arrB[] = {2,4,7,9};// { 0, 1, 1, 2, 4, 4 };
	ElemType arrC[] = {1,2,7,8};// { 1, 2, 2, 3, 3, 4 };
	for (int i = 0; i < sizeof(arrA) / sizeof(ElemType); i++)
	{
		ListInsert_L(A, i+1, arrA[i]);
	}
	for (int i = 0; i < sizeof(arrB) / sizeof(ElemType); i++)
	{
		ListInsert_L(B, i + 1, arrB[i]);
	}
	for (int i = 0; i < sizeof(arrC) / sizeof(ElemType); i++)
	{
		ListInsert_L(C, i + 1, arrC[i]);
	}
}

static bool DiscardSameElemL_2_30(LinkList &L)
{
	if (L->data == NULL)return ERROR;
	LNode* P = L->next, * Q = P->next;
	ElemType e = P->data;
	while (Q)
	{
		if (e == Q->data)
		{
			P->next = Q->next;
			free(Q);
			Q = P->next;
		}
		else
		{
			e = Q->data; 
			P = Q;
			Q = Q->next;
		}
	}
	return OK;
}

static bool GetSameL_2_30(LinkList& B, LinkList& C)
{
	if (!B->next || !C->next)return ERROR;
	LNode* PB = B, * QB = B->next, *QC = C->next;
	while (QB && QC)
	{
		if (QB->data == QC->data)
		{
			PB = QB;
			QB = QB->next;
		}
		else if(QB->data < QC->data)
		{
			QB = QB->next;
			free(PB->next);
			PB->next = QB;
		}
		else
		{
			QC = QC->next;
		}
	}
	if (QB && !QC)
	{
		while (QB)
		{
			QB = QB->next;
			free(PB->next);
			PB->next = QB;
		}
	}
	return OK;
}

static bool deleteSameL_2_30(LinkList &A, LinkList &B)
{
	if (!A->next || !B->next)return ERROR;
	LNode *PA = A, *QA = A->next, *QB = B->next;
	while (QA && QB)
	{
		if (QA->data == QB->data)
		{
			QA = QA->next;
			free(PA->next);
			PA->next = QA;
			QB = QB->next;
		}
		else if (QA->data < QB->data)
		{
			PA = QA;
			QA = QA->next;
		}
		else
		{
			QB = QB->next;
		}
	}
	return OK;
}

void Train_2_30()
{
	// A B C三个链表的值域按非递减顺序排列（可能有相同元素），删除A中BC都有的元素
	LinkList La, Lb, Lc;
	printf("####insert:\n");
	InsertL_2_30(La, Lb, Lc);
	printL(La, "La");
	printL(Lb, "Lb");
	printL(Lc, "Lc");

	printf("####discard same elem in Lb and Lc:\n");
	DiscardSameElemL_2_30(La);
	DiscardSameElemL_2_30(Lb);
	DiscardSameElemL_2_30(Lc);
	printL(La, "La");
	printL(Lb, "Lb");
	printL(Lc, "Lc");

	printf("####get same between Lb and Lc:\n");
	GetSameL_2_30(Lb, Lc);
	printL(Lb, "common");
	printf("####delete elem in La who is same with Lb :\n");
	deleteSameL_2_30(La, Lb);
	printL(La, "La");

	DestoryList_L(La);
	DestoryList_L(Lb);
	DestoryList_L(Lc);	
}