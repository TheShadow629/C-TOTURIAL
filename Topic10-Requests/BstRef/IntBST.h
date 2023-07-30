#ifndef INTBST_H_INCLUDED
#define INTBST_H_INCLUDED

#include <iostream>

using namespace std;

struct Node {
    /// Left child of the node
    Node* lChild;
    /// Element in the node
    int m_data;
    /// Right child of the node
    Node* rChild;
};

class IntBST
{
private:
        Node* m_Root;

        Node* Insert(int key, Node* node);

        Node* NewNode(int key);

public:
    IntBST();

    IntBST(int key);

    Node* GetRoot();

    Node* Insert(int key);

    Node* iInsert(int key);

    void Inorder(Node* n);
};

#endif