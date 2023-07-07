#include <iostream>
#include <cstdlib>
#include "assert.h"

template <typename T>
class LNode
{
public:
	T data;
	LNode<T>* next;
};

template <class T>
class LinkList {
public:
	LinkList() { head = nullptr; }
	~LinkList();
	bool clear();
	bool empty() { return head == nullptr; };
	int length();
	bool getElem(int i, T& t);
	int locateElem(const T& t);
	bool priorElem(const T& t_cur, T& t_pre);
	bool nextElem(const T& t_cur, T& t_next);
	bool insert(int i, T t);
	bool term(int i, T t);
	LNode<T>* reverse();
private:
	LNode<T>*head;
};

//清空函数
template <class T>
bool LinkList<T>::clear() {
	LNode<T>* p = head;
	while (head) {
		p = head;
		head = head->next;
		delete(p);
	}
	return true;
}

//析构函数
template <class T>
LinkList<T>::~LinkList() {
	clear();
}

//获取链表长度
template <class T>
int LinkList<T>::length() {
	LNode<T>* p = head;    //不能直接用head循环
	int len = 0;
	while (p != nullptr) {
		len++;
		p = p->next;
	}
	return len;
}

//获取指定位置元素
template <class T>
bool LinkList<T>::getElem(int i, T& t) {
	int j = 0;
	LNode<T>* p = head;
	while (j < i && p) {
		p = p->next;
		j++;
	}
	if (p == nullptr) return false;
	t = p->data;
	return true;
}

//查找元素位置
template <class T>
int LinkList<T>::locateElem(const T& t) {
	int loc = 0;
	LNode<T>* p = head;
	while (p->data != t && p) {
		p = p->next;
		loc++;
	}
	if (p->data == t) return loc;
	else return -1;
}

//获取前驱节点
template <class T>
bool LinkList<T>::priorElem(const T& t_cur, T& t_pre) {
	LNode<T>* p = head;
	if (p->data == t_cur) return false;
	while (p->next->data != t_cur && p->next) {
		p = p->next;
	}
	if (p->next->data == t_cur) {
		t_pre = p->data;
		return true;
	}

	return false;
}

//获取后继节点
template <class T>
bool LinkList<T>::nextElem(const T& t_cur, T& t_next) {
	LNode<T>* p = head;
	if (head == nullptr || head->next == nullptr) return false;
	while (p->next != nullptr) {
		if (p->data == t_cur)
		{
			t_next = p->next->data;
			return true;
		}
		else
			p = p->next;
	}
	return false;
}

template <class T>
bool LinkList<T>::insert(int i, T t) {
	LNode<T>* p = head;
	LNode<T>* s = head;
	int loc = 0;
	if (i == 0) {
		s = (LNode<T>*)malloc(sizeof(LNode<T>));
		s->data = t;
		s->next = p;
		head = s;
		return true;
	}
	while (p && loc < i - 1) {
		p = p->next;
		loc++;
	}
	if (p == nullptr)
		return false;
	s = (LNode<T>*)malloc(sizeof(LNode<T>));
	s->data = t;
	s->next = p->next;
	p->next = s;
	return true;
}

//删除指定位置元素
template <class T>
bool LinkList<T>::term(int i, T t) {
		LNode<T>*p = head;
	int loc = 0;
	if (i == 0) {
		t = head->data;
		head = head->next;
		delete p;
		p = nullptr;
		return true;
	}
	while (p && loc < i - 1) {
		loc++;
		p = p->next;
	}
	if (p == nullptr)
		return false;
		LNode * s;
	s = p->next;
	p->next = p->next->next;
	t = s->data;
	delete s;
	s = NULL;
	return true;
}

//反转链表
template <class T>
LNode<T>* LinkList<T>::reverse() {
	if (head == nullptr || head->next == nullptr) return head;
	LNode<T>* p = head, * q = head->next, * r;
	head->next = nullptr;
	while (q) {
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	head = p;
	return head;
}
