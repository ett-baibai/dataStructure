#pragma once
#include "typedef.h"
#include <iostream>

enum StateFlag
{
	init = 0,
	child = 1,
	clue = 2
};

typedef struct LBinNode
{
	BElemType data;
	struct LBinNode *left, *right;
	StateFlag lflag, rflag;
}LBinNode, * LBinTree;


bool InitBinTree_L(LBinTree& Lb);
void CreateBinTree_L(LBinTree& Lb);
void ResetBinTree_L();
void DestroyBinTree_L();
void PreVisit_L(LBinNode* node);
void MidVisit_L(LBinNode* node);
void PosVisit_L(LBinNode* node);

void CableNode_L(LBinNode* node, LBinNode*& pre);
void HandlePreClue_L(LBinNode* node, LBinNode* &pre);
void PreClue_L(LBinNode* node, LBinNode* pre);
void HandleMidClue_L(LBinNode* node, LBinNode*& pre);
void MidClue_L(LBinNode* node, LBinNode* pre);
void HandlePosClue_L(LBinNode* node, LBinNode*& pre);
void PosClue_L(LBinNode* node, LBinNode* pre);

void PrintLNode(LBinNode* node);
void PirntBinTree_L(LBinTree Lb, const std::string& title);