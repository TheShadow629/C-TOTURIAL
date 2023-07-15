#pragma once
#include <iostream>
#include <cstdlib>

template <class T>
class TNode1 { /* ����㶨�� */
	friend class intBST;
public:
	T GetData();
private:
	T Data; /* ������� */
	TNode1<T>* Left;     /* ָ�������� */
	TNode1<T>* Right;    /* ָ�������� */
};

template <class T>
T TNode1<T>::GetData()
{
	return Data;
}

template <class T>
class Bst
{
public:
	Bst();
	TNode1<T>* Insert(TNode1<T>* BST, int X);
	TNode1<T>* DeleteTree(TNode1<T>* BST);
	TNode1<T>* Find(int X, TNode1<T>* BST);

	void InOrderTraversal(TNode1<T>* BST);
	void PreOrderTraversal(TNode1<T>* BST);
	void PostOrderTraversal(TNode1<T>* BST);

	TNode1<T>* GetTree();
private:
	TNode1<T>* m_RooTNode1;
};

template <class T>
Bst<T>::Bst<T>()
{
	m_RooTNode1 = NULL;
}

template <class T>
TNode1<T>* Bst<T>::GetTree()
{
	return m_RooTNode1;
}

template <class T>
TNode1<T>* Bst<T>::Insert(TNode1<T>* BST, int X)
{
	if (BST == NULL)
	{
		BST = (TNode1<T>*)malloc(sizeof(TNode1<T>));
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

template <class T>
TNode1<T>* Bst<T>::DeleteTree(TNode1<T>* BST)
{
	if (BST == NULL)
	{
		return NULL;
	}
	else
	{
		if (BST->Left != NULL)
			DeleteTree(BST->Left);
		if (BST->Right != NULL)
			DeleteTree(BST->Right);
		free(BST);
		return BST;
	}
}

template <class T>
TNode1<T>* Bst<T>::Find(int X, TNode1<T>* BST)
{
	if (!BST) return NULL; /*����ʧ��*/
	if (X > BST->GetData())
		return Find(X, BST->Right);
	else if (X < BST->GetData())
		return Find(X, BST->Left);
	else
		return BST;
}

template <class T>
void Bst<T>::InOrderTraversal(TNode1<T>* BST)
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

template <class T>
void Bst<T>::PreOrderTraversal(TNode1<T>* BST)
{
	if (BST == NULL) {
		return;
	}
	else {
		std::cout << BST->GetData();
		PreOrderTraversal(BST->Left);
		PreOrderTraversal(BST->Right);
	}
}

template <class T>
void Bst<T>::PostOrderTraversal(TNode1<T>* BST)
{
	if (BST == NULL) {
		return;
	}
	else {
		PostOrderTraversal(BST->Left);
		PostOrderTraversal(BST->Right);
		std::cout << BST->GetData();
	}
}