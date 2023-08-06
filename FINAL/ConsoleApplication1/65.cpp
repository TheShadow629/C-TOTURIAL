//The order(Big - O) for the search / find algorithms in different data structures can vary.Let's consider
//the three data structures you mentioned: vector, linked list, and binary search tree.
//
//1. Vector:
//-Search / Find algorithm : The vector is an array - like structure with contiguous memory, and searching
//requires iterating through the elements.In an unsorted vector, the search algorithm typically has a linear
//time complexity.
//- Order : O(n)
//
//2. Linked List :
//-Search / Find algorithm : In a linked list, each element contains a pointer to the next element, making
//sequential access necessary.In an unsorted linked list, the search algorithm also has a linear time complexity.
//- Order : O(n)
//
//3. Binary Search Tree(BST) :
//	-Search / Find algorithm : A BST is a binary tree structure where all elements to the left of a node are
//	smaller, and all elements to the right are larger.In an unbalanced or randomly built BST, the worst - case
//	search time becomes linear, similar to a linked list or vector.
//	- Order: O(n)
//	However, if the binary search tree is balanced(e.g., AVL tree, red - black tree), the search time can be
//	significantly improved.In a balanced BST, the search algorithm has a logarithmic time complexity.
//	- Order : O(log n)
//	In summary, for unsorted data, the search algorithm for a vector, linked list, and unbalanced binary search
//	tree all have linear time complexity(O(n)).However, a balanced binary search tree can achieve a logarithmic
//	time complexity of O(log n) for search operations.

/*对于这三种数据结构：向量（vector），链表（linked list）和二叉搜索树（binary search tree），它们在搜索/查找操作的时间复杂度（大O表示法）上是不同的。

1. 向量（Vector）：
   - 搜索/查找算法：向量是一种类似于数组的结构，需要通过遍历元素来进行搜索。在未排序的向量中，搜索算法通常具有线性时间复杂度。
   - 时间复杂度：O(n)

2. 链表（Linked List）：
   - 搜索/查找算法：链表中的每个元素都包含指向下一个元素的指针，因此需要按顺序访问元素。在未排序的链表中，
   搜索算法同样具有线性时间复杂度。
   - 时间复杂度：O(n)

3. 二叉搜索树（BST）：
   - 搜索/查找算法：二叉搜索树是一种二叉树结构，其中左子节点的值都小于根节点，右子节点的值都大于根节点。
   在未平衡的或随机构建的二叉搜索树中，最坏情况下的搜索时间复杂度变为线性，类似于链表或向量。
   - 时间复杂度：O(n)

然而，如果二叉搜索树是平衡的（如AVL树、红黑树），搜索时间可以大幅提高。在平衡的二叉搜索树中，搜索算法具有对数时间复杂度。
   - 时间复杂度：O(log n)

总结起来，对于未排序的数据，向量、链表和未平衡的二叉搜索树的搜索算法都具有线性时间复杂度（O(n)）。
然而，平衡的二叉搜索树可以实现对数时间复杂度的搜索操作（O(log n)）。*/