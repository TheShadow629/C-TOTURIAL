#pragma once
template<class T>
class Queue;//��ջ�������

template<class T>
class QNode { //�ڵ���
	friend class Queue<T>; //������Ԫ��
private:
	T data; //������
	QNode<T>* next;//ָ����
	QNode() {}//���췽��
};

template<class T>
class Queue {
	int size;
	QNode<T>* head; //pointer to the font node
	QNode<T>* back;	//pointer to the least node
public:
	Queue();
	bool empty();
	T front();
	void push_back(const T& v);
	void pop();
};

template<class T>
Queue<T>::Queue() {
	size = 0;
	head = back = NULL;
}

template<class T>
bool Queue<T>::empty() {
	return size == 0;
}


template<class T>
T Queue<T>::front() {
	return head->data;
}

template<class T>
void Queue<T>::push_back(const T& v) {
	QNode<T>* pt = new QNode<T>(); //�����ڵ�
	pt->data = v;

	if (size == 0) {
		head = pt;
		back = pt;
		head->next = pt;
	}
	else if (size == 1) {
		head->next = back = pt;
	}
	else {
		back->next =pt;
		back = back->next;
	}
	size++;
	//return back;
}

template<class T>
void Queue<T>::pop() {
	if (empty()) return;
	QNode<T>* temp = head;
	head = head->next;
	delete temp;
	size--;
}


