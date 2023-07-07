//#include "haffman.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//#include <cmath>
//#include <vector>
//#include <algorithm>
//#include "haffman.h"
//#define MAXSIZE 100
//
//int main() {
//    int A[MAXSIZE] = { 0, 49, 38, 65, 97, 76, 13, 27, 49 }; // ��������
//    int n = 8; // ��ЧԪ�ظ���
//    buildHeap(A, n); // ���������
//    for (int i = 1; i <= n; i++) {
//        printf("%d ", A[i]); // ��ӡ�����
//    }
//    printf("\n");
//
//    push(A, 100, &n); // �������в���100
//    for (int i = 1; i <= n; i++) {
//        printf("%d ", A[i]); // ��ӡ�����
//    }
//    printf("\n");
//
//    push(A, 50, &n); // �������в���50
//    for (int i = 1; i <= n; i++) {
//        printf("%d ", A[i]); // ��ӡ�����
//    }
//    printf("\n");
//
//    pop(A,n); //����pop����
//    for (int i = 1; i <= n; i++) {
//        printf("%d ", A[i]); // ��ӡ�����
//    }
//    printf("\n");
//
//
//
//
//
//    return 0;
//}
////
////void plotHeap(const std::vector<int>& A) {
////    int n = A.size() - 1; // ��ЧԪ�ظ���
////    double alpha = 0.2; // �����ڵ�ļ��
////    int depth = std::log2(n) + 1; // ����ѵ����
////    std::vector<double> x_coords, y_coords, sizes;
////    std::vector<std::pair<double, double>> edges;
////
////    for (int i = 1; i <= n; ++i) {
////        double x = i / (std::pow(2, depth) + 1); // ����ڵ��x����
////        double y = depth - std::log2(i); // ����ڵ��y����
////        double r = std::pow(A[i], 0.3); // ����ڵ�İ뾶
////        x_coords.push_back(x);
////        y_coords.push_back(y);
////        sizes.push_back(r * 1000);
////
////        if (i > 1) {
////            int parent = i / 2; // �ҵ����ڵ������
////            double px = parent / (std::pow(2, depth) + 1); // ���㸸�ڵ��x����
////            double py = depth - std::log2(parent); // ���㸸�ڵ��y����
////            edges.push_back({ x, y });
////            edges.push_back({ px, py });
////        }
////    }
////
////    plt::scatter(x_coords, y_coords, sizes, { {"color", "r"} });
////    plt::plot(edges, { {"color", "k"} });
////    plt::xlim(0, 1);
////    plt::ylim(0, depth + 1);
////    plt::axis("off");
////    plt::show();
////}
////
////int main() {
////    std::vector<int> A = { 0, 49, 38, 65, 97, 76, 13, 27, 49 }; // ��������
////    plotHeap(A); // ���Ƴ�ʼ�Ĵ����
////
////    A.push_back(100); // �������в���100
////    std::push_heap(A.begin() + 1, A.end(), std::less<int>());
////    plotHeap(A); // �����µĴ������̬
////
////    A.push_back(50); // �������в���50
////    std::push_heap(A.begin() + 1, A.end(), std::less<int>());
////    plotHeap(A); // �����µĴ������̬
////
////    return 0;
////}
