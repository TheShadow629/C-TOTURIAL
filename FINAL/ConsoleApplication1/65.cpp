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

/*�������������ݽṹ��������vector��������linked list���Ͷ�����������binary search tree��������������/���Ҳ�����ʱ�临�Ӷȣ���O��ʾ�������ǲ�ͬ�ġ�

1. ������Vector����
   - ����/�����㷨��������һ������������Ľṹ����Ҫͨ������Ԫ����������������δ����������У������㷨ͨ����������ʱ�临�Ӷȡ�
   - ʱ�临�Ӷȣ�O(n)

2. ����Linked List����
   - ����/�����㷨�������е�ÿ��Ԫ�ض�����ָ����һ��Ԫ�ص�ָ�룬�����Ҫ��˳�����Ԫ�ء���δ����������У�
   �����㷨ͬ����������ʱ�临�Ӷȡ�
   - ʱ�临�Ӷȣ�O(n)

3. ������������BST����
   - ����/�����㷨��������������һ�ֶ������ṹ���������ӽڵ��ֵ��С�ڸ��ڵ㣬���ӽڵ��ֵ�����ڸ��ڵ㡣
   ��δƽ��Ļ���������Ķ����������У������µ�����ʱ�临�Ӷȱ�Ϊ���ԣ������������������
   - ʱ�临�Ӷȣ�O(n)

Ȼ�������������������ƽ��ģ���AVL�����������������ʱ����Դ����ߡ���ƽ��Ķ����������У������㷨���ж���ʱ�临�Ӷȡ�
   - ʱ�临�Ӷȣ�O(log n)

�ܽ�����������δ��������ݣ������������δƽ��Ķ����������������㷨����������ʱ�临�Ӷȣ�O(n)����
Ȼ����ƽ��Ķ�������������ʵ�ֶ���ʱ�临�Ӷȵ�����������O(log n)����*/