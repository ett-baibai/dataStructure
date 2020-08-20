#include "binTreeLinkList.h"
#include <stdio.h>

const int gNodeNum = 9;
static LBinNode* gNodeIndex[gNodeNum] = { NULL };
static const std::string gFlag[] = {"init","child", "clue"};

bool InitBinTree_L(LBinTree& Lb)
{
	printf("developing...\n");
	return OK;
}

void CreateBinTree_L(LBinTree& Lb)
{
	for (int i = 0; i < gNodeNum; i++)
	{
		gNodeIndex[i] = (LBinNode*)malloc(sizeof(LBinNode));
		if (!gNodeIndex[i])
		{
			printf("结点%d的内存申请失败\n", i + 1);
			exit(ERROR);
		}
		else
		{
			gNodeIndex[i]->data = i + 65;
			gNodeIndex[i]->left = NULL;
			gNodeIndex[i]->right = NULL;
			gNodeIndex[i]->lflag = init;
			gNodeIndex[i]->rflag = init;
		}
	}

	Lb = gNodeIndex[0];//!!!

	/*
		  	                             A
                          /                                 \
	                     B                                   C
                  /              \                  /                 \
				  D               E                 F                  G
            /                                                              \
			H                                                               I
	*/
	
	gNodeIndex[0]->left = gNodeIndex[1];
	gNodeIndex[0]->lflag = child;
	gNodeIndex[0]->right = gNodeIndex[2];
	gNodeIndex[0]->rflag = child;

	gNodeIndex[1]->left = gNodeIndex[3];
	gNodeIndex[1]->lflag = child;
	gNodeIndex[1]->right = gNodeIndex[4];
	gNodeIndex[1]->rflag = child;

	gNodeIndex[2]->left = gNodeIndex[5];
	gNodeIndex[2]->lflag = child;
	gNodeIndex[2]->right = gNodeIndex[6];
	gNodeIndex[2]->rflag = child;

	gNodeIndex[3]->left = gNodeIndex[7];
	gNodeIndex[3]->lflag = child;
	//gNodeIndex[3]->right = gNodeIndex[];
	//gNodeIndex[3]->rflag = ;

	//gNodeIndex[4]->left = gNodeIndex[];
	//gNodeIndex[4]->lflag = ;
	//gNodeIndex[4]->right = gNodeIndex[];
	//gNodeIndex[4]->rflag = ;

	//gNodeIndex[5]->left = gNodeIndex[];
	//gNodeIndex[5]->lflag = ;
	//gNodeIndex[5]->right = gNodeIndex[];
	//gNodeIndex[5]->rflag = ;

	//gNodeIndex[6]->left = gNodeIndex[];
	//gNodeIndex[6]->lflag = ;
	gNodeIndex[6]->right = gNodeIndex[8];
	gNodeIndex[6]->rflag = child;

	//gNodeIndex[7]->left = gNodeIndex[];
	//gNodeIndex[7]->lflag = ;
	//gNodeIndex[7]->right = gNodeIndex[];
	//gNodeIndex[7]->rflag = ;

	//gNodeIndex[8]->left = gNodeIndex[];
	//gNodeIndex[8]->lflag = ;
	//gNodeIndex[8]->right = gNodeIndex[];
	//gNodeIndex[8]->rflag = ;
}

void ResetBinTree_L()
{
	for (int i = 0; i < gNodeNum; i++)
	{
		if (gNodeIndex[i]->lflag == clue)
		{
			gNodeIndex[i]->left = NULL;
			gNodeIndex[i]->lflag = init;
		}

		if (gNodeIndex[i]->rflag == clue)
		{
			gNodeIndex[i]->right = NULL;
			gNodeIndex[i]->rflag = init;
		}
	}
}

void DestroyBinTree_L()
{
	for (int i = 0; i < gNodeNum; i++)
	{
		if (!gNodeIndex[i])
		{
			free(gNodeIndex[i]);
			gNodeIndex[i] = NULL;
		}
	}
}

void PreVisit_L(LBinNode* node)
{
	if (node)
	{
		PrintLNode(node);
		if(node->lflag == child)
			PreVisit_L(node->left);
		if(node->rflag == child)
			PreVisit_L(node->right);
	}
}

void MidVisit_L(LBinNode* node)
{
	if (node)
	{
		if (node->lflag == child)
			MidVisit_L(node->left);
		PrintLNode(node);
		if (node->rflag == child)
			MidVisit_L(node->right);
	}
}

void PosVisit_L(LBinNode* node)
{
	if (node)
	{
		if (node->lflag == child)
			PosVisit_L(node->left);
		if (node->rflag == child)
			PosVisit_L(node->right);
		PrintLNode(node);
	}
}

void CableNode_L(LBinNode* node, LBinNode*& pre)
{
	if (node->lflag == init)
	{
		node->left = pre;
		node->lflag = clue;
	}
	
	if (pre && pre->rflag == init)
	{
		pre->right = node;
		pre->rflag = clue;
	}
	
	pre = node;	
}

void HandlePreClue_L(LBinNode* node, LBinNode* &pre)
{
	if (node)
	{
		CableNode_L(node, pre);
		if(node->lflag != clue)
			HandlePreClue_L(node->left, pre);
		if(node->rflag != clue)
			HandlePreClue_L(node->right, pre);
	}
}

void PreClue_L(LBinNode* node, LBinNode* pre)
{
	HandlePreClue_L(node, pre);
	pre->right = NULL;
	pre->rflag = clue;
}

void HandleMidClue_L(LBinNode* node, LBinNode*& pre)
{
	if (node)
	{
		//if (node->lflag != clue)
			HandleMidClue_L(node->left, pre);
		CableNode_L(node, pre);
		//if (node->rflag != clue)
			HandleMidClue_L(node->right, pre);
	}
}

void MidClue_L(LBinNode* node, LBinNode* pre)
{
	HandleMidClue_L(node, pre);
	pre->right = NULL;
	pre->rflag = clue;
}

void HandlePosClue_L(LBinNode* node, LBinNode*& pre)
{
	if (node)
	{
		HandlePosClue_L(node->left, pre);
		HandlePosClue_L(node->right, pre);
		CableNode_L(node, pre);
	}
}

void PosClue_L(LBinNode* node, LBinNode* pre)
{
	HandlePosClue_L(node, pre);
}

void PrintLNode(LBinNode* node)
{
	printf("node: %c\n",node->data);
	std::cout << "lflag: " << gFlag[node->lflag] << ", rflag: " << gFlag[node->rflag] << std::endl;
	if (node->left && node->right)
		printf("left: %c, right: %c\n", node->left->data, node->right->data);
	else if (node->left && !node->right)
		printf("left: %c, right: NULL\n", node->left->data);
	else if (!node->left && node->right)
		printf("left: NULL, right: %c\n", node->right->data);
	else
		printf("left: NULL, right: NULL\n");
	printf("\n");
}

void PirntBinTree_L(LBinTree Lb, const std::string& title)
{
	printf("developing...\n");
	//std::cout << "二叉链表" << title << ":" << std::endl;
	//for (int i = 0; i < Lb->nodeNum; i++)
	//	printf("data: %c(%d)\nlchild: %p, rchild: %p\nisForLeftChild: %d, rflag: %d\n\n",
	//		Lb->data);
}
