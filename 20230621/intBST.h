#pragma once
#include <iostream>
#include <cstdlib>

class TNode { /* 树结点定义 */
	friend class intBST;
public:
	int GetData();
private:
	int Data; /* 结点数据 */
	TNode* Left;     /* 指向左子树 */
	TNode* Right;    /* 指向右子树 */
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