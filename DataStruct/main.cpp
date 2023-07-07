#include "DLinkList.h"
#include "LinkList.h"
#include "SeqList.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>
using namespace std;

int SeqListTest()
{
	std::cout << "***顺序表***" << std::endl;
	SeqList<int> seqList;
	int val = -1;
	int iLocate = -1;
	for (int i = 0; i < 10; i++)
	{
		seqList.Insert(i, i + 1);
	}
	seqList.Print();
	val = seqList.Get(3);
	std::cout << "seqList.Get(3): " << val << std::endl;
	val = seqList.Delete(2);
	std::cout << "seqList.Delete(2): " << val << std::endl;
	seqList.Print();
	iLocate = seqList.Locate(5);
	std::cout << "seqList.Locate(5): " << val << std::endl;
	std::cout << std::endl;
	return 0;
}

int LinkListTest()
{
	std::cout << "***单链表***" << std::endl;
	int a = 0;
	int* p = &a;
	LinkList<int> linkList;
	linkList.insert(0, 5);
	linkList.insert(1, 4);
	linkList.insert(2, 12);
	linkList.insert(3, 5);
	linkList.insert(3, 6);
	linkList.insert(1, 7);
	std::cout << "链表长度" << linkList.length() << std::endl;
	std::cout << "各个元素的值是: ";
	for (int i = 0; i < linkList.length(); i++)//遍历该链表
	{
		if (linkList.getElem(i, *p))
			std::cout << *p << "   ";
	}
	std::cout << std::endl;
	std::cout << "反转后各个元素的值是: ";
	LNode<int>* re_linkList = linkList.reverse();
	while (re_linkList)
	{
		std::cout << re_linkList->data << "   ";
		re_linkList = re_linkList->next;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	return 0;
}

int DLinkListTest()
{
	std::cout << "***双向链表***" << std::endl;

	List<int> list;
	list.add(6);
	list.add(443);
	list.add(767);
	list.add(56);

	List<int> list2(list);
	list2.print_reverse();
	list2.print();
	std::cout << "list2.size(): " << list2.size() << std::endl;
	std::cout << "list2.find(2): " << list2.find(2) << std::endl;
	list2.remove(443);
	list2.print();
	return 0;

}

int StackTest()
{
	Stack<int> mystack;
	cout << mystack.IsFull() << endl;
	cout << mystack.IsEmpty() << endl;
	cout << "入栈" << endl;
	mystack.Push(50);
	mystack.Push(25);
	mystack.Push(30);
	mystack.Push(31);
	mystack.Push(45);
	mystack.Push(0);
	cout << mystack.IsFull() << endl;
	cout << mystack.IsEmpty() << endl;
	cout << "....." << endl;
	cout << "出栈" << endl;
	cout << "data is " << mystack.Pop() << endl;
	cout << "data is " << mystack.Pop() << endl;
	cout << "data is " << mystack.Pop() << endl;
	cout << "data is " << mystack.Pop() << endl;
	cout << "data is " << mystack.Pop() << endl;
	cout << "data is " << mystack.Top() << endl;
	cout << "data is " << mystack.Pop() << endl;
	cout << mystack.IsFull() << endl;
	cout << mystack.IsEmpty() << endl;
	return 0;
}

int QueueTest() {
	Queue<int> queue;
	int n=10;
	for (int i = 0; i < n; i++) {
		queue.push_back(i);
	}
	//you have to judge if queue is empty before using this font node
	while (queue.empty() == false) {
		cout << queue.front() << endl;
		queue.pop();
	}
	return 0;
}

int SetTest()
{
	return 0;
}

int MapTest()
{
	return 0;
}

int main(int argc, char** argv)
{
	LinkListTest();
	DLinkListTest();
	StackTest();
	SetTest();
	MapTest();
	QueueTest();
	return 0;
}