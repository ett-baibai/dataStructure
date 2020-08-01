#pragma once
#include "typedef.h"
#include <iostream>

#define STACK_INIT_SIZE  10
#define STACK_INCREASE 1

typedef struct
{
	SElemType* base;
	SElemType* top;
	int stackSize;
}SqStack;


void InitStack_Sq(SqStack &S);
void DestroyStack_Sq(SqStack& S);
bool StackEmpty_Sq(SqStack S);
int GetStackLength_Sq(SqStack S);
bool GetPop_Sq(SqStack S, SElemType& e);
bool Push_Sq(SqStack& S, SElemType e);
bool Pop_Sq(SqStack& S, SElemType &e);
void printStackSq(SqStack S, const std::string& title);