//word28
//������һ��ʹ��UML��ʾ����С���������������ݽṹ����ƣ�
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
//����������У���Ҫ������`LinkedList`��`Node`��`LinkedList`���ʾ����������˽�����ݳ�Ա`head`��`tail`����Щ��Ա�ֱ�ָ�������ͷ����β���ڵ㡣`Node`���ʾ����Ľڵ㣬�����������ݳ�Ա`data`��ָ���Ա`next`��`next`ָ����һ���ڵ㡣
//
//ʹ��������ƣ����ǿ���ʵ��һ��ģ�廯�������ࣺ

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

//�����������У�����ʹ��ģ�嶨����һ��`LinkedList`�ࡣ����������ڲ��롢ɾ�����������ķ������Լ����ڼ�������Ƿ�Ϊ�յķ�����
//
//ʹ������ʵ�֣��������`LinkedList`�����ϲ���������һ���������磺

void testLL()
{
	LinkedList<int> list;
	list.insertBack(10);
	list.insertBack(20);
	list.insertFront(5);
	list.removeBack();
	list.removeFront();
}

//��������Ƭ���У����Ǵ�����һ���洢`int`����Ԫ�ص��������`list`��Ȼ�����ǲ���������Ԫ�أ�ɾ�������һ��Ԫ�غ͵�һ��Ԫ�ء�����Ը�����Ҫʹ���������͵�Ԫ����ʵ����`LinkedList`��