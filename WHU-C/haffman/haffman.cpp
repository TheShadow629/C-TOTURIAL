//#include "haffman.h"
//#define _CRT_SECURE_NO_WARNINGS
//
////函数的实现过程比较简单，就是从最后一个非叶子节点开始，递减进行筛选操作（sift()函数），直到根节点，就可以保证R数组是一个大根堆。
//void buildHeap(int* R, int n) {
//    int i;
//    for (i = n / 2; i >= 1; i--) { // 从最后一个非叶子节点开始，依次执行筛选操作
//        sift(R, i, n); // 执行一次筛选操作
//    }
//}
//
////函数的实现过程是，首先记录待筛选节点的值，然后不断比较左右孩子节  点的值，找到左右孩子节点中较大的一个，
////然后再将待筛选节点的值与较大孩子节点的值比较，如果待筛选节点的值小于较大孩子的值，需要交换位置，
////直到待筛选节点的值已经比它的两个孩子都大，或者已经超出数组范围。最后，将待筛选节点的值放到最终位置。
//void sift(int* R, int k, int m) {
//    int i = k, j = 2 * k; // i表示待筛选的节点，j表示i的左孩子
//    int temp = R[k]; // 临时保存待筛选节点的值
//    while (j <= m) { // 如果j在数组范围内，继续筛选
//        if (j < m && R[j] < R[j + 1]) { // 找到左右孩子节点中较大的一个
//            j++;
//        }
//        if (temp < R[j]) { // 如果待筛选节点的值小于较大孩子的值，需要交换位置
//            R[i] = R[j];
//            i = j;
//            j = 2 * i;
//        }
//        else break; // 待筛选节点的值已经比它的两个孩子都大，筛选结束
//    }
//    R[i] = temp; // 将待筛选节点的值放到最终位置
//}
//
////函数的实现过程是，首先将新元素放入数组尾部，然后将新元素的值向上调整，使得数组重新恢复成一个最大堆。
////具体来说，每次将新元素的值与它的父节点的值比较，如果父节点的值小于新元素的值，需要交换它们的位置，
////然后新元素的位置变为父节点的位置，继续向上调整，直到新元素的值大于等于它的父节点的值，
////或者已经到达根节点（即i=1）为止。
//void push(int* R, int x, int* n) {
//    (*n)++; // 有效元素个数加1
//    R[*n] = x; // 将新元素放入数组尾部
//    int i = *n, j = i / 2; // i表示新元素的位置，j表示i的父节点
//    while (j >= 1 && R[j] < R[i]) { // 如果i有父节点，并且父节点的值小于i的值
//
//        int temp = R[j]; // 交换i和j的值
//        R[j] = R[i];
//        R[i] = temp;
//
//        i = j; // i变为父节点的位置，继续向上调整
//        j = i / 2; // j变为i的父节点
//    }
//}
//
////maxHeapify()函数用于对以i为根的子树进行堆重构，使其满足大根堆的性质。
////pop()函数则弹出堆顶元素，并将最后一个元素复制到堆顶，然后通过一次maxHeapify()操作使得堆重新满足大根堆的性质。
////注意，n这个参数是引用传递，因为pop()函数会修改堆中元素的个数。
////对于调用者来说，可以通过判断n的值是否变化来确定pop()函数是否执行成功。
//void maxHeapify(int A[], int i, int n) {
//    int l = i * 2;
//    int r = l + 1;
//    int largest = i;
//
//    if (l <= n && A[l] > A[largest]) {
//        largest = l;
//        swap(A[i], A[largest]);
//        maxHeapify(A, largest, n);
//    }
//    if (r <= n && A[r] > A[largest]) {
//        largest = r;
//        swap(A[i], A[largest]);
//        maxHeapify(A, largest, n);
//    }
//
//}
//int pop(int A[], int& n) {
//    int maxVal = A[1];
//    A[1] = A[n];
//    n--;
//    maxHeapify(A, 1, n);
//    return maxVal;
//}
//
////这个函数首先取出堆顶元素，然后将数组最后一个元素拷贝至堆顶。
////接下来，我们需要进行一次筛选操作，来恢复堆的性质。
////在循环中，我们首先找出左右孩子中较大的一个，然后判断父节点和这个孩子节点的大小关系。
////如果父节点比孩子节点小，就交换它们的值，然后继续向下筛选，否则就退出循环。
//void heap_pop(int heap[], int& n) {
//    // 取出堆顶元素
//    int top = heap[0];
//    // 将数组最后一个元素拷贝至堆顶
//    heap[0] = heap[--n];
//    // 进行一次筛选操作
//    int parent = 0, child = 1;
//    while (child < n) {
//        if (child + 1 < n && heap[child + 1] > heap[child]) {
//            child++; // 找出左右孩子中较大的一个
//        }
//        if (heap[parent] < heap[child]) {
//            std::swap(heap[parent], heap[child]); // 交换父节点和孩子节点的值
//            parent = child;
//            child = parent * 2 + 1; // 下一层节点
//        }
//        else {
//            break; // 如果父节点已经比孩子节点大了，就退出循环
//        }
//    }
//}
//
//
////------------------------------------------------------------------------------------------------------------------------------------
//typedef struct HaffmanNode {
//    int weight;
//    struct HaffmanNode* left;
//    struct HaffmanNode* right;
//    struct HaffmanNode* parent; // 新添加的父节点指针
//} HaffmanNode;
//
///**
// * @brief 合并两棵小哈夫曼树
// *
// * @param[in] t1,t2 两棵小哈夫曼树
// */
////在合并两棵树时，我们需要先创建一个新的节点，并将新节点的权值设为两棵树的权值之和。
////然后，我们将新节点作为左右子树的父节点，将左右子树的父节点指针都指向新节点。
////最后，我们将第一个参数指向新节点，将第二个参数设为 NULL，表示该树已经被释放。
//void join(HaffmanNode** t1, HaffmanNode** t2) {
//    HaffmanNode* new_node = (HaffmanNode*)malloc(sizeof(HaffmanNode));
//
//    new_node->weight = (*t1)->weight + (*t2)->weight;
//    new_node->left = *t1;
//    new_node->right = *t2;
//    new_node->parent = NULL;  // 新节点的父节点指针初始化为 NULL
//
//    (*t1)->parent = new_node;  // 修改第一棵树的父节点指针，指向新节点
//    (*t2)->parent = new_node;  // 修改第二棵树的父节点指针，指向新节点
//
//    *t1 = new_node;
//    *t2 = NULL;
//}
//
//#define MAX_TREE_HT 512
///**
// * @brief 根据已经建好的哈夫曼树创建哈夫曼编码
// *
// * @param[in] node 当前节点
// * @param[in] code 当前节点的哈夫曼编码
// */
////这个函数接受两个参数：一个是当前节点，另一个是当前节点的哈夫曼编码。
////当递归到叶子节点时，我们输出该节点的权值以及对应的编码。
////当节点不是叶子节点时，我们向左遍历时，在缓存区中添加字符 '0'，然后将缓存区中的字符追加到编码后面，并递归下去。
////当向右遍历时，类似地，在缓存区中添加字符 '1'，然后将缓存区中的字符追加到编码后面，并递归下去。
////当回溯到父节点时，我们删除最后一个字符。通过使用静态变量 buf，我们可以避免在递归的过程中频繁分配和释放内存。
//void createCode(HaffmanNode* node, char* code) {
//    static char buf[MAX_TREE_HT]; // 用于缓存哈夫曼编码的缓冲区
//
//    if (node == NULL) {
//        return;
//    }
//
//    if (node->left == NULL && node->right == NULL) { // 如果是叶子节点，输出该节点的值以及对应的编码
//        printf("%d: %s\n", node->weight, code);
//    }
//    else {
//        // 向左遍历时，添加字符 '0' 并递归下去
//        buf[strlen(code)] = '0';
//        createCode(node->left, strcat(code, buf)); // 将缓存区中的字符追加到编码后面，然后递归下去
//
//        // 向右遍历时，添加字符 '1' 并递归下去
//        buf[strlen(code)] = '1';
//        createCode(node->right, strcat(code, buf));
//    }
//
//    if (strlen(code) > 0) {
//        code[strlen(code) - 1] = '\0'; // 回溯时，去掉最后一个字符
//    }
//    //在 `createCode()` 函数中，当递归遍历到一个非叶子节点时，此时需要回溯到它的父节点，同时需要将刚才添加到编码中的最后一个字符去掉。
//    //这是因为在生成哈夫曼编码时，每次向左或向右遍历哈夫曼树时，都会在当前编码的末尾添加 '0' 或 '1' 字符，以表示当前走的方向。当遍历到一个非叶子节点时，
//    // 需要回溯到其父节点，同时将刚才添加到编码中的最后一个字符去掉，这是因为在下一次遍历时，需要重新添加新的字符表示新的方向。
//    //如果没有将刚才添加到编码中的最后一个字符去掉，那么在下一次遍历时，生成的编码将会出现错误。因此，需要在回溯时将该字符去掉，以保证下一次遍历不受影响。
//}
//
////根据哈夫曼树求哈夫曼编码的代码在书本P234
//typedef struct
//{
//    char cd[100];
//    int start;
//}HCode;
//
//typedef struct
//{
//    char data;
//    double weight;
//    int parent;
//    int lchild;
//    int rchild;
//}HTNode;
//
////CreateHCode 函数的定义，参数列表包括一个包含节点信息的 HTNode 数组 haffmanNodes，用于存储哈夫曼树的结构；
////一个 HCode 数组 haffmanCode，用于存储编码结果；还有一个整型变量 n0，用于记录节点个数。
//void CreateHCode(HTNode haffmanNodes[], HCode haffmanCode[], int n0)
//{
//    int i, fatherNodeIndex, currentNodeIndex;
//    HCode singleHaffmanCode;
//    for (i = 0; i < n0; i++)
//    {
//        singleHaffmanCode.start = n0;//先将单个节点的编码起始位赋值为节点数
//        currentNodeIndex = i;
//        fatherNodeIndex = haffmanNodes[i].parent;
//        while (fatherNodeIndex != -1)
//        {
//            if (haffmanNodes[fatherNodeIndex].lchild == currentNodeIndex)
//                singleHaffmanCode.cd[singleHaffmanCode.start--] = '0';
//            else
//                singleHaffmanCode.cd[singleHaffmanCode.start--] = '1';
//            currentNodeIndex = fatherNodeIndex;
//            fatherNodeIndex = haffmanNodes[fatherNodeIndex].parent;
//        }
//        singleHaffmanCode.start++;
//        haffmanCode[i] = singleHaffmanCode;
//    }
//}