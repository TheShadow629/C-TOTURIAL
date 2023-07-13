//// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
////
//
//#include <iostream>
//
////#include "BinarySearchTree.h"
//#include "intBST.h"
//
////void bstTEST()
////{
////	BinarySearchTree<int> BST;
////
////	BST.Insert(5);
////	BST.Insert(1);
////	BST.Insert(2);
////	BST.Insert(7);
////	BST.Insert(3);
////	BST.Insert(0);
////	BST.Insert(6);
////	BST.Insert(8);
////	BST.PreOrderTraverse();
////	BST.InOrderTraverse();
////	BST.LastOrderTraverse();
////
////	std::cout << std::endl;
////
////	for (int i = 0; i < 10; i++)
////	{
////		if (BST.Search(i))
////		{
////			std::cout << i << " 找到 : " << BST.RecursionSearch(i, BST.GetRoot()) << std::endl;
////			continue;
////		}
////		std::cout << i << " 未找到~ " << BST.RecursionSearch(i, BST.GetRoot()) << std::endl;
////	}
////}
//
//
//int main()
//{
//    intBST tmp;
//    tmp.Insert(tmp.GetTree(), 1);
//    tmp.Insert(tmp.GetTree(), 5);
//    tmp.Insert(tmp.GetTree(), 2);
//    tmp.Insert(tmp.GetTree(), 8);
//    tmp.Insert(tmp.GetTree(), 7);
//    tmp.Insert(tmp.GetTree(), 4);
//    tmp.Insert(tmp.GetTree(), 6);
//
//    std::cout << (tmp.FindMax(tmp.GetTree()))->GetData();
//}
