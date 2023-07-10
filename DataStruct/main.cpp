#include "DLinkList.h"
#include "LinkList.h"
#include "SeqList.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>
#include <set>
#include <map> 
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
	//https://blog.csdn.net/qq_42185999/article/details/107031098
	//set 翻译为集合，是一个内部自动有序且不含重复元素的容器。
	//当出现需要去掉重复元素的情况，而且有可能因这些元素比较大或者类型不是 int 型而不能直接开散列表，在这种情况下就可以用 set 来保留元素本身而不考虑它的个数。
	//当然，上面说的情况也可以通过再开一个数组进行下标和元素的对应来解决，但是 set 提供了更为直观的接口，并且加入 set 之后可以实现自动排序。

	set<int> st;
	for (int i = 1; i <= 20; i++)
	{
		//insert(x) 可将 x 插入 set 容器中，并自动递增排序和去重，时间复杂度为 O（logN），其中 N 为 set 内的元素个数。
		st.insert(i);
	}
	for (set<int>::iterator it = st.begin(); it != st.end(); it++)
	{
		//set只能通过迭代器访问
		printf("%d ", *it);
	}

	//find(value) 返回 set 中对应值为 value 的迭代器，时间复杂度为 O（logN），其中 N 为 set 内的元素个数。
	set<int>::iterator it = st.find(2); //在 set 中查找2，返回其迭代器。
	printf("%d ", *it);

	//st.erase(it)  ，即删除迭代器为 it 处的元素，时间复杂度为 O（1）
	st.erase(it);
	for (set<int>::iterator it = st.begin(); it != st.end(); it++)
	{
		//set只能通过迭代器访问
		printf("%d ", *it);
	}

	//value 为所需要删除元素的值。时间复杂度为 O（logN）
	st.erase(3); 

	//erase(first,last) 即删除 [first,last) 内的所有元素。其中 first 为所需要删除区间的起始迭代器，而 last 则为所需要删除区间的末尾迭代器的下一个地址。时间复杂度为 O（last-first）。
	st.erase(st.find(10), st.end());

	//size() 用来获得 set 中元素的个数，时间复杂度为 O（1）
	st.size();

	//clear() 用来清空 set 中的所有元素，时间复杂度为 O（N），其中 N 为 set 中元素的个数。
	st.clear();
	return 0;
}

int MapTest()
{
	//https://blog.csdn.net/sevenjoin/article/details/81943864

	// 定义一个map对象
	map<int, string> mapStudent;


	// 第一种 用insert函數插入pair
	mapStudent.insert(pair<int, string>(000, "student_zero"));
	// 第二种 用insert函数插入value_type数据
	mapStudent.insert(map<int, string>::value_type(001, "student_one"));
	// 第三种 用"array"方式插入
	mapStudent[456] = "student_second";
	mapStudent[123] = "student_first";

	//mapStudent.insert(pair<int, string>(000, "TESTStudent"));
	//mapStudent.insert(map<int, string>::value_type(000, "student_one"));

	////mapStudent[000] = "student_first";

	//mapStudent.insert(map<int, string>::value_type(001, "student_one"));
	//mapStudent.insert(map<int, string>::value_type(001, "student_two"));

	//int* p;

	// 构造定义，返回一个pair对象
	//我们通过pair的第二个变量来知道是否插入成功，它的第一个变量返回的是一个map的迭代器，
	//如果插入成功的话Insert_Pair.second应该是true的，否则为false。
	pair<map<int, string>::iterator, bool> Insert_Pair;
	Insert_Pair = mapStudent.insert(map<int, string>::value_type(001, "student_one"));
	if (!Insert_Pair.second)
		cout << "Error insert new element" << endl;


	//当所查找的关键key出现时，它返回数据所在对象的位置，如果沒有，返回iter与end函数的值相同。
	// find 返回迭代器指向当前查找元素的位置否则返回map::end()位置
	map<int, string>::iterator iter = mapStudent.find(123);
	if (iter != mapStudent.end())
	{
		cout << "Find, the value is" << iter->second << endl;
		cout << "Find, the value is" << (*(iter)).second << endl;
	}
	else
		cout << "Do not Find" << endl;

	bool haveStudent= mapStudent.count(0);
	//刪除与清空元素
	//迭代器刪除
	iter = mapStudent.find(123);
	mapStudent.erase(iter);

	//mapStudent.erase(mapStudent.find(123));


	//用关键字刪除
	int n = mapStudent.erase(123); //如果刪除了會返回1，否則返回0

	//if (mapStudent.erase(123))
	//{

	//}
	//用迭代器范围刪除 : 把整个map清空
	mapStudent.erase(mapStudent.begin(), mapStudent.end());
	mapStudent.erase(mapStudent.find(123), mapStudent.end());

	//等同于mapStudent.clear()

	//map的大小
	int nSize = mapStudent.size();

	map<int, string>::iterator it;
	for (it = mapStudent.begin(); it != mapStudent.end(); it++) 
	{
		cout << (it->first) <<"  " << (it->second);
	}


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