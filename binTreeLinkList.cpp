#include "binTreeLinkList.h"
#include <stdio.h>

const int gNodeNum = 9;
static LBinNode* gNodeIndex[gNodeNum] = { NULL };

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
			gNodeIndex[i]->isForLeftChild = 0;
			gNodeIndex[i]->isForRightChild = 0;
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
	gNodeIndex[0]->isForLeftChild = 1;
	gNodeIndex[0]->right = gNodeIndex[2];
	gNodeIndex[0]->isForRightChild = 1;

	gNodeIndex[1]->left = gNodeIndex[3];
	gNodeIndex[1]->isForLeftChild = 1;
	gNodeIndex[1]->right = gNodeIndex[4];
	gNodeIndex[1]->isForRightChild = 1;

	gNodeIndex[2]->left = gNodeIndex[5];
	gNodeIndex[2]->isForLeftChild = 1;
	gNodeIndex[2]->right = gNodeIndex[6];
	gNodeIndex[2]->isForRightChild = 1;

	gNodeIndex[3]->left = gNodeIndex[7];
	gNodeIndex[3]->isForLeftChild = 1;
	//gNodeIndex[3]->right = gNodeIndex[];
	//gNodeIndex[3]->isForRightChild = ;

	//gNodeIndex[4]->left = gNodeIndex[];
	//gNodeIndex[4]->isForLeftChild = ;
	//gNodeIndex[4]->right = gNodeIndex[];
	//gNodeIndex[4]->isForRightChild = ;

	//gNodeIndex[5]->left = gNodeIndex[];
	//gNodeIndex[5]->isForLeftChild = ;
	//gNodeIndex[5]->right = gNodeIndex[];
	//gNodeIndex[5]->isForRightChild = ;

	//gNodeIndex[6]->left = gNodeIndex[];
	//gNodeIndex[6]->isForLeftChild = ;
	gNodeIndex[6]->right = gNodeIndex[8];
	gNodeIndex[6]->isForRightChild = 1;

	//gNodeIndex[7]->left = gNodeIndex[];
	//gNodeIndex[7]->isForLeftChild = ;
	//gNodeIndex[7]->right = gNodeIndex[];
	//gNodeIndex[7]->isForRightChild = ;

	//gNodeIndex[8]->left = gNodeIndex[];
	//gNodeIndex[8]->isForLeftChild = ;
	//gNodeIndex[8]->right = gNodeIndex[];
	//gNodeIndex[8]->isForRightChild = ;
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

void PreVisit(LBinNode* node)
{
	if (node)
	{
		PrintLNode(node);
		PreVisit(node->left);
		PreVisit(node->right);
	}
}

void MidVisit(LBinNode* node)
{
	if (node)
	{
		MidVisit(node->left);
		PrintLNode(node);
		MidVisit(node->right);
	}
}

void PosVisit(LBinNode* node)
{
	if (node)
	{
		PosVisit(node->left);
		PosVisit(node->right);
		PrintLNode(node);
	}
}

void PrintLNode(LBinNode* node)
{
	printf("data: %c(%d), ptr: %p\nlchild: %p, rchild: %p\nisForLeftChild: %d, isForRightChild: %d\n\n",
			node->data, node->data, node, node->left, node->right, node->isForLeftChild, node->isForRightChild);
}

void PirntBinTree_L(LBinTree Lb, const std::string& title)
{
	printf("developing...\n");
	//std::cout << "二叉链表" << title << ":" << std::endl;
	//for (int i = 0; i < Lb->nodeNum; i++)
	//	printf("data: %c(%d)\nlchild: %p, rchild: %p\nisForLeftChild: %d, isForRightChild: %d\n\n",
	//		Lb->data);
}
