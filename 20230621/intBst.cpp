#include "intBST.h"

int TNode::GetData()
{
	return Data;
}

intBST::intBST(int x)
{
	m_RootNode = new TNode;
	m_RootNode->Left = NULL;
	m_RootNode->Right = NULL;
	m_RootNode->Data = x;
}

TNode* intBST::GetTree()
{
	return m_RootNode;
}

TNode* intBST::Insert(TNode* BST, int X)
{
	if (BST == NULL)
	{
		BST = (TNode*)malloc(sizeof(TNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else
	{
		if (X < BST->GetData())
			BST->Left = Insert(BST->Left, X);
		else if (X > BST->GetData())
			BST->Right = Insert(BST->Right, X);
	}
	return BST;
}

bool intBST::DeleteTree(TNode* BST)
{
	if (BST == NULL)
	{
		return true;
	}
	else
	{
		if (BST->Left != NULL)
			DeleteTree(BST->Left);
		if (BST->Right != NULL)
			DeleteTree(BST->Right);
		free(BST);
		BST = NULL;
		return true;
	}
}

TNode* intBST::Find(int X, TNode* BST)
{
	if (!BST) return NULL; /*²éÕÒÊ§°Ü*/
	if (X > BST->GetData())
		return Find(X, BST->Right);
	else if (X < BST->GetData())
		return Find(X, BST->Left);
	else
		return BST;
}

void intBST::InOrderTraversal(TNode* BST)
{
	if (BST == NULL) {
		return;
	}
	else {
		InOrderTraversal(BST->Left);
		std::cout << BST->GetData() << "  ";
		InOrderTraversal(BST->Right);
	}
}

void intBST::PreOrderTraversal(TNode* BST)
{
	if (BST == NULL) {
		return;
	}
	else {
		std::cout << BST->GetData() << "  ";
		PreOrderTraversal(BST->Left);
		PreOrderTraversal(BST->Right);
	}
}

void intBST::PostOrderTraversal(TNode* BST)
{
	if (BST == NULL) {
		return;
	}
	else {
		PostOrderTraversal(BST->Left);
		PostOrderTraversal(BST->Right);
		std::cout << BST->GetData() << "  ";
	}
}