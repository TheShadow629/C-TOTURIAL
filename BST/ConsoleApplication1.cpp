// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include "intBST.h"
#include "Bst.h"

void intBstTest()
{
	intBST myIntBst(0);
	myIntBst.Insert(myIntBst.GetTree(), 3);
	myIntBst.Insert(myIntBst.GetTree(), 2);
	myIntBst.Insert(myIntBst.GetTree(), 4);
	myIntBst.Insert(myIntBst.GetTree(), 1);
	myIntBst.Insert(myIntBst.GetTree(), 6);
	myIntBst.Insert(myIntBst.GetTree(), 10);
	myIntBst.Insert(myIntBst.GetTree(), 10);
	myIntBst.Insert(myIntBst.GetTree(), 7);
	myIntBst.Insert(myIntBst.GetTree(), 11);

	myIntBst.InOrderTraversal(myIntBst.GetTree());
	std::cout << std::endl;

	myIntBst.PreOrderTraversal(myIntBst.GetTree());
	std::cout << std::endl;

	myIntBst.PostOrderTraversal(myIntBst.GetTree());
	std::cout << std::endl;

	if (myIntBst.Find(4, myIntBst.GetTree()))
		std::cout << myIntBst.Find(4, myIntBst.GetTree())->GetData()
		<< "   " << myIntBst.Find(4, myIntBst.GetTree()) << std::endl;
	else
		std::cout << "NOTFOUND" << std::endl;

	if (myIntBst.Find(44, myIntBst.GetTree()))
		std::cout << myIntBst.Find(44, myIntBst.GetTree())->GetData()
		<< "   " << myIntBst.Find(44, myIntBst.GetTree()) << std::endl;
	else
		std::cout << "NOTFOUND" << std::endl;

	myIntBst.DeleteTree(myIntBst.GetTree());
	//intBST();
	//TNode* Insert(TNode * BST, int X);
	//TNode* DeleteTree(TNode * BST);
	//TNode* Find(int X, TNode * BST);

	//void InOrderTraversal(TNode * BST);
	//void PreOrderTraversal(TNode * BST);
	//void PostOrderTraversal(TNode * BST);
}

void templetBstTest()
{
	Bst<int> myIntBst(0);
	myIntBst.Insert(myIntBst.GetTree(), 3);
	myIntBst.Insert(myIntBst.GetTree(), 2);
	myIntBst.Insert(myIntBst.GetTree(), 4);
	myIntBst.Insert(myIntBst.GetTree(), 1);
	myIntBst.Insert(myIntBst.GetTree(), 6);
	myIntBst.Insert(myIntBst.GetTree(), 10);
	myIntBst.Insert(myIntBst.GetTree(), 7);
	myIntBst.Insert(myIntBst.GetTree(), 11);

	myIntBst.InOrderTraversal(myIntBst.GetTree());
	std::cout << std::endl;

	myIntBst.PreOrderTraversal(myIntBst.GetTree());
	std::cout << std::endl;

	myIntBst.PostOrderTraversal(myIntBst.GetTree());
	std::cout << std::endl;

	if (myIntBst.Find(4, myIntBst.GetTree()))
		std::cout << myIntBst.Find(4, myIntBst.GetTree())->GetData()
		<< "   " << myIntBst.Find(4, myIntBst.GetTree()) << std::endl;
	else
		std::cout << "NOTFOUND" << std::endl;

	if (myIntBst.Find(44, myIntBst.GetTree()))
		std::cout << myIntBst.Find(44, myIntBst.GetTree())->GetData()
		<< "   " << myIntBst.Find(44, myIntBst.GetTree()) << std::endl;
	else
		std::cout << "NOTFOUND" << std::endl;

	myIntBst.DeleteTree(myIntBst.GetTree());
}

int main()
{
	intBstTest();
	//templetBstTest();
	return 0;
}

