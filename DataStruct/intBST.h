#pragma once
#include <iostream>
#include <cstdlib>
#include <queue>

#include "assert.h"

typedef int ElementType;
class TNode { /* 树结点定义 */
	friend class intBST;
public:
	ElementType GetData()
	{
		return Data;
	}
private:
	ElementType Data; /* 结点数据 */
	TNode* Left;     /* 指向左子树 */
	TNode* Right;    /* 指向右子树 */
};

class intBST
{
public:
	intBST()
	{
		m_RootNode = new TNode;
		m_RootNode->Left = NULL;
		m_RootNode->Right = NULL;
	}

	~intBST()
	{
		clear();
	}
	void clear()
	{
		if (!m_RootNode)
		{
			std::queue<TNode*> q;
			q.push(m_RootNode);
			while (!q.empty())
			{
				TNode* f = q.front();
				if (f->Left != NULL) q.push(f->Left);//如果子女不为空就加入子女，一会儿删除
				if (f->Right != NULL) q.push(f->Right);
				delete f;//删除当前节点
				q.pop();//把没用的指针弹出
			}
			m_RootNode = NULL;
		}
	}

	TNode* Find(ElementType X, TNode* BST)
	{
		if (!BST) return NULL; /*查找失败*/
		if (X > BST->Data)
			return Find(X, BST->Right); /*在右子树中继续查找*/
		else if (X < BST->Data)
			return Find(X, BST->Left); /*在左子树中继续查找*/
		else /* X == BST->Data */
			return BST; /*查找成功，返回结点的找到结点的地址*/
	}

	TNode* IterFind(ElementType X)
	{
		TNode* p = m_RootNode;
		while (p)
		{
			if (X > p->Data)
				p = p->Right; /*向右子树中移动，继续查找*/
			else if (X < p->Data)
				p = p->Left; /*向左子树中移动，继续查找*/
			else /* X == p->Data */
				return p; /*查找成功，返回结点的找到结点的地址*/
		}
		return NULL; /*查找失败*/
	}

	TNode* FindMin(TNode* m_RootNode)
	{
		if (!m_RootNode)
			return NULL; /*空的二叉搜索树，返回NULL*/
		else if (!m_RootNode->Left)
			return m_RootNode; /*找到最左叶结点并返回*/
		else
			return FindMin(m_RootNode->Left); /*沿左分支继续查找*/
	}

	TNode* FindMax(TNode* m_RootNode)
	{
		if (m_RootNode)
			while (m_RootNode->Right)  /*沿右分支继续查找，直到最右叶结点*/
				m_RootNode = m_RootNode->Right;
		return m_RootNode;
	}

	TNode* Insert(TNode* BST, ElementType X)
	{
		if (!BST) { /* 若原树为空，生成并返回一个结点的二叉搜索树 */
			BST = (TNode*)malloc(sizeof(struct TNode));
			BST->Data = X;
			BST->Left = BST->Right = NULL;
		}
		else { /* 开始找要插入元素的位置 */
			if (X < BST->Data)
				BST->Left = Insert(BST->Left, X);   /*递归插入左子树*/
			else  if (X > BST->Data)
				BST->Right = Insert(BST->Right, X); /*递归插入右子树*/
			/* else X已经存在，什么都不做 */
		}
		return BST;
	}

	TNode* Delete(TNode* BST, ElementType X)
	{
		TNode* Tmp;
		if (!BST)
			printf("要删除的元素未找到");
		else {
			if (X < BST->Data)
				BST->Left = Delete(BST->Left, X);   /* 从左子树递归删除 */
			else if (X > BST->Data)
				BST->Right = Delete(BST->Right, X); /* 从右子树递归删除 */
			else
			{ /* BST就是要删除的结点 */
				/* 如果被删除结点有左右两个子结点 */
				if (BST->Left && BST->Right)
				{
					/* 从右子树中找最小的元素填充删除结点 */
					Tmp = FindMin(BST->Right);
					BST->Data = Tmp->Data;
					/* 从右子树中删除最小元素 */
					BST->Right = Delete(BST->Right, BST->Data);
				}
				else
				{ /* 被删除结点有一个或无子结点 */
					Tmp = BST;
					if (!BST->Left)       /* 只有右孩子或无子结点 */
						BST = BST->Right;
					else                   /* 只有左孩子 */
						BST = BST->Left;
					free(Tmp);
				}
			}
		}
		return BST;
	}

	TNode* GetTree()
	{
		return m_RootNode;
	}
private:
	TNode* m_RootNode;
};
