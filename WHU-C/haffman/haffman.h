#pragma once

#include "haffman.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "haffman.h"
//#include "matplotlibcpp.h"
//namespace plt = matplotlibcpp;

void buildHeap(int* R, int n);
void sift(int* R, int k, int m);
void push(int* R, int x, int* n);
void maxHeapify(int A[], int i, int n);
int pop(int A[], int& n);
void heap_pop(int heap[], int& n);

template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}