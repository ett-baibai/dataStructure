#pragma once
#include "typedef.h"
#include <iostream>

typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

void InitQueue_L(LinkQueue& L);
void DestroyQueue_L(LinkQueue& L);
void ClearQueue_L(LinkQueue& L);
bool QueueEmpty_L(LinkQueue L);
int QueueLength_L(LinkQueue L);
bool GetQueueHead_L(LinkQueue L, QElemType& e);
bool EnQueue_L(LinkQueue& L, QElemType e);
bool DeQueue_L(LinkQueue& L, QElemType& e);
void printQueueL(LinkQueue L, const std::string& title);