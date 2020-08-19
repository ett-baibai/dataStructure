#pragma once
#include "typedef.h"
#include <iostream>

typedef struct LBinNode
{
	BElemType data;
	struct LBinNode *left, *right;
	bool isForLeftChild, isForRightChild;
}LBinNode, * LBinTree;


bool InitBinTree_L(LBinTree& Lb);
void CreateBinTree_L(LBinTree& Lb);
void DestroyBinTree_L();
void PreVisit(LBinNode* node);
void MidVisit(LBinNode* node);
void PosVisit(LBinNode* node);
void PrintLNode(LBinNode* node);
void PirntBinTree_L(LBinTree Lb, const std::string& title);