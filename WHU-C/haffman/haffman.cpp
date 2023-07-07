//#include "haffman.h"
//#define _CRT_SECURE_NO_WARNINGS
//
////������ʵ�ֹ��̱Ƚϼ򵥣����Ǵ����һ����Ҷ�ӽڵ㿪ʼ���ݼ�����ɸѡ������sift()��������ֱ�����ڵ㣬�Ϳ��Ա�֤R������һ������ѡ�
//void buildHeap(int* R, int n) {
//    int i;
//    for (i = n / 2; i >= 1; i--) { // �����һ����Ҷ�ӽڵ㿪ʼ������ִ��ɸѡ����
//        sift(R, i, n); // ִ��һ��ɸѡ����
//    }
//}
//
////������ʵ�ֹ����ǣ����ȼ�¼��ɸѡ�ڵ��ֵ��Ȼ�󲻶ϱȽ����Һ��ӽ�  ���ֵ���ҵ����Һ��ӽڵ��нϴ��һ����
////Ȼ���ٽ���ɸѡ�ڵ��ֵ��ϴ��ӽڵ��ֵ�Ƚϣ������ɸѡ�ڵ��ֵС�ڽϴ��ӵ�ֵ����Ҫ����λ�ã�
////ֱ����ɸѡ�ڵ��ֵ�Ѿ��������������Ӷ��󣬻����Ѿ��������鷶Χ����󣬽���ɸѡ�ڵ��ֵ�ŵ�����λ�á�
//void sift(int* R, int k, int m) {
//    int i = k, j = 2 * k; // i��ʾ��ɸѡ�Ľڵ㣬j��ʾi������
//    int temp = R[k]; // ��ʱ�����ɸѡ�ڵ��ֵ
//    while (j <= m) { // ���j�����鷶Χ�ڣ�����ɸѡ
//        if (j < m && R[j] < R[j + 1]) { // �ҵ����Һ��ӽڵ��нϴ��һ��
//            j++;
//        }
//        if (temp < R[j]) { // �����ɸѡ�ڵ��ֵС�ڽϴ��ӵ�ֵ����Ҫ����λ��
//            R[i] = R[j];
//            i = j;
//            j = 2 * i;
//        }
//        else break; // ��ɸѡ�ڵ��ֵ�Ѿ��������������Ӷ���ɸѡ����
//    }
//    R[i] = temp; // ����ɸѡ�ڵ��ֵ�ŵ�����λ��
//}
//
////������ʵ�ֹ����ǣ����Ƚ���Ԫ�ط�������β����Ȼ����Ԫ�ص�ֵ���ϵ�����ʹ���������»ָ���һ�����ѡ�
////������˵��ÿ�ν���Ԫ�ص�ֵ�����ĸ��ڵ��ֵ�Ƚϣ�������ڵ��ֵС����Ԫ�ص�ֵ����Ҫ�������ǵ�λ�ã�
////Ȼ����Ԫ�ص�λ�ñ�Ϊ���ڵ��λ�ã��������ϵ�����ֱ����Ԫ�ص�ֵ���ڵ������ĸ��ڵ��ֵ��
////�����Ѿ�������ڵ㣨��i=1��Ϊֹ��
//void push(int* R, int x, int* n) {
//    (*n)++; // ��ЧԪ�ظ�����1
//    R[*n] = x; // ����Ԫ�ط�������β��
//    int i = *n, j = i / 2; // i��ʾ��Ԫ�ص�λ�ã�j��ʾi�ĸ��ڵ�
//    while (j >= 1 && R[j] < R[i]) { // ���i�и��ڵ㣬���Ҹ��ڵ��ֵС��i��ֵ
//
//        int temp = R[j]; // ����i��j��ֵ
//        R[j] = R[i];
//        R[i] = temp;
//
//        i = j; // i��Ϊ���ڵ��λ�ã��������ϵ���
//        j = i / 2; // j��Ϊi�ĸ��ڵ�
//    }
//}
//
////maxHeapify()�������ڶ���iΪ�����������ж��ع���ʹ���������ѵ����ʡ�
////pop()�����򵯳��Ѷ�Ԫ�أ��������һ��Ԫ�ظ��Ƶ��Ѷ���Ȼ��ͨ��һ��maxHeapify()����ʹ�ö������������ѵ����ʡ�
////ע�⣬n������������ô��ݣ���Ϊpop()�������޸Ķ���Ԫ�صĸ�����
////���ڵ�������˵������ͨ���ж�n��ֵ�Ƿ�仯��ȷ��pop()�����Ƿ�ִ�гɹ���
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
////�����������ȡ���Ѷ�Ԫ�أ�Ȼ���������һ��Ԫ�ؿ������Ѷ���
////��������������Ҫ����һ��ɸѡ���������ָ��ѵ����ʡ�
////��ѭ���У����������ҳ����Һ����нϴ��һ����Ȼ���жϸ��ڵ��������ӽڵ�Ĵ�С��ϵ��
////������ڵ�Ⱥ��ӽڵ�С���ͽ������ǵ�ֵ��Ȼ���������ɸѡ��������˳�ѭ����
//void heap_pop(int heap[], int& n) {
//    // ȡ���Ѷ�Ԫ��
//    int top = heap[0];
//    // ���������һ��Ԫ�ؿ������Ѷ�
//    heap[0] = heap[--n];
//    // ����һ��ɸѡ����
//    int parent = 0, child = 1;
//    while (child < n) {
//        if (child + 1 < n && heap[child + 1] > heap[child]) {
//            child++; // �ҳ����Һ����нϴ��һ��
//        }
//        if (heap[parent] < heap[child]) {
//            std::swap(heap[parent], heap[child]); // �������ڵ�ͺ��ӽڵ��ֵ
//            parent = child;
//            child = parent * 2 + 1; // ��һ��ڵ�
//        }
//        else {
//            break; // ������ڵ��Ѿ��Ⱥ��ӽڵ���ˣ����˳�ѭ��
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
//    struct HaffmanNode* parent; // ����ӵĸ��ڵ�ָ��
//} HaffmanNode;
//
///**
// * @brief �ϲ�����С��������
// *
// * @param[in] t1,t2 ����С��������
// */
////�ںϲ�������ʱ��������Ҫ�ȴ���һ���µĽڵ㣬�����½ڵ��Ȩֵ��Ϊ��������Ȩֵ֮�͡�
////Ȼ�����ǽ��½ڵ���Ϊ���������ĸ��ڵ㣬�����������ĸ��ڵ�ָ�붼ָ���½ڵ㡣
////������ǽ���һ������ָ���½ڵ㣬���ڶ���������Ϊ NULL����ʾ�����Ѿ����ͷš�
//void join(HaffmanNode** t1, HaffmanNode** t2) {
//    HaffmanNode* new_node = (HaffmanNode*)malloc(sizeof(HaffmanNode));
//
//    new_node->weight = (*t1)->weight + (*t2)->weight;
//    new_node->left = *t1;
//    new_node->right = *t2;
//    new_node->parent = NULL;  // �½ڵ�ĸ��ڵ�ָ���ʼ��Ϊ NULL
//
//    (*t1)->parent = new_node;  // �޸ĵ�һ�����ĸ��ڵ�ָ�룬ָ���½ڵ�
//    (*t2)->parent = new_node;  // �޸ĵڶ������ĸ��ڵ�ָ�룬ָ���½ڵ�
//
//    *t1 = new_node;
//    *t2 = NULL;
//}
//
//#define MAX_TREE_HT 512
///**
// * @brief �����Ѿ����õĹ���������������������
// *
// * @param[in] node ��ǰ�ڵ�
// * @param[in] code ��ǰ�ڵ�Ĺ���������
// */
////���������������������һ���ǵ�ǰ�ڵ㣬��һ���ǵ�ǰ�ڵ�Ĺ��������롣
////���ݹ鵽Ҷ�ӽڵ�ʱ����������ýڵ��Ȩֵ�Լ���Ӧ�ı��롣
////���ڵ㲻��Ҷ�ӽڵ�ʱ�������������ʱ���ڻ�����������ַ� '0'��Ȼ�󽫻������е��ַ�׷�ӵ�������棬���ݹ���ȥ��
////�����ұ���ʱ�����Ƶأ��ڻ�����������ַ� '1'��Ȼ�󽫻������е��ַ�׷�ӵ�������棬���ݹ���ȥ��
////�����ݵ����ڵ�ʱ������ɾ�����һ���ַ���ͨ��ʹ�þ�̬���� buf�����ǿ��Ա����ڵݹ�Ĺ�����Ƶ��������ͷ��ڴ档
//void createCode(HaffmanNode* node, char* code) {
//    static char buf[MAX_TREE_HT]; // ���ڻ������������Ļ�����
//
//    if (node == NULL) {
//        return;
//    }
//
//    if (node->left == NULL && node->right == NULL) { // �����Ҷ�ӽڵ㣬����ýڵ��ֵ�Լ���Ӧ�ı���
//        printf("%d: %s\n", node->weight, code);
//    }
//    else {
//        // �������ʱ������ַ� '0' ���ݹ���ȥ
//        buf[strlen(code)] = '0';
//        createCode(node->left, strcat(code, buf)); // ���������е��ַ�׷�ӵ�������棬Ȼ��ݹ���ȥ
//
//        // ���ұ���ʱ������ַ� '1' ���ݹ���ȥ
//        buf[strlen(code)] = '1';
//        createCode(node->right, strcat(code, buf));
//    }
//
//    if (strlen(code) > 0) {
//        code[strlen(code) - 1] = '\0'; // ����ʱ��ȥ�����һ���ַ�
//    }
//    //�� `createCode()` �����У����ݹ������һ����Ҷ�ӽڵ�ʱ����ʱ��Ҫ���ݵ����ĸ��ڵ㣬ͬʱ��Ҫ���ղ���ӵ������е����һ���ַ�ȥ����
//    //������Ϊ�����ɹ���������ʱ��ÿ����������ұ�����������ʱ�������ڵ�ǰ�����ĩβ��� '0' �� '1' �ַ����Ա�ʾ��ǰ�ߵķ��򡣵�������һ����Ҷ�ӽڵ�ʱ��
//    // ��Ҫ���ݵ��丸�ڵ㣬ͬʱ���ղ���ӵ������е����һ���ַ�ȥ����������Ϊ����һ�α���ʱ����Ҫ��������µ��ַ���ʾ�µķ���
//    //���û�н��ղ���ӵ������е����һ���ַ�ȥ������ô����һ�α���ʱ�����ɵı��뽫����ִ�����ˣ���Ҫ�ڻ���ʱ�����ַ�ȥ�����Ա�֤��һ�α�������Ӱ�졣
//}
//
////���ݹ������������������Ĵ������鱾P234
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
////CreateHCode �����Ķ��壬�����б����һ�������ڵ���Ϣ�� HTNode ���� haffmanNodes�����ڴ洢���������Ľṹ��
////һ�� HCode ���� haffmanCode�����ڴ洢������������һ�����ͱ��� n0�����ڼ�¼�ڵ������
//void CreateHCode(HTNode haffmanNodes[], HCode haffmanCode[], int n0)
//{
//    int i, fatherNodeIndex, currentNodeIndex;
//    HCode singleHaffmanCode;
//    for (i = 0; i < n0; i++)
//    {
//        singleHaffmanCode.start = n0;//�Ƚ������ڵ�ı�����ʼλ��ֵΪ�ڵ���
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