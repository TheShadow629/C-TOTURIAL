#pragma once
#include<iostream>
using namespace std;
template<class Type>
class BinTreeNode
{
public:
    BinTreeNode()
    {
        left = nullptr;
        right = nullptr;
    }
public:
    Type val;
    BinTreeNode *left;
    BinTreeNode *right;
};

template<class Type>
BinTreeNode<Type>* InsertBintree(BinTreeNode<Type>*& root, Type val) 
{
    if (root == NULL) 
    { 
        // empty tree
        root = new BinTreeNode<Type>();
        root->val = val;
    }
    else if (val < root->val) 
    {
        root->left = InsertBintree(root->left, val);
    }
    else 
    {
        root->right = InsertBintree(root->right, val);
    }
    return root;
}

template<class Type>
void Pre_Trival(BinTreeNode<Type> *root)
{
    if (root == nullptr)
        return;

    Pre_Trival(root->left);
    cout << root->val << endl;
    Pre_Trival(root->right);
}

template<class Type>
void Mid_Trival(BinTreeNode<Type> *root)
{
    if (root == nullptr)
        return;

    cout << root->val << endl;
    Mid_Trival(root->left);
    Mid_Trival(root->right);
}

template<class Type>
void Last_Trival(BinTreeNode<Type> *root)
{
    if (root == nullptr)
        return;

    Last_Trival(root->left);
    Last_Trival(root->right);
    cout << root->val << endl;
}

template<class Type>
Type* find_val(BinTreeNode<Type> *root, Type val)
{
    if (root == nullptr)
        return nullptr;

    BinTreeNode<Type> *cur = root;
    while (cur != nullptr)
    {
        if (cur->val == val)
        {
            return &cur->val;
        }

        if (cur->val > val)
        {
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
    }
    return nullptr;
}

template<class Type>
void clearTree(BinTreeNode<Type> *root)
{
    if (root == nullptr)
        return;

    Last_Trival(root->left);
    Last_Trival(root->right);
    delete root;
}

template<class Type>
BinTreeNode<Type>* FindMin(BinTreeNode<Type>* root)
{
    while (root->left != NULL) root = root->left;
    return root;
}


template<class Type>
BinTreeNode<Type>* Delete(BinTreeNode<Type> *root, Type data) {
    if (root == NULL) return root;
    else if (data < root->val) root->left = Delete(root->left, data);
    else if (data > root->val) root->right = Delete(root->right, data);
    // Wohoo... I found you, Get ready to be deleted	
    else {
        // Case 1:  No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        //Case 2: One child 
        else if (root->left == NULL) {
            BinTreeNode<Type>* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL) {
            BinTreeNode<Type>* temp = root;
            root = root->left;
            delete temp;
        }
        // case 3: 2 children
        else {
            BinTreeNode<Type> *temp = FindMin(root->right);
            root->val = temp->val;
            root->right = Delete(root->right, temp->val);
        }
    }
    return root;
}
