#pragma once
#include <iostream>
#include <cstdlib>
#include <queue>

#include "assert.h"

typedef int ElementType;
class TNode { /* ����㶨�� */
	friend class intBST;
public:
	ElementType GetData()
	{
		return Data;
	}
private:
	ElementType Data; /* ������� */
	TNode* Left;     /* ָ�������� */
	TNode* Right;    /* ָ�������� */
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
				if (f->Left != NULL) q.push(f->Left);//�����Ů��Ϊ�վͼ�����Ů��һ���ɾ��
				if (f->Right != NULL) q.push(f->Right);
				delete f;//ɾ����ǰ�ڵ�
				q.pop();//��û�õ�ָ�뵯��
			}
			m_RootNode = NULL;
		}
	}

	TNode* Find(ElementType X, TNode* BST)
	{
		if (!BST) return NULL; /*����ʧ��*/
		if (X > BST->Data)
			return Find(X, BST->Right); /*���������м�������*/
		else if (X < BST->Data)
			return Find(X, BST->Left); /*���������м�������*/
		else /* X == BST->Data */
			return BST; /*���ҳɹ������ؽ����ҵ����ĵ�ַ*/
	}

	TNode* IterFind(ElementType X)
	{
		TNode* p = m_RootNode;
		while (p)
		{
			if (X > p->Data)
				p = p->Right; /*�����������ƶ�����������*/
			else if (X < p->Data)
				p = p->Left; /*�����������ƶ�����������*/
			else /* X == p->Data */
				return p; /*���ҳɹ������ؽ����ҵ����ĵ�ַ*/
		}
		return NULL; /*����ʧ��*/
	}

	TNode* FindMin(TNode* m_RootNode)
	{
		if (!m_RootNode)
			return NULL; /*�յĶ���������������NULL*/
		else if (!m_RootNode->Left)
			return m_RootNode; /*�ҵ�����Ҷ��㲢����*/
		else
			return FindMin(m_RootNode->Left); /*�����֧��������*/
	}

	TNode* FindMax(TNode* m_RootNode)
	{
		if (m_RootNode)
			while (m_RootNode->Right)  /*���ҷ�֧�������ң�ֱ������Ҷ���*/
				m_RootNode = m_RootNode->Right;
		return m_RootNode;
	}

	TNode* Insert(TNode* BST, ElementType X)
	{
		if (!BST) { /* ��ԭ��Ϊ�գ����ɲ�����һ�����Ķ��������� */
			BST = (TNode*)malloc(sizeof(struct TNode));
			BST->Data = X;
			BST->Left = BST->Right = NULL;
		}
		else { /* ��ʼ��Ҫ����Ԫ�ص�λ�� */
			if (X < BST->Data)
				BST->Left = Insert(BST->Left, X);   /*�ݹ����������*/
			else  if (X > BST->Data)
				BST->Right = Insert(BST->Right, X); /*�ݹ����������*/
			/* else X�Ѿ����ڣ�ʲô������ */
		}
		return BST;
	}

	TNode* Delete(TNode* BST, ElementType X)
	{
		TNode* Tmp;
		if (!BST)
			printf("Ҫɾ����Ԫ��δ�ҵ�");
		else {
			if (X < BST->Data)
				BST->Left = Delete(BST->Left, X);   /* ���������ݹ�ɾ�� */
			else if (X > BST->Data)
				BST->Right = Delete(BST->Right, X); /* ���������ݹ�ɾ�� */
			else
			{ /* BST����Ҫɾ���Ľ�� */
				/* �����ɾ����������������ӽ�� */
				if (BST->Left && BST->Right)
				{
					/* ��������������С��Ԫ�����ɾ����� */
					Tmp = FindMin(BST->Right);
					BST->Data = Tmp->Data;
					/* ����������ɾ����СԪ�� */
					BST->Right = Delete(BST->Right, BST->Data);
				}
				else
				{ /* ��ɾ�������һ�������ӽ�� */
					Tmp = BST;
					if (!BST->Left)       /* ֻ���Һ��ӻ����ӽ�� */
						BST = BST->Right;
					else                   /* ֻ������ */
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
