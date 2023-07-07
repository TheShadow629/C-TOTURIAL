#include <iostream>
#include <cstdlib>
#include "assert.h"

template <class T>
class DNode
{
public:
	DNode<T>* next;
	DNode<T>* prev;
	T data;
};

template <class T>
class List
{
public:
	List();//Ĭ�Ϲ��캯��
	List(const List& ln);//�������캯��
	~List();//��������
	void add(T e);//�������������
	void remove(T index);//�Ƴ�ĳ�����
	T find(int index);//���ҽ��
	bool empty();//�ж��Ƿ�Ϊ��
	int size();//������
	void print();//��ʾ����
	void print_reverse();//��������ʾ
	void clear();//ɾ��ȫ�����
private:
	DNode<T>* head;
	DNode<T>* tail;
	int length;
};
//Ĭ�Ϲ��캯��
template <typename T>
List<T>::List()
{
	head = new DNode<T>;
	tail = new DNode<T>;
	head->next = tail;
	head->prev = nullptr;
	tail->next = nullptr;
	tail->prev = head;
	length = 0;
}
//�������캯��
template <typename T>
List<T>::List(const List& ln)
{
	head = new DNode<T>;
	head->prev = nullptr;
	tail = new DNode<T>;
	head->next = tail;
	tail->prev = head;
	length = 0;
	DNode<T>* temp = ln.head;
	while (temp->next != ln.tail)
	{
		temp = temp->next;
		tail->data = temp->data;
		DNode<T>* p = new DNode<T>;
		p->prev = tail;
		tail->next = p;
		tail = p;
		length++;
	}
	tail->next = nullptr;
}
//��������
template <typename T>
List<T>::~List()
{
	if (length == 0)
	{
		delete head;
		delete tail;
		head = nullptr;
		tail = nullptr;
		return;
	}
	while (head->next != nullptr)
	{
		DNode<T>* temp = head;
		head = head->next;
		delete temp;
	}
	delete head;
	head = nullptr;
}
//�������������
template <typename T>
void List<T>::add(T e)
{
	DNode<T>* temp = this->tail;
	tail->data = e;
	tail->next = new DNode<T>;
	DNode<T>* p = tail;
	tail = tail->next;
	tail->prev = p;
	tail->next = nullptr;
	length++;
}
//���ҽ��
template <typename T>
T List<T>::find(int index)
{
	if (length == 0)
	{
		std::cout << "List is empty";
		return NULL;
	}
	if (index >= length)
	{
		std::cout << "Out of bounds";
		return NULL;
	}
	int x = 0;
	DNode<T>* p;
	p = head->next;
	while (p->next != nullptr && x++ != index)
	{
		p = p->next;
	}
		return p->data;
}
//ɾ�����
template <typename T>
void List<T>::remove(T index)
{
	if (length == 0)
	{
		std::cout << "List is empty";
		return;
	}
	DNode<T>* p = head;
	while (p->next != nullptr)
	{
		p = p->next;
		if (p->data == index)
		{
			DNode<T>* temp = p->prev;
			temp->next = p->next;
			p->next->prev = temp;
			delete p;
			length--;
			return;
		}
	}
}
//ɾ�����н��
template <typename T>
void List<T>::clear()
{
	if (length == 0)
	{
		return;
	}
	DNode<T>* p = head->next;
	while (p != tail)
	{
		DNode<T>* temp = p;
		p = p->next;
		delete temp;
	}
	head->next = tail;
	tail->prev = head;
	length = 0;
}
//�ж��Ƿ�Ϊ��
template <typename T>
bool List<T>::empty()
{
	if (length == 0)
	{
		return true;
	}
	else {
		return false;
	}
}
//������
template <typename T>
int List<T>::size()
{
	return length;
}
//�������
template <typename T>
void List<T>::print()
{
	if (length == 0)
	{
		std::cout << "List is empty" << std::endl;
		return;
	}
	DNode<T>* p = head->next;
	while (p != tail)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}
//�����������
template <typename T>
void List<T>::print_reverse()
{
	if (length == 0)return;
	DNode<T>* p = tail->prev;
	while (p != head)
	{
		std::cout << p->data << " ";
		p = p->prev;
	}
	std::cout << std::endl;
}
