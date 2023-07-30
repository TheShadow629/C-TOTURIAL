#ifndef BST_H
#define BST_H

#include "NODE.H"

template <class T>

/**
 * @class Binary Search Tree
 * @brief A template binary search tree class.
 *
 * Bst class represents a binary search tree data structure,
 * which supports insertion, search and three types of tree traversal operations.
 *
 * @author Noor Hidayat
 *
 */
class Bst
{
public:
    /**
     * @brief Constructor for Bst.
     */
    Bst();
    /**
     * @brief Destructor for Bst.
     */
    ~Bst();

    /**
     * @brief Inserts data into the binary search tree.
     * @param data The data to be inserted.
     */
    void insert(const T& data);

    /**
     * @brief Searches for a data item in the binary search tree.
     * @param searchItem The data item to search for.
     * @return true if the data item is found, false otherwise.
     */
    bool search(const T& searchItem);

    /**
     * @brief Performs in-order traversal of the binary search tree.
     */
    void inOrder();


    /**
     * @brief Performs in-order traversal of the binary search tree.
     *
     * This function traverses the binary search tree in an in-order
     *
     * @param visit Function pointer to a function that takes a reference to an object of type T.
     * This function is called on each node's data during traversal.
     */
    void inOrder(void(*visit)(T&));

    /**
     * @brief Performs in-order traversal of the binary search tree and insert into tVect.
     *
     * @tparam T The type of elements in the vector.
     *
     * @param visit Function to be applied to each vector item.
     * @param tVect Vector to perform the operation on.
     */
    void inOrder(void(*visit)(T&, Vector<T>&), Vector<T>& tVect);

    /**
     * @brief Performs pre-order traversal of the binary search tree.
     */
    void preOrder();

    /**
     * @brief Performs post-order traversal of the binary search tree.
     */
    void postOrder();

    /**
     * @brief Destroys and release the heap.
     */
    void deleteTree();

    /**
     * @brief Deletes a node and its links.
     */
    void deleteNode(const T& data);


private:
    Node<T>* root;

    void insert(Node<T>*& node, const T& data);
    bool search(Node<T>* node, const T& searchItem);
    void inOrder(Node<T>* node);
    void inOrder(Node<T>* node, void(*visit)(T&));
    void inOrder(Node<T>* node, void(*visit)(T&, Vector<T>&), Vector<T>& tVect);
    void preOrder(Node<T>* node);
    void postOrder(Node<T>* node);
    void deleteFromTree(Node<T>*& node);
    void copyTree(Node<T>*& copiedTreeRoot, Node<T>* otherTreeRoot);
    void deleteNode(Node<T>*& node, const T& data);
};

template <class T>
Bst<T>::Bst()
{
    root = nullptr;
}

template <class T>
Bst<T>::~Bst()
{
    deleteFromTree(root);
}

template <class T>
void Bst<T>::deleteTree()
{
    deleteFromTree(root);
    root = nullptr;
}

template <class T>
void Bst<T>::insert(const T& data)
{
    insert(root, data);
}

template <class T>
void Bst<T>::insert(Node<T>*& node, const T& data)
{

    if (node == nullptr)
    {
        node = new Node<T>(data);
    }
    else if (data < node->data)
    {
        insert(node->left, data);
    }
    else if (data > node->data)
    {
        insert(node->right, data);
    }
}

template <class T>
bool Bst<T>::search(const T& searchItem)
{
    return search(root, searchItem);
}

template <class T>
bool Bst<T>::search(Node<T>* node, const T& searchItem)
{
    if (node == nullptr)
    {
        return false;
    }
    else if (searchItem < node->data)
    {
        return search(node->left, searchItem);
    }
    else if (searchItem > node->data)
    {
        return search(node->right, searchItem);
    }
    else
    {
        return true;
    }
}

template <class T>
void Bst<T>::inOrder()
{
    inOrder(root);
}

template <class T>
void Bst<T>::inOrder(Node<T>* node)
{
    if (node != nullptr)
    {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

template <class T>
void Bst<T>::inOrder(void(*visit)(T&))
{
    inOrder(root, visit);
}

template <class T>
void Bst<T>::inOrder(Node<T>* node, void(*visit)(T&))
{
    if (node != nullptr)
    {
        inOrder(node->left, visit);
        visit(node->data);
        inOrder(node->right, visit);
    }
}

template <class T>
void Bst<T>::inOrder(void(*visit)(T&, Vector<T>&), Vector<T>& tVect)
{
    inOrder(root, visit, tVect);
}

template <class T>
void Bst<T>::inOrder(Node<T>* node, void(*visit)(T&, Vector<T>&), Vector<T>& tVect)
{
    if (node != nullptr)
    {
        inOrder(node->left, visit, tVect);
        visit(node->data, tVect);
        inOrder(node->right, visit, tVect);
    }
}

template <class T>
void Bst<T>::preOrder()
{
    preOrder(root);
}

template <class T>
void Bst<T>::preOrder(Node<T>* node)
{
    if (node != nullptr)
    {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

template <class T>
void Bst<T>::postOrder()
{
    postOrder(root);
}

template <class T>
void Bst<T>::postOrder(Node<T>* node)
{
    if (node != nullptr)
    {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

template <class T>
void Bst<T>::deleteNode(Node<T>*& node, const T& data)
{

    if (node == nullptr) return;

    if (data < node->data)
    {
        deleteNode(node->left, data);
    }

    else if (data > node->data)
    {
        deleteNode(node->right, data);
    }

    // If data is same as node's data
    else
    {
        deleteFromTree(node);
    }
}

template <class T>
void Bst<T>::deleteNode(const T& data)
{
    deleteNode(root, data);
}

template <class T>
void Bst<T>::deleteFromTree(Node<T>*& node)
{
    if (node == nullptr)
    {
        return;
    }
    deleteFromTree(node->left);
    deleteFromTree(node->right);

    delete node;
    node = nullptr;
}

template <class T>
void Bst<T>::copyTree(Node<T>*& copiedTreeRoot, Node<T>* otherTreeRoot)
{
    if (otherTreeRoot == nullptr)
    {
        copiedTreeRoot = nullptr;
    } else {
        copiedTreeRoot = new Node<T>();
        copiedTreeRoot->data = otherTreeRoot->data;
        copyTree(copiedTreeRoot->left, otherTreeRoot->left);
        copyTree(copiedTreeRoot->right, otherTreeRoot->right);
    }
}


#endif // BST_H
