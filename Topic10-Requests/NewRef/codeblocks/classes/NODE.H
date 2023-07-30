#ifndef NODE_H
#define NODE_H

template<class T>

/**
 * @class Node
 * @brief Node class used in Binary Search Tree (BST) implementation
 *
 * The Node class is a templated class that contains data of type T and pointers to left and right child nodes.
 * It is used as a building block in the BST implementation.
 *
 * @tparam T Type of the data that will be stored in the Node

 * @author Noor Hidayat
 *
 */
class Node
{
    public:
        /**
         * @brief Constructor for Node.
         */
        Node();

        /**
         * @brief Parameterized constructor for Node
         *
         * Initializes the data member with the provided value and left and right child pointers to nullptr.
         *
         * @param data Initial value to be stored in the node
         */
        Node(const T& data);

        // Data of generic data type T
        T data;
        // Node pointer to generic data type T
        Node<T>* left;
        // Node pointer to generic data type T
        Node<T>* right;

};

template<class T>
Node<T>::Node()
{
    // cstr
    left = nullptr;
    right = nullptr;
}


template<class T>
Node<T>::Node(const T& data)
{
    this->data = data;
    left = nullptr;
    right = nullptr;
}

#endif // NODE_H

