#pragma once
#include "typedef.h"
#include <iostream>

#define MAX_QUEUE_SIZE  25

typedef struct
{
	QElemType* base;
	int front;
	int rear;
}SqQueue;

void InitQueue_Sq(SqQueue& S);
void DestroyQueue_Sq(SqQueue& S);
void ClearQueue_Sq(SqQueue& S);
bool QueueEmpty_Sq(SqQueue S);
bool QueueFull_Sq(SqQueue S);
int  QueueLength_Sq(SqQueue S);
bool GetQueueHead_Sq(SqQueue S, QElemType& e);
bool EnQueue_Sq(SqQueue& S, QElemType e);
bool DeQueue_Sq(SqQueue& S, QElemType& e);
void printQueueSq(SqQueue S, const std::string& title);