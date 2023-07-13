//#pragma once
//#include<stack>
//#include<queue>
//
//template<class T> class BinarySearchTree;
//
////树结点
//template<class T>
//class TreeNode
//{
//public:
//	TreeNode(const T& d) :data(d), left(0), right(0) {};
//	friend class BinarySearchTree<T>;
//private:
//	T data;
//	TreeNode* left;
//	TreeNode* right;
//};
//
//
////二叉查找树BST
//template<class T>
//class BinarySearchTree
//{
//public:
//	BinarySearchTree() :m_root(0) {};
//	~BinarySearchTree() { Clear(); };
//	//递归查找
//	int RecursionSearch(const T&, TreeNode<T>*, int position = 1);
//	//迭代查找
//	bool Search(const T&);
//	bool Insert(const T&);
//
//	void Clear();
//	void PreOrderTraverse() const;
//	void InOrderTraverse() const;
//	void LastOrderTraverse() const;
//
//	TreeNode<T>* GetRoot();
//
//private:
//	TreeNode<T>* m_root; //根节点
//};
//
//template<class T>
//inline int BinarySearchTree<T>::RecursionSearch(const T& node, TreeNode<T>* root, int position)
//{
//	if (nullptr == root)
//		return -1;
//
//
//	if (root->data == node)
//	{
//		return position;
//	}
//	else if (root->data > node)
//	{
//		return RecursionSearch(node, root->left, position * 2);
//	}
//	else
//	{
//		return RecursionSearch(node, root->right, position * 2 + 1);
//	}
//}
//
//template<class T>
//inline bool BinarySearchTree<T>::Search(const T& node)
//{
//	TreeNode<T>* cur = m_root;
//
//	while (cur)
//	{
//		if (cur->data == node)
//			return true;
//		else if (cur->data > node)
//			cur = cur->left;
//		else
//			cur = cur->right;
//	}
//
//	return false;
//}
//
//template<class T>
//inline bool BinarySearchTree<T>::Insert(const T& node)
//{
//	if (m_root == nullptr)
//	{
//		m_root = new TreeNode<T>(node);
//		return true;
//	}
//
//	TreeNode<T>* cur = m_root;
//	TreeNode<T>* pre = nullptr;
//
//	while (cur)
//	{
//		pre = cur;
//		if (cur->data == node)
//			return false;
//		else if (cur->data > node)
//			cur = cur->left;
//		else
//			cur = cur->right;
//	}
//
//	cur = new TreeNode<T>(node);
//
//	if (pre->data > node)
//		pre->left = cur;
//	else
//		pre->right = cur;
//
//	return true;
//}
//
//template<class T>
//inline void BinarySearchTree<T>::Clear()  //层次遍历
//{
//	if (m_root == nullptr)
//		return;
//
//	TreeNode<T>* cur;
//	std::queue<TreeNode<T>*> q;
//	q.push(m_root);
//
//	std::cout << "层次遍历 : ";
//	while (!q.empty())
//	{
//		int size = q.size();
//
//		while (size--)
//		{
//			cur = q.front();
//			q.pop();
//			std::cout << cur->data << " ";
//
//			if (cur->left) q.push(cur->left);
//			if (cur->right) q.push(cur->right);
//
//			delete cur;
//		}
//	}
//	std::cout << std::endl;
//}
//
//template<class T>
//inline void BinarySearchTree<T>::PreOrderTraverse() const
//{
//	if (m_root == nullptr)
//		return;
//
//	TreeNode<T>* cur;
//	std::stack<TreeNode<T>*> st;
//	st.push(m_root);
//
//	std::cout << "先序遍历 : ";
//
//	while (!st.empty())
//	{
//		cur = st.top();
//		st.pop();
//		std::cout << cur->data << " ";
//
//		if (cur->right)
//		{
//			st.push(cur->right);
//		}
//		if (cur->left)
//		{
//			st.push(cur->left);
//		}
//	}
//	std::cout << std::endl;
//}
//
//template<class T>
//inline void BinarySearchTree<T>::InOrderTraverse() const
//{
//	if (m_root == nullptr)
//		return;
//
//	TreeNode<T>* cur = m_root;
//	std::stack<TreeNode<T>*> st;
//
//	std::cout << "中序遍历 : ";
//
//	while (!st.empty() || cur != nullptr)
//	{
//
//		while (cur)
//		{
//			st.push(cur);
//			cur = cur->left;
//		}
//
//		cur = st.top();
//		st.pop();
//
//		std::cout << cur->data << " ";
//		cur = cur->right;
//	}
//
//	std::cout << std::endl;
//}
//
//template<class T>
//inline void BinarySearchTree<T>::LastOrderTraverse() const
//{
//	if (m_root == nullptr)
//		return;
//
//	TreeNode<T>* cur = m_root;
//	std::stack<TreeNode<T>*> st;
//
//	std::cout << "后序遍历 : ";
//
//	while (!st.empty() || cur)
//	{
//		while (cur)
//		{
//			st.push(cur);
//			cur = cur->left ? cur->left : cur->right;
//		}
//
//		cur = st.top();
//		st.pop();
//
//		std::cout << cur->data << " ";
//
//		if (!st.empty() && st.top()->left == cur)
//		{
//			cur = st.top()->right;
//		}
//		else
//		{
//			cur = nullptr;
//		}
//
//	}
//	std::cout << std::endl;
//}
//
//template<class T>
//inline TreeNode<T>* BinarySearchTree<T>::GetRoot()
//{
//	return m_root;
//}
//
