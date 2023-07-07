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
//    int A[MAXSIZE] = { 0, 49, 38, 65, 97, 76, 13, 27, 49 }; // 输入数组
//    int n = 8; // 有效元素个数
//    buildHeap(A, n); // 建立大根堆
//    for (int i = 1; i <= n; i++) {
//        printf("%d ", A[i]); // 打印大根堆
//    }
//    printf("\n");
//
//    push(A, 100, &n); // 向大根堆中插入100
//    for (int i = 1; i <= n; i++) {
//        printf("%d ", A[i]); // 打印大根堆
//    }
//    printf("\n");
//
//    push(A, 50, &n); // 向大根堆中插入50
//    for (int i = 1; i <= n; i++) {
//        printf("%d ", A[i]); // 打印大根堆
//    }
//    printf("\n");
//
//    pop(A,n); //测试pop函数
//    for (int i = 1; i <= n; i++) {
//        printf("%d ", A[i]); // 打印大根堆
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
////    int n = A.size() - 1; // 有效元素个数
////    double alpha = 0.2; // 调整节点的间距
////    int depth = std::log2(n) + 1; // 大根堆的深度
////    std::vector<double> x_coords, y_coords, sizes;
////    std::vector<std::pair<double, double>> edges;
////
////    for (int i = 1; i <= n; ++i) {
////        double x = i / (std::pow(2, depth) + 1); // 计算节点的x坐标
////        double y = depth - std::log2(i); // 计算节点的y坐标
////        double r = std::pow(A[i], 0.3); // 计算节点的半径
////        x_coords.push_back(x);
////        y_coords.push_back(y);
////        sizes.push_back(r * 1000);
////
////        if (i > 1) {
////            int parent = i / 2; // 找到父节点的索引
////            double px = parent / (std::pow(2, depth) + 1); // 计算父节点的x坐标
////            double py = depth - std::log2(parent); // 计算父节点的y坐标
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
////    std::vector<int> A = { 0, 49, 38, 65, 97, 76, 13, 27, 49 }; // 输入数组
////    plotHeap(A); // 绘制初始的大根堆
////
////    A.push_back(100); // 向大根堆中插入100
////    std::push_heap(A.begin() + 1, A.end(), std::less<int>());
////    plotHeap(A); // 绘制新的大根堆形态
////
////    A.push_back(50); // 向大根堆中插入50
////    std::push_heap(A.begin() + 1, A.end(), std::less<int>());
////    plotHeap(A); // 绘制新的大根堆形态
////
////    return 0;
////}
