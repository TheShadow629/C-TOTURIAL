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
//    int value;              // ����ڵ�洢������
//    struct Node* next;      // ����ڵ����һ���ڵ�ָ��
//} Node;
//
//Node* buildList(int* array, int length) {
//    Node* head = NULL;      // ͷ�ڵ�ָ���ʼ��Ϊ NULL 
//    Node* tail = NULL;      // β�ڵ�ָ���ʼ��Ϊ NULL 
//
//    // ͨ��ѭ�����������е�Ԫ�أ������Ǵ洢������ڵ���
//    for (int i = 0; i < length; i++) {
//        Node* node = (Node*)malloc(sizeof(Node));    // ����һ���µĽڵ�
//        node->value = array[i];                     // ������Ԫ�ش洢���ڵ���
//        node->next = NULL;                          // �½ڵ����һ���ڵ�ָ���ʼ��Ϊ NULL 
//
//        // �������Ϊ�գ���ͷ�ڵ��β�ڵ㶼ָ���½ڵ�
//        if (head == NULL) {
//            head = node;
//            tail = node;
//        }
//        // �������Ϊ�գ����½ڵ���ӵ�����
//        else {
//            tail->next = node;  // ��ǰβ�ڵ����һ���ڵ�ָ��ָ���½ڵ�
//            tail = node;        // ����β�ڵ�ָ��Ϊ�½ڵ�
//        }
//    }
//    return head;    // ��������ͷָ��
//}
//
////----------------------------------------------------------------------------------------------
//typedef struct SequenceListNode {
//    Node* singleSinquence;                         // ������ͷ�ڵ�ָ��
//    struct SequenceListNode* next;      // ��ǰ�ڵ����һ���ڵ�ָ��
//} SequenceListNode;
//
//SequenceListNode* initSequenceList(Node* n)
//{
//    SequenceListNode* sl = NULL;      // ͷ�ڵ�ָ���ʼ��Ϊ NULL 
//    SequenceListNode* tail = NULL;      // β�ڵ�ָ���ʼ��Ϊ NULL 
//
//    // ͨ��ѭ������Node* n�����е�Ԫ�أ������Ǵ洢�� SequenceListNode����ڵ���
//    while (n!=NULL)
//    {
//        SequenceListNode* sequenceLists = (SequenceListNode*)malloc(sizeof(SequenceListNode));    // ����һ���µĽڵ�
//        sequenceLists->singleSinquence = n;                     // ��Ԫ�ش洢���ڵ���
//        sequenceLists->next = NULL;                          // �½ڵ����һ���ڵ�ָ���ʼ��Ϊ NULL 
//
//        // �������Ϊ�գ���ͷ�ڵ��β�ڵ㶼ָ���½ڵ�
//        if (sl == NULL) {
//            sl = sequenceLists;
//            tail = sequenceLists;
//        }
//        // �������Ϊ�գ����½ڵ���ӵ�����β��
//        else {
//            tail->next = sequenceLists;  // ��ǰβ�ڵ����һ���ڵ�ָ��ָ���½ڵ�
//            tail = sequenceLists;        // ����β�ڵ�ָ��Ϊ�½ڵ�
//        }
//        n = n->next;
//    }
//    return sl;    // ��������ͷָ��
//}
//
//void merge(SequenceListNode* sl) {
//    SequenceListNode* first = sl;
//    SequenceListNode* second = sl->next;
//    while (second != nullptr) {        
//        //first->singleSinquence = hebing(first->singleSinquence, second->singleSinquence);  // ���úϲ�����
//        //---------------------------------------------------------------------------------------
//        Node* A = first->singleSinquence, *B = second->singleSinquence;
//        Node* dummy = new Node;  // ����һ��ͷ�����Ϊ�ϲ����������ʼλ��
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
//        // ��ʣ��Ľڵ�ӵ�����ĩβ
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
//        // ���غϲ��������ͷ�ڵ�(�洢��)first->singleSinquence��
//        first->singleSinquence = dummy->next;
//        delete dummy;
//        //----------------------------------------------------------------------------------------------
//
//        first->next = second->next;
//        //delete next;
//        first = first->next;
//        if (first != nullptr) {
//            second = first->next;  // ������һ����Ҫ�ϲ���Ԫ��
//        }
//        else {
//            break;
//        }
//    }
//}
//
////Node* hebing(Node* A, Node* B) {
////    Node* dummy = new Node;  // ����һ��ͷ�����Ϊ�ϲ����������ʼλ��
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
////    // ��ʣ��Ľڵ�ӵ�����ĩβ
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
////    // ���غϲ��������ͷ�ڵ�
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