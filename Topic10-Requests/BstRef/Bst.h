#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include <iostream>

template <class T>
struct Node {
    /// Left child of the node
    Node* lChild;
    /// Element in the node
    T m_data;
    /// Right child of the node
    Node* rChild;
};

template <class T>
class Bst
{
private:
    Node<T>* m_Root;

    Node<T>* Insert(T key, Node<T>* node);

    Node<T>* NewNode(T key);

public:
    Bst();

    Bst(T key);

    Node<T>* GetRoot();

    Node<T>* Insert(T key);

    Node<T>* iInsert(T key);

    void Inorder(Node<T>* n);
};

template <class T>
Bst<T>::Bst()
{
    m_Root = nullptr;
}

template <class T>
Bst<T>::Bst(T key)
{
    m_Root = NewNode(key);
}

template <class T>
Node<T>* Bst<T>::NewNode(T key)
{
    Node<T>* node = new Node<T>;

    node->m_data = key;
    node->lChild = nullptr;
    node->rChild = nullptr;

    return node;
}

template <class T>
Node<T>* Bst<T>::GetRoot()
{
    return m_Root;
}

template <class T>
Node<T>* Bst<T>::Insert(T key)
{
    return Insert(key, m_Root);
}

template <class T>
Node<T>* Bst<T>::Insert(T key, Node<T>* node)
{
    Node<T>* temp = nullptr;

    if (node == nullptr)
    {
        temp = NewNode(key);
        temp->lChild = nullptr;
        temp->rChild = nullptr;
        return temp;
    }

    if (key < node->m_data)
    {
        node->lChild = Insert(key, node->lChild);
    }
    else
    {
        node->rChild = Insert(key, node->rChild);
    }

    return node;
}

template <class T>
Node<T>* Bst<T>::iInsert(T key)
{
    Node<T>* newnode = NewNode(key);
    Node<T>* x = m_Root;
    Node<T>* y = NULL;

    while (x != NULL)
    {
        y = x;
        if (key < x->m_data)
        {
            x = x->lChild;
        }
        else
        {
            x = x->rChild;
        }
    }

    if (y == NULL)
    {
        y = newnode;
    }
    else if (key < y->m_data)
    {
        y->lChild = newnode;
    }
    else
    {
        y->rChild = newnode;
    }
    return y;
}

template <class T>
void Bst<T>::Inorder(Node<T>* root)
{
    if (root == NULL)
    {
        return;
    }
    else {
        Inorder(root->lChild);

        Inorder(root->rChild);
    }
}

#endif
