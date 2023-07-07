#include <stdexcept>
template<class T>
class Stack;//堆栈类的声明

template<class T>
class Node { //节点类
	friend class Stack<T>; //定义友元类
private:
	T data; //数据域
	Node<T>* next;//指针域
	Node() {}//构造方法
};

template<class T>
class Stack { //堆栈类的实现
public:
	Stack();//构造方法
	~Stack();//析构函数
	void Push(const T& x);//入栈
	T Pop();//出栈
	T Top()const;//查看栈顶数据
	bool IsEmpty()const;//判断栈是否为空
	bool IsFull()const;//判断栈是否已满
private:
	Node<T>* top; //栈顶指针
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
	if (!IsFull()) { //判断链表是否已满
		Node<T>* pt = new Node<T>(); //创建节点
		pt->data = x; //指定数据域数值
		Node<T>* temp = top;
		top = pt;
		pt->next = temp; //至此，入栈完成
	}
	else { //栈已满，抛出异常
		throw "the stack is full!";
	}
}

template<class T>
T Stack<T>::Pop() {
	if (!IsEmpty()) { //栈不为空
		Node<T>* temp = top; //保存top指针现有的节点
		top = top->next;//右移top指针
		T temp_data = temp->data;//取出temp节点中的数据
		delete temp;//释放temp节点的空间
		return temp_data; //返回数据
	}
	else { //栈为空
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
		Node<T>* p = new Node<T>(); //表名是否还能创建节点，如果不能，new引发NoMem异常。
		delete p;//删除创建的节点
		return false;//能够创建节点，栈未满
	}
	catch (std::exception e) {//引发NoMem异常，说明内存已满
		return true;
	}
}

