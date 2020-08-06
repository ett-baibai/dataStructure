#include "queueLinkList.h"

void InitQueue_L(LinkQueue& L)
{
	L.front = L.rear = (QNode*)malloc(sizeof(QNode));
	if (!L.front)exit(OVER_FLOW);
	L.rear->next = NULL;
}

void DestroyQueue_L(LinkQueue& L)
{
	if (!L.front || !L.rear)return;

	QNode* deleteNode = L.front->next;
	while (deleteNode)
	{
		L.front->next = deleteNode->next;
		free(deleteNode);
		deleteNode = L.front->next;
	}
	free(L.front);
	L.front = NULL;
}

void ClearQueue_L(LinkQueue& L)
{

}

bool QueueEmpty_L(LinkQueue L)
{
	return (L.front == L.rear);
}

int QueueLength_L(LinkQueue L)
{
	return OK;
}

bool GetQueueHead_L(LinkQueue L, QElemType& e)
{
	return OK;
}

bool EnQueue_L(LinkQueue& L, QElemType e)
{
	QNode* p = (QNode*)malloc(sizeof(QNode));
	if (!p)return ERROR;

	p->data = e;
	p->next = NULL;
	L.rear->next = p;
	L.rear = p;
	return OK;
}

bool DeQueue_L(LinkQueue& L, QElemType& e)
{
	if (QueueEmpty_L(L))return ERROR;
	QNode* p = L.front->next;
	e = p->data;
	L.front->next = p->next;
	if (L.rear == p)L.rear = L.front;//the last one element dequeue
	free(p);
	return OK;
}

void printQueueL(LinkQueue L, const std::string& title)
{
	std::cout << "单链队列" << title << ":" << std::endl;
	if (QueueEmpty_L(L))
	{
		printf("空队列\n");
		return;
	}
	printf("队头 ---> 队尾\n");
	QNode* showNode = L.front->next;
	int i = 0;
	while (showNode)
	{
		printf("StackNode%2d :addr: %p, value:%d\n", i, showNode, showNode->data);
		showNode = showNode->next;
		i++;
	}
	printf("length:%d\n", i);
	printf("\n\n");
}
