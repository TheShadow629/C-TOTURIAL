////word 27
//The run - time performance(Big - O) of the BST's search method is O(log n) on average,
//where n is the number of nodes in the tree. This is because, in a balanced binary search tree,
//each comparison during the search operation eliminates about half of the remaining nodes,
//leading to a logarithmic time complexity.
//
//However, in the worst - case scenario, where the tree is heavily imbalanced, the search
//method's run-time performance can degrade to O(n), linear time complexity, instead of the
//expected O(log n). This worst-case scenario occurs when the tree becomes essentially a linked list,
//with all nodes either only having left children or right children.
//
//For example, consider inserting a sorted sequence of numbers into the BST, such as[1, 2, 3, 4, 5].
//If you insert the numbers in ascending order, the resulting tree will be heavily imbalanced,
//with each node having only a right child.In this case, searching for the maximum number(5) will
//require traversing through all nodes from the root to the rightmost leaf node, which takes O(n) time.
//
//To mitigate this worst - case scenario and maintain the expected O(log n) performance,
//various self - balancing binary search tree algorithms, such as AVL trees or red - black trees,
//are used.These algorithms maintain a balanced tree structure, ensuring that the worst -
//case scenario is avoided and search operations can be performed efficiently.