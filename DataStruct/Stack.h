#include <stdexcept>
template<class T>
class Stack;//��ջ�������

template<class T>
class Node { //�ڵ���
	friend class Stack<T>; //������Ԫ��
private:
	T data; //������
	Node<T>* next;//ָ����
	Node() {}//���췽��
};

template<class T>
class Stack { //��ջ���ʵ��
public:
	Stack();//���췽��
	~Stack();//��������
	void Push(const T& x);//��ջ
	T Pop();//��ջ
	T Top()const;//�鿴ջ������
	bool IsEmpty()const;//�ж�ջ�Ƿ�Ϊ��
	bool IsFull()const;//�ж�ջ�Ƿ�����
private:
	Node<T>* top; //ջ��ָ��
};

template<class T>
Stack<T>::Stack() {
	top = NULL;
}

template<class T>
Stack<T>::~Stack() {
	Node<T>* temp = NULL;
	while (top != NULL) {
		temp = top->next;
		delete top;
		top = temp;
	}
}

template<class T>
void Stack<T>::Push(const T& x) {
	if (!IsFull()) { //�ж������Ƿ�����
		Node<T>* pt = new Node<T>(); //�����ڵ�
		pt->data = x; //ָ����������ֵ
		Node<T>* temp = top;
		top = pt;
		pt->next = temp; //���ˣ���ջ���
	}
	else { //ջ�������׳��쳣
		throw "the stack is full!";
	}
}

template<class T>
T Stack<T>::Pop() {
	if (!IsEmpty()) { //ջ��Ϊ��
		Node<T>* temp = top; //����topָ�����еĽڵ�
		top = top->next;//����topָ��
		T temp_data = temp->data;//ȡ��temp�ڵ��е�����
		delete temp;//�ͷ�temp�ڵ�Ŀռ�
		return temp_data; //��������
	}
	else { //ջΪ��
		throw "the stack is empty!";
	}
}

template<class T>
T Stack<T>::Top()const {
	return top->data;
}

template<class T>
bool Stack<T>::IsEmpty()const {
	return top == NULL;
}

template<class T>
bool Stack<T>::IsFull()const {
	try {
		Node<T>* p = new Node<T>(); //�����Ƿ��ܴ����ڵ㣬������ܣ�new����NoMem�쳣��
		delete p;//ɾ�������Ľڵ�
		return false;//�ܹ������ڵ㣬ջδ��
	}
	catch (std::exception e) {//����NoMem�쳣��˵���ڴ�����
		return true;
	}
}

