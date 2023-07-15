#pragma once
#include <iostream>
#include <cstdlib>

template<class T> class Bst;

template <class T>
class TNode1 { /* ����㶨�� */
	friend class Bst<T>;
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
	Bst(T X=NULL);
	TNode1<T>* Insert(TNode1<T>* BST, const T& X);
	TNode1<T>* DeleteTree(TNode1<T>* BST);
	TNode1<T>* Find(T X, TNode1<T>* BST);

	void InOrderTraversal(TNode1<T>* BST);
	void PreOrderTraversal(TNode1<T>* BST);
	void PostOrderTraversal(TNode1<T>* BST);

	TNode1<T>* GetTree();
private:
	TNode1<T>* m_RooTNode1;
};

template <class T>
Bst<T>::Bst<T>(T X)
{
	m_RooTNode1 = new TNode1<T>;
	m_RooTNode1->Left = NULL;
	m_RooTNode1->Right = NULL;
	m_RooTNode1->Data = X;
}

template <class T>
TNode1<T>* Bst<T>::GetTree()
{
	return m_RooTNode1;
}

template <class T>
TNode1<T>* Bst<T>::Insert(TNode1<T>* BST, const T& X)
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
		BST = NULL;
		return BST;
	}
}

template <class T>
TNode1<T>* Bst<T>::Find(T X, TNode1<T>* BST)
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
		std::cout << BST->GetData() << "  ";
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
		std::cout << BST->GetData() << "  ";
	}
}