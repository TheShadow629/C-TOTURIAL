#pragma once
#include <iostream>
#include <cstdlib>

class TNode { /* ����㶨�� */
	friend class intBST;
public:
	int GetData();
private:
	int Data; /* ������� */
	TNode* Left;     /* ָ�������� */
	TNode* Right;    /* ָ�������� */
};


class intBST
{
public:
	intBST(int x=0);
	TNode* Insert(TNode* BST, int X);
	bool DeleteTree(TNode* BST);
	TNode* Find(int X, TNode* BST);

	void InOrderTraversal(TNode* BST);
	void PreOrderTraversal(TNode* BST);
	void PostOrderTraversal(TNode* BST);

	TNode* GetTree();
private:
	TNode* m_RootNode;
};