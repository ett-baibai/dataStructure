#pragma once
#include "typedef.h"
#include <iostream>

typedef struct StackNode
{
	SElemType value;
	struct StackNode* top;
}StackNode, * StackLinkList;

void InitStack_L(StackLinkList& L);
void DestroyStack_L(StackLinkList& L);
bool StackEmpty_L(StackLinkList L);
bool Push_L(StackLinkList& L, SElemType e);
bool GetPop_L(StackLinkList L, SElemType& e);
bool Pop_L(StackLinkList& L, SElemType& e);
void printStackL(StackLinkList L, const std::string& title);