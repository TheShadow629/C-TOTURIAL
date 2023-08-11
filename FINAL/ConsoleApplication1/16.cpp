#include <iostream>

template<typename T>
class BinarySearchTree {
private:
	struct Node {
		T data;
		Node* left;
		Node* right;

		Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
	};

	Node* root;

public:
	BinarySearchTree() : root(nullptr) { }

	~BinarySearchTree() {
		DestroyTree(root);
	}

	void Insert(const T& value) {
		if (root == nullptr) {
			root = new Node(value);
		}
		else {
			InsertNode(root, value);
		}
	}

	bool Search(const T& value) const {
		return SearchNode(root, value);
	}

	BinarySearchTree(const BinarySearchTree& other) {
		root = CopyTree(other.root);
	}

	BinarySearchTree& operator=(const BinarySearchTree& other) {
		if (this != &other) {
			DestroyTree(root);
			root = CopyTree(other.root);
		}
		return *this;
	}

	void InorderTraversal() const { InorderTraversal(root); }

	void PreorderTraversal() const {
		PreorderTraversal(root);
	}

	void PostorderTraversal() const {
		PostorderTraversal(root);
	}

private:
	void DestroyTree(Node* node) {
		if (node != nullptr) {
			DestroyTree(node->left);
			DestroyTree(node->right);
			delete node;
			node = nullptr;
		}
	}

	void InsertNode(Node* node, const T& value) {
		if (value < node->data) {
			if (node->left == nullptr) {
				node->left = new Node(value);
			}
			else {
				InsertNode(node->left, value);
			}
		}
		else {
			if (node->right == nullptr) {
				node->right = new Node(value);
			}
			else {
				InsertNode(node->right, value);
			}
		}
	}

	bool SearchNode(Node* node, const T& value) const {
		if (node == nullptr) {
			return false;
		}
		else if (value == node->data) {
			return true;
		}
		else if (value < node->data) {
			return SearchNode(node->left, value);
		}
		else {
			return SearchNode(node->right, value);
		}
	}

	Node* CopyTree(const Node* node) {
		if (node == nullptr) {
			return nullptr;
		}

		Node* newNode = new Node(node->data);
		newNode->left = CopyTree(node->left);
		newNode->right = CopyTree(node->right);
		return newNode;
	}

	void InorderTraversal(Node* node) const
	{
		if (node != nullptr) {
			InorderTraversal(node->left);
			std::cout << node->data << " ";
			InorderTraversal(node->right);
		}
	}

	void PreorderTraversal(Node* node) const {
		if (node != nullptr) {
			std::cout << node->data << " ";
			PreorderTraversal(node->left);
			PreorderTraversal(node->right);
		}
	}

	void PostorderTraversal(Node* node) const {
		if (node != nullptr) {
			PostorderTraversal(node->left);
			PostorderTraversal(node->right);
			std::cout << node->data << " ";
		}
	}
};

class Date {
private:
	int m_Day;
	int m_Month;
	int m_Year;

public:
	int GetDay() const;
	void SetDay(const int day);
	int GetMonth() const;
	void SetMonth(const int month);
	int GetYear() const;
	void SetYear(const int year);
	Date(int d, int m, int y) : m_Day(d), m_Month(m), m_Year(y) {}

	bool operator<(const Date& other) const;
	bool operator==(const Date& other) const;
};

bool Date::operator<(const Date& other) const {
	if (m_Year < other.m_Year) {
		return true;
	}
	else if (m_Year == other.m_Year) {
		if (m_Month < other.m_Month) {
			return true;
		}
		else if (m_Month == other.m_Month) {
			return m_Day < other.m_Day;
		}
	}
	return false;
}

bool Date::operator==(const Date& other) const {
	return (m_Year == other.m_Year && m_Month == other.m_Month && m_Day == other.m_Day);
}

int Date::GetDay() const
{
	return m_Day;
}

void Date::SetDay(const int day)
{
	this->m_Day = day;
}

int Date::GetMonth() const
{
	return m_Month;
}

void Date::SetMonth(const int month)
{
	this->m_Month = month;
}

int Date::GetYear() const
{
	return m_Year;
}

void Date::SetYear(const int year)
{
	this->m_Year = year;
}

int main()
{
	BinarySearchTree<int> bst;
	bst.Insert(5);
	bst.Insert(3);
	bst.Insert(7);
	bst.Insert(1);
	bst.Insert(4);
	bst.Insert(6);
	bst.Insert(8);

	BinarySearchTree<int> bst1;
	bst1 = bst;
	bst.InorderTraversal();
	std::cout << std::endl;
	bst1.InorderTraversal();
	std::cout << std::endl;
	std::cout << "Searching for 3: " << (bst.Search(3) ? "Found" : "Not found") << std::endl;
	std::cout << "Searching for 10: " << (bst.Search(10) ? "Found" : "Not found") << std::endl;

	BinarySearchTree<Date> dateBST;
	dateBST.Insert(Date(15, 2, 2022));
	dateBST.Insert(Date(10, 1, 2023));
	dateBST.Insert(Date(20, 12, 2021));

	Date searchDate(10, 1, 2023);
	std::cout << "Searching for " << searchDate.GetDay() << "/" << searchDate.GetMonth() << "/" << searchDate.GetYear()
		<< ": " << (dateBST.Search(searchDate) ? "Found" : "Not found") << std::endl;

	return 0;
}
