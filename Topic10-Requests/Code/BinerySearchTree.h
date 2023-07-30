#pragma once
#include <iostream>
#include <cstdlib>
#include <typeinfo>
template <class T>
struct nodeType  // answer why struct encapsulation is used - rationale
	// there are other approaches, choose which one is the most
	// appropriate and provide rationale
{
	T Data; /* 结点数据 */
	nodeType<T>* Left;     /* 指向左子树 */
	nodeType<T>* Right;    /* 指向右子树 */
	T& GetData()
	{
		return Data;
	}
};

template <class T>
class Bst 
{
	typedef void (*processMethod)(T&);
	typedef void (*fun)(T&, std::string, double&);

public:
	Bst(T X);
	Bst();
	//~Bst();
	nodeType<T>* Insert(nodeType<T>* BST, T X);
	nodeType<T>* DeleteTree(nodeType<T>*& BST);
	nodeType<T>* Find(T X, nodeType<T>* BST);

	void InOrderTraversal(processMethod f1) const;
	void InOrderTraversal(fun f1, std::string colName, double& res) const;

	void PreOrderTraversal(processMethod f1) const;
	void PostOrderTraversal(processMethod f1) const;

	nodeType<T>*& GetTree();

	Bst<T>& operator=(Bst<T>& other);
	void Clone(nodeType<T>*& lhs, nodeType<T>* rhs);
private:
	nodeType<T>* m_root;
	void InOrder(processMethod f1, nodeType<T>* p) const;
	void InOrder(fun f1, nodeType<T>* p, std::string colName, double& res) const;

	void PreOrder(processMethod f1, nodeType<T>* p) const;
	void PostOrder(processMethod f1, nodeType<T>* p) const;
};

//template <class T>
//Bst<T>::~Bst()
//{
//	//std::cout << "当前需要析构的节点是" << typeid(m_root->GetData()).name() << std::endl;
//	if (m_root == NULL)
//		return;
//	//DeleteTree(m_root);
//	m_root = NULL;
//}

template <class T>
Bst<T>::Bst()
{
	m_root = new nodeType<T>;
	m_root->Left = NULL;
	m_root->Right = NULL;
}

template <class T>
Bst<T>::Bst(T X)
{
	m_root = new nodeType<T>;
	m_root->Left = NULL;
	m_root->Right = NULL;
	m_root->Data = X;
}

template <class T>
nodeType<T>*& Bst<T>::GetTree()
{
	return m_root;
}

template <class T>
nodeType<T>* Bst<T>::Insert(nodeType<T>* BST, T X)
{
	if (BST == NULL)
	{
		int a = sizeof(nodeType<T>);
		//BST = (nodeType<T>*)malloc(sizeof(nodeType<T>));
		BST = new nodeType<T>;
		//BST = (nodeType<T>*)malloc(112)
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else
	{
		if (X < BST->GetData())
			BST->Left = Insert(BST->Left, X);
		else //if (X > BST->GetData())
			BST->Right = Insert(BST->Right, X);
	}
	return BST;
}

template <class T>
nodeType<T>* Bst<T>::DeleteTree(nodeType<T>*& BST)
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
		delete BST;
		BST = NULL;
		return BST;
	}
}

template <class T>
nodeType<T>* Bst<T>::Find(T X, nodeType<T>* BST)
{
	if (!BST) return NULL; /*查找失败*/
	if (X > BST->GetData())
		return Find(X, BST->Right);
	else if (X < BST->GetData())
		return Find(X, BST->Left);
	else
		return BST;
}

template <class T>
void Bst<T>::InOrder(processMethod f1, nodeType<T>* BST) const
{
	if (BST == NULL) {
		return;
	}
	else {
		InOrder(f1, BST->Left);
		if (BST != m_root)//不遍历根节点的数据
		{
			f1(BST->GetData());
		}
		InOrder(f1, BST->Right);
	}
}

template <class T>
void Bst<T>::InOrderTraversal(processMethod f1) const
{
	InOrder(f1, m_root);
}

template <class T>
void Bst<T>::InOrder(fun f1, nodeType<T>* BST, std::string colName, double& res) const
{
	if (BST == NULL) {
		return;
	}
	else {
		InOrder(f1, BST->Left, colName, res);
		if (BST != m_root)//不遍历根节点的数据
		{
			f1(BST->GetData(), colName, res);
		}
		InOrder(f1, BST->Right, colName, res);
	}
}

template <class T>
void Bst<T>::InOrderTraversal(fun f1, std::string colName, double& res) const
{
	InOrder(f1, m_root, colName, res);
}

template <class T>
void Bst<T>::PreOrder(processMethod f1, nodeType<T>* BST) const
{
	if (BST == NULL) {
		return;
	}
	else {
		f1(BST->GetData());
		//std::cout << BST->GetData() << "  ";
		PreOrder(f1, BST->Left);
		PreOrder(f1, BST->Right);
	}
}

template <class T>
void Bst<T>::PreOrderTraversal(processMethod f1) const
{
	PreOrder(f1, m_root);
}

template <class T>
void Bst<T>::PostOrder(processMethod f1, nodeType<T>* BST) const
{
	if (BST == NULL) {
		return;
	}
	else {
		PostOrder(f1, BST->Left);
		PostOrder(f1, BST->Right);
		f1(BST->GetData());
		//std::cout << BST->GetData() << "  ";
	}
}

template <class T>
void Bst<T>::PostOrderTraversal(processMethod f1) const
{
	PostOrder(f1, m_root);
}

template <class T>
Bst<T>& Bst<T>::operator=(Bst<T>& other)
{
	Clone(m_root, other.GetTree());
	return *this;
}

template <class T>
void Bst<T>::Clone(nodeType<T>*& lhs, nodeType<T>* rhs)
{
	if (rhs == NULL)
	{
		lhs = NULL;
	}
	else {
		lhs = new nodeType<T>();
		lhs->Data = rhs->Data;
		Clone(lhs->Left, rhs->Left);
		Clone(lhs->Right, rhs->Right);
	}
}