//word28
//以下是一个使用UML演示的最小但完整的链表数据结构的设计：
//------------------------
//|        LinkedList    |
//------------------------
//| - Node* head         |
//| - Node* tail         |
//------------------------
//| + LinkedList()      |
//| + ~LinkedList()     |
//| + isEmpty() const   |
//| + insertFront(data)  |
//| + insertBack(data)   |
//| + removeFront()      |
//| + removeBack()       |
//------------------------
//
//------------------------
//|          Node        |
//------------------------
//| - T data             |
//| - Node* next         |
//------------------------
//| + Node(data)         |
//------------------------
//
//在上述设计中，主要的类是`LinkedList`和`Node`。`LinkedList`类表示链表，它具有私有数据成员`head`和`tail`，这些成员分别指向链表的头部和尾部节点。`Node`类表示链表的节点，它包含了数据成员`data`和指针成员`next`，`next`指向下一个节点。
//
//使用上述设计，我们可以实现一个模板化的链表类：

template<typename T>
class LinkedList {
private:
	struct Node {
		T data;
		Node* next;

		Node(const T& value) { data = value, next = nullptr; }
	};

	Node* head;
	Node* tail;

public:
	LinkedList() { head = nullptr, tail = nullptr; }

	~LinkedList() {
		clear();
	}

	bool isEmpty() const {
		return (head == nullptr);
	}

	void insertFront(const T& data) {
		Node* newNode = new Node(data);
		if (isEmpty()) {
			head = tail = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
	}

	void insertBack(const T& data) {
		Node* newNode = new Node(data);
		if (isEmpty()) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}

	void removeFront() {
		if (!isEmpty()) {
			Node* temp = head;
			head = head->next;
			delete temp;
			if (head == nullptr) {
				tail = nullptr;
			}
		}
	}

	void removeBack() {
		if (!isEmpty()) {
			if (head == tail) {
				delete head;
				head = tail = nullptr;
			}
			else {
				Node* temp = head;
				while (temp->next != tail) {
					temp = temp->next;
				}
				delete tail;
				tail = temp;
				tail->next = nullptr;
			}
		}
	}

	void clear() {
		while (!isEmpty()) {
			removeFront();
		}
	}
};

//在上述代码中，我们使用模板定义了一个`LinkedList`类。该类具有用于插入、删除和清空链表的方法，以及用于检查链表是否为空的方法。
//
//使用上述实现，你可以在`LinkedList`对象上操作并管理一个链表。例如：

void testLL()
{
	LinkedList<int> list;
	list.insertBack(10);
	list.insertBack(20);
	list.insertFront(5);
	list.removeBack();
	list.removeFront();
}

//上述代码片段中，我们创建了一个存储`int`类型元素的链表对象`list`。然后，我们插入了三个元素，删除了最后一个元素和第一个元素。你可以根据需要使用其他类型的元素来实例化`LinkedList`。