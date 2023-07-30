#include "IntBst.h"

IntBST::IntBST()
{
    m_Root = nullptr;
}

IntBST::IntBST(int key)
{
    m_Root = new Node;

    m_Root->m_data = key;
    m_Root->lChild = nullptr;
    m_Root->rChild = nullptr;
}

Node* IntBST::GetRoot()
{
    return m_Root;
}

Node* IntBST::Insert(int key)
{
    return Insert(key, m_Root);
}

Node* IntBST::Insert(int key, Node* node)
{
    Node* temp = nullptr;

    if (node == nullptr)
    {
        temp = new Node;
        temp->m_data = key;
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

Node* IntBST::NewNode(int key)
{
    Node* node = new Node;

    node->m_data = key;
    node->lChild = nullptr;
    node->rChild = nullptr;

    return node;
}

Node* IntBST::iInsert(int key)
{
    Node* newnode = NewNode(key);
    Node* x = m_Root;
    Node* y = NULL;

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

void IntBST::Inorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    else {
        Inorder(root->lChild);
        cout << root->m_data << " ";
        Inorder(root->rChild);
    }
}