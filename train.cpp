#include "train.h"
#include <stdio.h>
#include <iostream>
#include "dynamicSequence.h"
#include "linkList.h"
#include "stackSequence.h"
#include "stackLinkList.h"
#include "queueLinkList.h"

using namespace std;

static bool DeleteK(SqList &a, int i, int k)
{
	if (i < 1 || k<0 || i + k + 1>a.length)return ERROR;
	else
	{
		int num = a.length - i - k + 1;
		for (int count = 0; count < num; count++)
		{
			a.elem[i - 1] = a.elem[i - 1 + k];
			printf("a.elem[%d] = a.elem[%d] = %d\n", i - 1, i - 1 + k, a.elem[i - 1 + k]);
			i++;
		}
		a.length -= k;
		return OK;
	}
}

void Train_2_10()
{
	SqList Sq;
	InitList_Sq(Sq);
	ElemType e = 1;
	for (int i = 0; i < 10; i++)
	{
		ListInsert_Sq(Sq, i+1, e);
		e++;
	}
	printSq(Sq, "Sq1");

	if (!DeleteK(Sq, 3, 2))printf("执行失败");
	else printSq(Sq, "Sq2");
	DestroyList(Sq);
}





static bool Insert_2_11(SqList& L, ElemType x)
{
	if (L.length >= L.listSize)
	{
		ElemType* newBase = (ElemType*)realloc(L.elem, (L.listSize + LIST_INCREASE) * sizeof(ElemType));
		if (NULL == newBase)return ERROR;
		L.elem = newBase;
		L.listSize += LIST_INCREASE;
	}

	int index = 0;
	for (; index < L.length; index++)
	{
		if (index == 0)
		{
			if (x <= L.elem[0])break;
		}
		else
		{
			if (x >= L.elem[index - 1] && x <= L.elem[index])break;
		}
	}
	int j = L.length;
	for (; j > index; j--)
	{
		L.elem[j] = L.elem[j - 1];
	}
	L.elem[j] = x;
	L.length += 1;
	return OK;
}

void Train_2_11()
{
	SqList Va;
	InitList_Sq(Va);
	ElemType e = 1;
	for (int i = 0; i < 10; i++)
	{
		ListInsert_Sq(Va, i + 1, e);
		e++;
	}
	Va.elem[3] = 5;
	printSq(Va, "Va1");

	if (!Insert_2_11(Va, 5))printf("执行失败");
	else printSq(Va, "Va2");
	DestroyList(Va);
}





static void Compare_2_12(SqList A, SqList B)
{
	int i = 0, j = 0;
	for (;i<A.length&&j<B.length; i++, j++)
	{
		if (A.elem[i] > B.elem[j])
		{
			printf("A>B\n");
			return;
		}
		else if (A.elem[i] < B.elem[j])
		{
			printf("A<B\n");
			return;
		}
	}

	if (i == A.length && j == B.length)
	{
		printf("A=B\n");
		return;
	}
	else if (i == A.length && j < B.length)
	{
		printf("A<B\n");
		return;
	}
	else
	{
		printf("A>B\n");
		return;
	}
}

void Train_2_12()
{
	SqList A, B;
	InitList_Sq(A);
	InitList_Sq(B);
	ElemType e = 1;
	for (int i = 0; i < 10; i++)
	{
		ListInsert_Sq(A, i + 1, e);
		ListInsert_Sq(B, i + 1, e);
		e++;
	}
	//B.elem[B.length - 1] += 1;
	//B.elem[0] -= 1;
	B.length -= 1;
	printSq(A, "A");
	printSq(B, "B");

	Compare_2_12(A, B);
	
	DestroyList(A);
	DestroyList(B);
}





static int Locate(LinkList L, ElemType x)
{
	LNode* p = L;
	int index = 0;
	while (p->next)
	{
		p = p->next;
		index++;
		if (x == p->data)return index;
	}
	return ERROR;
}

void Train_2_13()
{
	LinkList L;
	InitList_L(L);
	ElemType e = 1;
	for (int i = 1; i < 6; i++)
	{
		if (!ListInsert_L(L, i, e))printf("loop insert error, index = %d\n", i);
		e++;
	}
	printL(L, "L");
	ElemType target = 15;
	int index = Locate(L, target);
	printf("target:%d, index = %d\n", target, index);
	DestoryList_L(L);
}





static void Connect(LinkList& ha, LinkList& hb, LinkList &hc, int m, int n)
{
	LNode* p = hc = m > n ? hb : ha;
	while (p->next)
	{
		p = p->next;
	}
	p->next = m > n ? ha->next : hb->next;
	if (m > n)
	{
		free(ha);
		ha = NULL;
	}
	else
	{
		free(hb);
		hb = NULL;
	}
}

void Train_2_15()
{
	LinkList La, Lb, Lc;
	InitList_L(La);
	InitList_L(Lb);
	ElemType e = 1;
	int i = 1;
	for (; i < 6; i++)
	{
		if (!ListInsert_L(La, i, e) || !ListInsert_L(Lb, i, e))printf("loop insert error, index = %d\n", i);
		e++;
	}
	for (; i < 11; i++)
	{
		if (!ListInsert_L(La, i, e))printf("loop insert error, index = %d\n", i);
		e++;
	}
	printL(La, "La");
	printL(Lb, "Lb");
	Connect(La, Lb, Lc, GetLinkListLength(La), GetLinkListLength(Lb));
	printL(La, "La");
	printL(Lb, "Lb");
	printL(Lc, "Lc");
	DestoryList_L(La);
	DestoryList_L(Lb);	
}





static bool Delete_2_19(LinkList &L, ElemType mink, ElemType maxk)
{
	LNode* P = L, * Q = L->next, * S = NULL;
	while(Q)
	{
		if (Q->data > mink)
		{
			if (Q->data < maxk)
			{
				S = Q;
				Q = Q->next;
				free(S);
			}
			else break;
		}
		else
		{
			P = Q;
			Q = Q->next;
		}
	}
	if (P->next == Q)return ERROR;
	else P->next = Q;
	return OK;
}

void Train_2_19()
{
	LinkList L;
	InitList_L(L);
	ElemType e = 1;
	for (int i = 1; i < 11; i++)
	{
		if (!ListInsert_L(L, i, e))printf("loop insert error, index = %d\n", i);
		e++;
	}
	printL(L, "L");
	int mink = 15, maxk = 11;
	Delete_2_19(L, mink, maxk);
	printL(L, "L");
	
	DestoryList_L(L);
}





static bool Delete_2_20(LinkList& L)
{
	LNode* P = L, * Q = L->next;
	ElemType sameValue = 0;
	if (!Q)return OK;
	else sameValue = Q->data + 1;//加1是为了保证sameValue和第一个结点的值不一样
	
	while (Q)
	{
		if (sameValue == Q->data)
		{
			Q = Q->next;
			free(P->next);
			P->next = Q;
		}
		else
		{
			sameValue = Q->data;
			P = Q;
			Q = Q->next;
		}
	}
	return OK;
}

void Train_2_20()
{
	LinkList L;
	InitList_L(L);
	ElemType e = 1;
	for (int i = 1; i < 11; i++)
	{
		if (!ListInsert_L(L, i, e/2))printf("loop insert error, index = %d\n", i);
		e++;
	}
	printL(L, "L");
	Delete_2_20(L);
	printL(L, "L");

	DestoryList_L(L);
}





static void Reverse_2_21(SqList& Sq)
{
	ElemType p = 0;
	for (int i = 0; i < Sq.length/2; i++)
	{
		p = Sq.elem[i];
		Sq.elem[i] = Sq.elem[Sq.length - i - 1];
		Sq.elem[Sq.length - i - 1] = p;
	}
}

void Train_2_21()
{
	SqList Sq;
	InitList_Sq(Sq);
	ElemType e = 1;
	for (int i = 0; i < 15; i++)
	{
		ListInsert_Sq(Sq, i + 1, e);
		e++;
	}
	printSq(Sq, "Sq1");

	Reverse_2_21(Sq);
	printSq(Sq, "Sq2");

	DestroyList(Sq);
}





static bool Reverse_2_22_24(LinkList& L)
{
	if (L->next == NULL)return OK;
	LNode* P = L->next, * Q = P->next, *S = NULL;
	while(Q)
	{
		S = Q;
		Q = Q->next;
		S->next = P;
		P = S;
	}
	L->next->next = NULL;
	L->next = P;
	return OK;
}

void Train_2_22()
{
	LinkList L;
	InitList_L(L);
	ElemType e = 1;
	for (int i = 1; i < 3; i++)
	{
		if (!ListInsert_L(L, i, e))printf("loop insert error, index = %d\n", i);
		e++;
	}
	printL(L, "L1");
	Reverse_2_22_24(L);
	printL(L, "L2");

	DestoryList_L(L);
}





static void MergeList_2_23(LinkList& A, LinkList& B, LinkList& C)
{
	LNode* PA = A, *QA = A->next, *PB = B, *QB = B->next;
	while(QA && QB)
	{
		PA = QA;
		QA = QA->next;

		PB = QB;
		QB = QB->next;

		PA->next = PB;
		PB->next = QA;
	}
	if (!QA && QB)PB->next = QB;//A空B不空
	
	C = A; B->next = NULL;
}

void Train_2_23()
{
	LinkList La, Lb, Lc;
	InitList_L(La);
	InitList_L(Lb);
	ElemType e = 1;
	int i = 1;
	for (; i < 6; i++)
	{
		if (!ListInsert_L(La, i, e) || !ListInsert_L(Lb, i, e))printf("loop insert error, index = %d\n", i);
		e++;
	}
	for (; i < 11; i++)
	{
		if (!ListInsert_L(Lb, i, e))printf("loop insert error, index = %d\n", i);
		e++;
	}
	printL(La, "La");
	printL(Lb, "Lb");
	MergeList_2_23(La, Lb, Lc);
	
	printL(Lc, "Lc");
	DestoryList_L(La);
	DestoryList_L(Lb);
}





static bool MergeList_2_24(LinkList& A, LinkList& B, LinkList& C)
{
	if (!A->next && !B->next)return ERROR;
	if (!A->next && B->next)
	{
		C = B;
		return OK;
	}
	if (A->next && !B->next)
	{
		C = A;
		return OK;
	}
	LNode* PA = A, * QA = A->next, * PB = B, * QB = B->next;
	while (QA && QB)
	{
		if (QA->data > QB->data)
		{
			PB = QB;
			QB = QB->next;
			PA->next = PB;
			PB->next = QA;
			PA = PB;
		}
		else
		{
			PA = QA;
			QA = QA->next;
		}
	}
	if(!QA) PA->next = QB;
	C = A; 
	B->next = NULL;
	return OK;
}

void Train_2_24()
{
	LinkList La, Lb, Lc;
	InitList_L(La);
	InitList_L(Lb);
	ElemType e1 = 1, e2 = 3;
	int i = 1, j =1;
	for (; i < 6; i++)
	{
		if (!ListInsert_L(La, i, e1))printf("loop insert error, index = %d\n", i);
		e1++;
	}
	for (; j < 6; j++)
	{
		if (!ListInsert_L(Lb, j, e2))printf("loop insert error, index = %d\n", i);
		e2++;
	}
	
	printL(La, "La");
	printL(Lb, "Lb");
	if (!MergeList_2_24(La, Lb, Lc))printf("La Lb 均为空链表\n");
	else
	{
		Reverse_2_22_24(Lc);
		printL(Lc, "Lc");
	}
	DestoryList_L(La);
	DestoryList_L(Lb);
}





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





static void ditui_3_9(int n)
{
	/*
	int i = n;
	while (i > 1)
		printf("%d ", i--);
	printf("\n");
	*/

	if (n > 1)
	{
		printf("%d ", n);
		ditui_3_9(n-1);
	}
}

void Train_3_9()
{
	ditui_3_9(5);
}




static void test_3_10(int& sum)
{
	/*
	int x;
	scanf_s("%d", &x);
	if (x == 0)sum = 0;
	else
	{
		test_3_10(sum);
		sum += x;
	}
	printf("%d\n", sum);
	*/
	int x = -1;
	while (1)
	{
		scanf_s("%d", &x);
		if (x == 0)break;
		else
		{
			printf("%d\n", sum);
			sum += x;
		}
	}
	printf("%d\n", sum);
}

void Train_3_10()
{
	int sum = 0;
	test_3_10(sum);
}





static void fun_3_21(LinkQueue &Q)
{
	SqStack S; SElemType x, y;
	InitStack_Sq(S);
	int length = QueueLength_L(Q);

	for (int i = 0; i < length; i++)
	{
		DeQueue_L(Q, x);
		if (x > 'a' && x < 'z')EnQueue_L(Q,x);
		else
		{
			if (!GetPop_Sq(S, y))
			{
				Push_Sq(S,x);
				continue;
			}
			if (y == '+' || y == '-')
			{
				if (x == '+' || x == '-')
				{
					Pop_Sq(S, y);
					EnQueue_L(Q, y);
					Push_Sq(S, x);
				}
				else Push_Sq(S, x);
			}
			else
			{
				Pop_Sq(S, y);
				EnQueue_L(Q, y);
				Push_Sq(S, x);
			}
		}
	}

	while (!StackEmpty_Sq(S))
	{
		Pop_Sq(S, y);
		EnQueue_L(Q, y);
	}
	DestroyStack_Sq(S);
}

void Train_3_21()
{
	LinkQueue L;
	InitQueue_L(L);
	const QElemType exp[] = { 'a', '*', 'b', '-', 'c', '+', 'd', '/', 'e'};
	for (int i = 0; i < sizeof(exp) / sizeof(QElemType); i++)
		if (!EnQueue_L(L, exp[i]))printf("EnQueue_L error!\n");
	printQueueL(L, "L");

	fun_3_21(L);
	printQueueL(L, "L");
	DestroyQueue_L(L);	
}





static int g_3_24(int& m, int& n)
{
	static int i = 1;
	int s = 0;
	if (m > 0)
	{
		m -= 1;
		n *= 2;
		printf("i = %d,m = %d, n = %d\n", i, m, n);
		i++;
		s = g_3_24(m, n) + n;
	}
	i--;
	printf("i = %d,m = %d, n = %d, return s = %d\n", i, m, n, s);
	return s;
}

void Train_3_24()
{
	int m = 5, n = 2;
	g_3_24(m, n);
}





static int Fn_3_25_1(int &n)
{
	int s = 0, p = 0;
	if (n == 0)s = n + 1;
	else
	{
		p = n / 2;
		s = n * Fn_3_25_1(p);
	}
	printf("s = %d\n", s);

	return s;
}

static void Fn_3_25_2(int n)
{
	int s = n;
	while (n != 0 && n/2 !=0)
	{
		s = s * (n / 2);
		n = n / 2;
	}
	printf("s = %d\n", s);
}

void Train_3_25()
{
	int n = 5;
	int m = n;
	Fn_3_25_1(n);
	printf("\n\n");
	Fn_3_25_2(m);
}





static bool Compare_3_31(LinkQueue Q)
{
	SqStack S; int queueLength = 0; QElemType e = 0, x = 0;
	InitStack_Sq(S);
	queueLength = QueueLength_L(Q) - 1;

	for (int i = 0; i < queueLength; i++)
	{
		DeQueue_L(Q, e);
		if (i < queueLength / 2)Push_Sq(S, e);
		else if (queueLength % 2 != 0 && i == queueLength / 2);
		else
		{
			Pop_Sq(S, x);
			if (x != e)return ERROR;
		}
	}
	DestroyStack_Sq(S);
	return OK;
}

void Train_3_31()
{
	const SElemType expression[] ={'b','c','b','a','#'};
	LinkQueue L;
	InitQueue_L(L);
	for (int i = 0; i < sizeof(expression) / sizeof(SElemType); i++)
		if (!EnQueue_L(L, expression[i]))printf("EnQueue_L error!\n");
	printQueueL(L, "L");

	if (Compare_3_31(L))
		printf("yes\n");
	else
		printf("no\n");
}





void Practice_3_2_2_CheckOfBrackets()
{
	SElemType e = 0, bracket[] = {'{', '}','[', ']'};
	SqStack S;
	InitStack_Sq(S);

	bool flag = 1;
	int i = 0, length = sizeof(bracket) / sizeof(SElemType);
	while (i < length)
	{
		if (bracket[i] == '{' || bracket[i] == '[' || bracket[i] == '(')
		{
			if (!Push_Sq(S, bracket[i]))
			{
				printf("内存不足，入栈失败\n");
				flag = 0;
				break;
			}
		}
		else if (bracket[i] == '}' || bracket[i] == ']' || bracket[i] == ')')
		{
			if (!Pop_Sq(S, e))
			{
				printf("栈已空，右括号有剩余\n");
				flag = 0;
				break;
			}
			if(!((e == '{' && bracket[i] == '}') || 
				 (e == '[' && bracket[i] == ']') || 
				 (e == '(' && bracket[i] == ')')))
			{
				printf("括号匹配失败\n");
				flag = 0;
				break;
			}
		}
		else
		{
			printf("\'%c\'不是括号字符\n", bracket[i]);
			flag = 0;
			break;
		}
		i++;
	}
	if (flag)
	{
		if (StackEmpty_Sq(S))printf("total:括号匹配成功\n");
		else printf("左括号有剩余\n");
	}

	DestroyStack_Sq(S);
}






//字符是否合法 () + - * / 0~9 #
static bool IsOperaValid(const char c)
{
	return ((c >= 40 && c <= 57 && c != 44 && c != 46) || c == '#');
}

//读取到的符号是否为数字
static bool IsOperand(const char c)
{
	return (c >= 48 && c <= 57);
}

static bool HandleOperand(StackLinkList& Operand, ElemType& operand)
{
	if (-1 != operand)
	{
		if (!Push_L(Operand, operand))
		{
			printf("数据入栈失败\n");
			return ERROR;
		}
		operand = -1;
	}
	return OK;
}

static bool CalculateStep(SqStack& Operator, StackLinkList& Operand, const SElemType c)
{
	ElemType firstOperand = 0, lastOperand = 0;
	SElemType p = 0;
	if (!Pop_L(Operand, lastOperand) || !Pop_L(Operand, firstOperand) || !Pop_Sq(Operator, p))
	{
		printf("计算数据时，出栈失败\n");
		return ERROR;
	}
	ElemType result = 0;
	switch (p)
	{
	case '+':
		result = firstOperand + lastOperand;
		break;

	case '-':
		result = firstOperand - lastOperand;
		break;

	case '*':
		result = firstOperand * lastOperand;
		break;

	case '/':
		result = firstOperand / lastOperand;
		break;

	default:
		printf("计算数据时，有未知符号\n");
		return ERROR;
	}

	if (c != ')' && c != '#')
	{
		if (!Push_Sq(Operator, c))
		{
			printf("计算数据后，符号入栈失败\n");
			return ERROR;
		}
	}
	if (!Push_L(Operand, result))
	{
		printf("计算数据后，数据入栈失败\n");
		return ERROR;
	}
	else return OK;
}

static bool HandleOperationLeftBracket(SqStack& Operator, const SElemType c)
{
	if (!Push_Sq(Operator, c))
	{
		printf("处理四则运算左括号时，入栈失败\n");
		return ERROR;
	}
	return OK;
}

static bool HandleOperationPlusAndSubtraction(SqStack& Operator, StackLinkList& Operand, const SElemType c)
{
	if (c == '+' || c == '-' )
	{
		if (!CalculateStep(Operator, Operand, c))return ERROR;
	}
	else if(c == '*' || c == '/')
	{
		if (!Push_Sq(Operator, c))
		{
			printf("处理四则运算加减法时，入栈失败\n");
			return ERROR;
		}
	}
	return OK;
}

static bool HandleOperation(SqStack& Operator, StackLinkList& Operand, const SElemType c)
{
	SElemType p = 0;
	GetPop_Sq(Operator, p);
	switch (p)
	{
	case 0: //栈空
	case '(':
		if (!HandleOperationLeftBracket(Operator, c))return ERROR;
		break;

	case '+':
	case '-':
		if (!HandleOperationPlusAndSubtraction(Operator, Operand, c))return ERROR;
		break;

	case '*':
	case '/':
		if (!CalculateStep(Operator, Operand, c))return ERROR;
		break;

	default:
		printf("处理四则运算时,错误符号: \'%c\'\n", c);
		return ERROR;
	}
	return OK;
}

static bool HandleRightBracket(SqStack& Operator, StackLinkList& Operand, const SElemType c)
{
	SElemType p = 0;
	if (!GetPop_Sq(Operator, p))
	{
		printf("处理右括号时，读取符号失败\n");
		return ERROR;
	}

	while (p != '(')
	{
		if (!CalculateStep(Operator, Operand, c))return ERROR;
		if (!GetPop_Sq(Operator, p))
		{
			printf("处理右括号时，读取符号失败\n");
			return ERROR;
		}
	}
	Pop_Sq(Operator, p);//弹出左括号
	return OK;
}

static bool HandleOpertor(SqStack& Operator, StackLinkList& Operand, const SElemType c)
{
	switch (c)
	{
	case '(':
		if (!Push_Sq(Operator, c))
		{
			printf("处理\'(\'符号时，入栈失败\n");
			return ERROR;
		}
		break;

	case ')':
		if(!HandleRightBracket(Operator, Operand, c))return ERROR;
		break;

	case '+':
	case '-':
	case '*':
	case '/':
		if(!HandleOperation(Operator, Operand, c))return ERROR;
		break;

	case '#':
		break;

	default:
		printf("错误符号: \'%c\'\n", c);
		return ERROR;
	}
	return OK;
}

static void HandleOpera(SqStack& Operator, StackLinkList& Operand, const SElemType c)
{
	static ElemType operand = -1;
	if (IsOperand(c))//读到数字
	{
		if (-1 == operand)operand = 0;
		operand = operand * 10 + c - 48;
	}
	else
	{
		if (!HandleOperand(Operand, operand))return;
		if (!HandleOpertor(Operator, Operand, c))return;
	}
}

static bool GetResult(SqStack& Operator, StackLinkList& Operand)
{
	while (GetStackLength_Sq(Operator) != 0)
	{
		if (!CalculateStep(Operator, Operand, '#'))return ERROR;
	}
	ElemType result = 0;
	if (!Pop_L(Operand, result))
	{
		printf("获取计算结果时，出栈失败\n");
		return ERROR;
	}
	else
	{
		printf("result = %d\n", result);
		return OK;
	}
}

static void ShowExpression(const SElemType *ex, int num)
{
	for (int i = 0; i < num - 1; i++)
		printf("%c", ex[i]);
	printf("\n\n");
}

static void Calculate(SqStack& Operator, StackLinkList& Operand, const SElemType *ex, int num)
{
	ShowExpression(ex, num);
	for (int i = 0; i < num; i++)
	{
		if (!IsOperaValid(ex[i]))
		{
			printf("第%d个字符 \'%c\' 不合法\n", i+1,ex[i]);
			return;
		}
		HandleOpera(Operator, Operand, ex[i]);
	}
	GetResult(Operator, Operand);
}

static int GetExpression(SElemType **ex)
{
	printf("输入表达式：\n");
	string exp;
	cin >> exp;
	int len = exp.length();
	*ex = (SElemType*)malloc((len + 1) * sizeof(SElemType));
	const char *cex = exp.c_str();
	for (int i = 0; i < len-1; i++)
	{
		if (!IsOperaValid(cex[i]))
		{
			printf("第%d个字符 \'%c\' 不合法\n", i + 1, cex[i]);
			exit(ERROR);
		}
		//*ex[i] = cex[i];
		else printf("%c\n", cex[i]);
	}
	//*ex[len] = '#';
	return len;
}

void Practice_3_2_2_InfixExpressionEvaluation()
{
	/*
	const SElemType expression[] =
	{ 
		'(', '(', '1', '5', '/', '(', '7', '-', '(', '1', '+', '1', ')', ')', ')',
		'*', '3', ')' ,'-', '(', '6', '*', '2', '0', '/', '(', '2', '+', '3', '*', '4', ')', ')','#'
	};
	*/
	SElemType *expression = NULL;

	int length = GetExpression(&expression);

	SqStack Operator;
	InitStack_Sq(Operator);
	StackLinkList Operand;
	InitStack_L(Operand);

	//Calculate(Operator, Operand, expression, length);

	DestroyStack_L(Operand);
	DestroyStack_Sq(Operator);
	free(expression);
}





static int MatchPoorly_1(SqList S, SqList T)
{
	int i = 0, j = 0, k = 0;
	while (i < S.length && j < T.length)
	{
		if (S.elem[i] == T.elem[j])
		{
			i++;
			j++;
		}
		else
		{
			k++;
			j = 0;
			i = k;
		}
	}
	if (j >= T.length)return k+1;
	else return 0;
}

static int MatchPoorly_2(SqList S, SqList T)
{
	int i = 0, j = 0;
	while (i < S.length && j < T.length)
	{
		if (S.elem[i] == T.elem[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
			
		}
	}
	if (j >= T.length)return i + 1 - T.length;
	else return 0;
}

static void GetNext(int *next, int len)
{
	next[0] = -1;
	next[1] = 0;
	next[2] = 0;
	next[3] = 0;
	next[len-1] = 0;
}

static int Match_KMP(SqList S, SqList T)
{
	int* next = (int*)malloc(T.length * sizeof(int));
	if (!next)return 0;
	GetNext(next, T.length);

	int i = 0, j = 0;
	while (i < S.length && j < T.length)
	{
		if (j == -1)
		{
			i++;
			j++;
			continue;
		}
		if (S.elem[i] == T.elem[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	free(next);
	if (j >= T.length)return i + 1 - T.length;
	else return 0;
}

void Practice_4_3_MatchPatternString()
{
	const char cS[] = { 'd','a','t','u','c','t','u','r', 'a',' ','s','t','r', 'u','c','t','u','r','e' };
	const char cT[] = { 'c','t','u','r','e' };
	SqList S, T;
	InitList_Sq(S);
	InitList_Sq(T);
	for (int i = 0; i < sizeof(cS) / sizeof(ElemType); i++)
	{
		if (!ListInsert_Sq(S, i + 1, cS[i]))
		{
			printf("入队失败\n");
			break;
		}
	}
	for (int j = 0; j < sizeof(cT) / sizeof(ElemType); j++)
	{
		if (!ListInsert_Sq(T, j + 1, cT[j]))
		{
			printf("入队失败\n");
			break;
		}
	}
	printSq(S, "S");
	printSq(T, "T");
	printf("MatchPoorly_1: %d\n", MatchPoorly_1(S, T));
	printf("MatchPoorly_2: %d\n", MatchPoorly_2(S, T));
	printf("Match_KMP:     %d\n", Match_KMP(S, T));
	DestroyList(S);
	DestroyList(T);
}