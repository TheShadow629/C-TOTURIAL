//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//#include <cmath>
//#include <vector>
//#include <algorithm>
//#include <stdio.h>
//#include <malloc.h>
//
//typedef struct Node {
//    int value;              // 链表节点存储的数据
//    struct Node* next;      // 链表节点的下一个节点指针
//} Node;
//
//Node* buildList(int* array, int length) {
//    Node* head = NULL;      // 头节点指针初始化为 NULL 
//    Node* tail = NULL;      // 尾节点指针初始化为 NULL 
//
//    // 通过循环遍历数组中的元素，将它们存储到链表节点中
//    for (int i = 0; i < length; i++) {
//        Node* node = (Node*)malloc(sizeof(Node));    // 创建一个新的节点
//        node->value = array[i];                     // 将数组元素存储到节点中
//        node->next = NULL;                          // 新节点的下一个节点指针初始化为 NULL 
//
//        // 如果链表为空，将头节点和尾节点都指向新节点
//        if (head == NULL) {
//            head = node;
//            tail = node;
//        }
//        // 如果链表不为空，将新节点添加到链表
//        else {
//            tail->next = node;  // 当前尾节点的下一个节点指针指向新节点
//            tail = node;        // 更新尾节点指针为新节点
//        }
//    }
//    return head;    // 返回链表头指针
//}
//
////----------------------------------------------------------------------------------------------
//typedef struct SequenceListNode {
//    Node* singleSinquence;                         // 子序列头节点指针
//    struct SequenceListNode* next;      // 当前节点的下一个节点指针
//} SequenceListNode;
//
//SequenceListNode* initSequenceList(Node* n)
//{
//    SequenceListNode* sl = NULL;      // 头节点指针初始化为 NULL 
//    SequenceListNode* tail = NULL;      // 尾节点指针初始化为 NULL 
//
//    // 通过循环遍历Node* n链表中的元素，将它们存储到 SequenceListNode链表节点中
//    while (n!=NULL)
//    {
//        SequenceListNode* sequenceLists = (SequenceListNode*)malloc(sizeof(SequenceListNode));    // 创建一个新的节点
//        sequenceLists->singleSinquence = n;                     // 将元素存储到节点中
//        sequenceLists->next = NULL;                          // 新节点的下一个节点指针初始化为 NULL 
//
//        // 如果链表为空，将头节点和尾节点都指向新节点
//        if (sl == NULL) {
//            sl = sequenceLists;
//            tail = sequenceLists;
//        }
//        // 如果链表不为空，将新节点添加到链表尾部
//        else {
//            tail->next = sequenceLists;  // 当前尾节点的下一个节点指针指向新节点
//            tail = sequenceLists;        // 更新尾节点指针为新节点
//        }
//        n = n->next;
//    }
//    return sl;    // 返回链表头指针
//}
//
//void merge(SequenceListNode* sl) {
//    SequenceListNode* first = sl;
//    SequenceListNode* second = sl->next;
//    while (second != nullptr) {        
//        //first->singleSinquence = hebing(first->singleSinquence, second->singleSinquence);  // 调用合并函数
//        //---------------------------------------------------------------------------------------
//        Node* A = first->singleSinquence, *B = second->singleSinquence;
//        Node* dummy = new Node;  // 创建一个头结点作为合并后链表的起始位置
//        Node* cur = dummy;
//        while (A != nullptr && B != nullptr) {
//            if (A->value <= B->value) {
//                /*cur = */
//                insertNode(A, cur);
//                A = A->next;
//            }
//            else {
//                /*cur = */
//                insertNode(B, cur);
//                B = B->next;
//            }
//        }
//        // 将剩余的节点接到链表末尾
//        while (A != NULL) {
//            cur->next = A;
//            A = A->next;
//            cur = cur->next;
//        }
//        while (B != NULL) {
//            cur->next = B;
//            B = B->next;
//            cur = cur->next;
//        }
//        // 返回合并后的链表头节点(存储到)first->singleSinquence内
//        first->singleSinquence = dummy->next;
//        delete dummy;
//        //----------------------------------------------------------------------------------------------
//
//        first->next = second->next;
//        //delete next;
//        first = first->next;
//        if (first != nullptr) {
//            second = first->next;  // 跳到下一组需要合并的元素
//        }
//        else {
//            break;
//        }
//    }
//}
//
////Node* hebing(Node* A, Node* B) {
////    Node* dummy = new Node;  // 创建一个头结点作为合并后链表的起始位置
////    Node* cur = dummy;
////    while (A != nullptr && B != nullptr) {
////        if (A->value <= B->value) {
////            cur = insertNode(A, cur);
////            A = A->next;
////        }
////        else {
////            cur = insertNode(B, cur);
////            B = B->next;
////        }
////    }
////    // 将剩余的节点接到链表末尾
////    while (A != NULL) {
////        cur->next = A;
////        A = A->next;
////        cur = cur->next;
////    }
////    while(B!=NULL){
////        cur->next = B;
////        B = B->next;
////        cur = cur->next;
////    }
////    // 返回合并后的链表头节点
////    Node* result = dummy->next;
////    delete dummy;
////    return result;
////}
//
//void insertNode(Node* dataNode, Node*& orderedList) {
//    Node* prev = nullptr;
//    Node* cur = orderedList;
//    while (cur != nullptr && cur->value < dataNode->value) {
//        prev = cur;
//        cur = cur->next;
//    }
//    if (prev == nullptr) {
//        dataNode->next = orderedList;
//        //return dataNode;
//        orderedList = dataNode;
//    }
//    else {
//        prev->next = dataNode;
//        dataNode->next = cur;
//        //return prev;
//        orderedList = prev;
//    }
//}
//
//
//Node* mergeSort(int* array, int length)
//{
//    Node* newNode;
//    newNode=buildList( array, length);
//    SequenceListNode* sl;
//    sl = initSequenceList(newNode);
//    while (sl->next != NULL)
//    {
//        merge(sl);
//    }
//    return sl->singleSinquence;
//}