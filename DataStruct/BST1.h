#include <iostream>
using namespace std;

// ����һ���ڵ�
template <class T>
struct BSTNode {
	T _val;
	BSTNode<T>* _left;
	BSTNode<T>* _right;

	// ����
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

	// ���Һ���
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
		return nullptr;  // δ�ҵ������ؿ�
	}

	// ���롣 ֻ�ܲ��뵽��Ϊ 0 �� 1 �Ľڵ��У�ֻ�в����Ƿ�ɹ��������� bool ��������. 
	bool insert(const T& val) {
		// �ж��Ƿ�Ϊ������ �ǿ��������� val ����(node)һ����
		if (_root == nullptr) {
			_root = new Node(val);
		}
		Node* cur = _root;
		Node* parent = nullptr;
		// �Ȳ���
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
		// while �����ˣ�û�� val �ڵ㣬�ʹ���һ����
		cur = new Node(val);
		// �ж� cur Ӧ�÷��� parent ����һ��
		if (parent->_val < val) {
			parent->_right = cur;
		}
		else {
			parent->_left = cur;
		}
		return true;
	}

	bool erase(const T& val) {
		// ɾ��
		// ������� Ҷ�ӽڵ� ����Ϊ��  �Һ���Ϊ��  ��Ϊ 2 �Ľڵ�
		//1. ɾ��Ҷ�ӽڵ�
		// �Ȳ���
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
		if (cur == nullptr) {  // û�ҵ�Ҫɾ���Ľڵ�
			return false;
		}
		// ��� cur ��Ҷ�ӽڵ�
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
			delete cur; // �ͷ� cur�� �Է��ڴ�й© 
		}
		// ����Ϊ��
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
		// �Һ���Ϊ��
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
		// ���Һ��Ӷ�����
		else {
			Node* leftMostChid = cur->_right;
			Node* parent = cur;
			while (leftMostChid->_left) {
				parent = leftMostChid;
				leftMostChid = leftMostChid->_left;
			}
			cur->_val = leftMostChid->_val;
			// �ж�����ֵ�ڸ��׵���߻����ұ�,  ��nullptr�Ǿͽ�nullptr
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
	// ���������ʾ���
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

	// Ĭ�Ϲ���
	BSTree() :_root(nullptr) {};

	// ��������
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

	//��������
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
	// ��ֵ�����
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
	// ����
	BSTree<int> p(bst);
	p.inorder();
	// ɾ��
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