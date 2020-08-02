#include "ccQueueSequence.h"

void InitQueue_Sq(SqQueue& S)
{
	S.base = (QElemType*)malloc(sizeof(QElemType) * MAX_QUEUE_SIZE);
	if (!S.base)exit(OVER_FLOW);

	S.front = S.rear = 0;
}

void DestroyQueue_Sq(SqQueue& S)
{
	if (S.base)
	{
		free(S.base);
		S.base = NULL;
	}
}

void ClearQueue_Sq(SqQueue& S)
{
	S.front = S.rear = 0;
}

bool QueueEmpty_Sq(SqQueue S)
{
	return (S.front == S.rear);
}

bool QueueFull_Sq(SqQueue S)
{
	return ((S.rear + 1) % MAX_QUEUE_SIZE == S.front);
}

int  QueueLength_Sq(SqQueue S)
{
	return (S.rear - S.front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

bool GetQueueHead_Sq(SqQueue S, QElemType& e)
{
	return OK;
}

bool EnQueue_Sq(SqQueue& S, QElemType e)
{
	if (QueueFull_Sq(S))return ERROR;

	S.base[S.rear] = e;
	S.rear = (S.rear + 1) % MAX_QUEUE_SIZE;

	return OK;
}

bool DeQueue_Sq(SqQueue& S, QElemType& e)
{
	if (QueueEmpty_Sq(S))return ERROR;

	e = S.base[S.front];
	S.front = (S.front + 1) % MAX_QUEUE_SIZE;
	return OK;
}

void printQueueSq(SqQueue S, const std::string& title)
{
	std::cout << "循环顺序队列" << title << ":" << std::endl;
	if (QueueEmpty_Sq(S))
	{
		printf("空队列\n");
		return;
	}
	printf("队头 ---> 队尾\n");
	int length = QueueLength_Sq(S);
	while (S.front != S.rear)
	{
		printf("QueueNode[%2d] :addr: %p, value:%d\n", S.front, &S.base[S.front], S.base[S.front]);
		S.front = (S.front + 1) % MAX_QUEUE_SIZE;
	}
	printf("length:%d\n", length);
	printf("\n\n");
}
