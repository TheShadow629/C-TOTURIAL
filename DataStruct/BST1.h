#include <iostream>
using namespace std;

// 创建一个节点
template <class T>
struct BSTNode {
	T _val;
	BSTNode<T>* _left;
	BSTNode<T>* _right;

	// 构造
	BSTNode(const T& val = T())
		:_val(val)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

template <class T>
class BSTree {
public:
	typedef BSTNode<T> Node;

	// 查找函数
	Node* find(const T& val) {
		Node* cur = _root;
		while (cur) {
			if (cur->_val == val) {
				return cur;
			}
			if (cur->_val < val) {
				cur = cur->_right;
			}
			if (cur->_val > val) {
				cur = cur->_left;
			}
		}
		return nullptr;  // 未找到，返回空
	}

	// 插入。 只能插入到度为 0 或 1 的节点中，只有插入是否成功，所有用 bool 数据类型. 
	bool insert(const T& val) {
		// 判断是否为空树， 是空树，则用 val 创建(node)一个树
		if (_root == nullptr) {
			_root = new Node(val);
		}
		Node* cur = _root;
		Node* parent = nullptr;
		// 先查找
		while (cur) {
			parent = cur;
			if (cur->_val == val) {
				return false;
			}
			else if (cur->_val < val) {
				cur = cur->_right;
			}
			else {
				cur = cur->_left;
			}
		}
		// while 走完了，没有 val 节点，就创建一个吧
		cur = new Node(val);
		// 判断 cur 应该放在 parent 的那一边
		if (parent->_val < val) {
			parent->_right = cur;
		}
		else {
			parent->_left = cur;
		}
		return true;
	}

	bool erase(const T& val) {
		// 删除
		// 四种情况 叶子节点 左孩子为空  右孩子为空  度为 2 的节点
		//1. 删除叶子节点
		// 先查找
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur) {
			if (cur->_val == val) {
				break;
			}
			if (cur->_val < val) {
				parent = cur;
				cur = cur->_right;
			}
			if (cur->_val > val) {
				parent = cur;
				cur = cur->_left;
			}
		}
		if (cur == nullptr) {  // 没找到要删除的节点
			return false;
		}
		// 如果 cur 是叶子节点
		if (cur->_left == nullptr && cur->_left == nullptr) {
			if (cur == _root) {
				_root = nullptr;
			}
			else {
				if (parent->_right == cur) {
					parent->_right = nullptr;
				}
				else {
					parent->_left = nullptr;
				}

			}
			delete cur; // 释放 cur， 以防内存泄漏 
		}
		// 左孩子为空
		else if (cur->_left == nullptr) {
			if (cur == _root) {
				_root = cur->_right;
			}
			else {
				if (parent->_right == cur) {
					parent->_right = cur->_right;
				}
				else if (parent->_left == cur) {
					parent->_left = cur->_right;
				}
			}
			delete cur;
		}
		// 右孩子为空
		else if (cur->_right == nullptr) {
			if (cur == _root) {
				_root = cur->_left;
			}
			else {
				if (parent->_left == cur) {
					parent->_left = cur->_left;
				}
				else {
					parent->_right = cur->_left;
				}
			}
			delete cur;
		}
		// 左右孩子都存在
		else {
			Node* leftMostChid = cur->_right;
			Node* parent = cur;
			while (leftMostChid->_left) {
				parent = leftMostChid;
				leftMostChid = leftMostChid->_left;
			}
			cur->_val = leftMostChid->_val;
			// 判断最左值在父亲的左边还是右边,  有nullptr那就接nullptr
			if (parent->_left = cur) {
				parent->_left = leftMostChid->_right;
			}
			else {
				parent->_right = leftMostChid->_right;
			}
			delete leftMostChid;
		}
		return true;
	}
	// 中序遍历显示结果
	void inorder() {
		_inorder(_root);
		cout << endl;
	}
	void _inorder(Node* root) {
		if (root) {
			_inorder(root->_left);
			cout << root->_val << ' ';
			_inorder(root->_right);
		}
	}

	// 默认构造
	BSTree() :_root(nullptr) {};

	// 拷贝构造
	Node* copyTree(Node* root) {
		if (root) {
			Node* cur = new Node(root->_val);
			cur->_left = copyTree(root->_left);
			cur->_right = copyTree(root->_right);
			return cur;
		}
		return nullptr;
	}

	BSTree(const BSTree<T>& bst) :_root(nullptr) {
		_root = copyTree(bst._root);
	}

	//析构函数
	void destory(Node* root) {
		if (root) {
			destory(root->_left);
			destory(root->_right);
			delete root;
		}
	}
	~BSTree() {
		destory(_root);
	}
	// 赋值运算符
	BSTree<T>& operator=(BSTree<T> bst)
	{
		swap(_root, bst._root);
		return *this;
	}

private:
	Node* _root = nullptr;
};

void test() {
	BSTree <int> bst;
	bst.insert(0);
	bst.insert(5);
	bst.insert(6);
	bst.insert(3);
	bst.insert(7);
	bst.insert(1);
	bst.inorder();
	// 拷贝
	BSTree<int> p(bst);
	p.inorder();
	// 删除
	bst.erase(3);
	bst.inorder();
	bst.erase(6);
	bst.inorder();
}

int main() {
	test();
	system("pause");
	return 0;
}