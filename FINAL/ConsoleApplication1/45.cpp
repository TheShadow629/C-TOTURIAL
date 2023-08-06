//Here is an implementation of the merge algorithm in C++ using a template subroutine called "merge":
//word 41
#include <iostream>
#include <vector>

template <typename T>
std::vector<T> merge(const std::vector<T>&arr1, const std::vector<T>&arr2) {
    std::vector<T> mergedArr;
    int i = 0;  // index for arr1
    int j = 0;  // index for arr2

    // Merge the two arrays until one of them is exhausted
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] <= arr2[j]) {
            mergedArr.push_back(arr1[i]);
            i++;
        }
        else {
            mergedArr.push_back(arr2[j]);
            j++;
        }
    }

    // Append remaining elements from arr1 (if any)
    while (i < arr1.size()) {
        mergedArr.push_back(arr1[i]);
        i++;
    }

    // Append remaining elements from arr2 (if any)
    while (j < arr2.size()) {
        mergedArr.push_back(arr2[j]);
        j++;
    }

    return mergedArr;
}

int main() {
    // Test the merge function with different data types
    std::vector<int> arr1 = { 1, 4, 7, 9 };
    std::vector<int> arr2 = { 2, 3, 5, 8 };
    std::vector<int> mergedInt = merge(arr1, arr2);
    for (const auto& num : mergedInt) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<char> arr3 = { 'a', 'c', 'e', 'g' };
    std::vector<char> arr4 = { 'b', 'd', 'f', 'h' };
    std::vector<char> mergedChar = merge(arr3, arr4);
    for (const auto& ch : mergedChar) {
        std::cout << ch << " ";
    }
    std::cout << std::endl;

    return 0;
}
//
//In this implementation, the `merge` template subroutine takes two vectors `arr1` and `arr2` as input,
//which represent the two sorted arrays to be merged.The subroutine merges the arrays and returns a new
//vector `mergedArr` containing all the sorted values.
//
//You can test the `merge` subroutine for different data types by passing vectors of those data types to it
//.In the example code, we test it with `int` and `char` data types.
//
//Note: To use the C++ `vector` and `cout` functionalities, ensure you have included the necessary header
//files `#include <vector>` and `#include <iostream>`.

//�õģ����Ѿ��޸��˴�������Ӧʹ������洢���������ݡ��������޸ĺ��C++ģ���ӳ���"merge"��ʵ�֣�
#include <iostream>

template <typename T, size_t N, size_t M>
void merge(const T(&arr1)[N], const T(&arr2)[M], T(&mergedArr)[N + M]) {
    size_t i = 0;  // ������������arr1
    size_t j = 0;  // ������������arr2
    size_t k = 0;  // ������������mergedArr

    // �ϲ��������飬ֱ������һ�����������
    while (i < N && j < M) {
        if (arr1[i] <= arr2[j]) {
            mergedArr[k] = arr1[i];
            i++;
        }
        else {
            mergedArr[k] = arr2[j];
            j++;
        }
        k++;
    }

    // ��arr1��ʣ���Ԫ��׷�ӵ�mergedArr�У�����еĻ���
    while (i < N) {
        mergedArr[k] = arr1[i];
        i++;
        k++;
    }

    // ��arr2��ʣ���Ԫ��׷�ӵ�mergedArr�У�����еĻ���
    while (j < M) {
        mergedArr[k] = arr2[j];
        j++;
        k++;
    }
}

int main() {
    // �Բ�ͬ���������Ͳ���merge�ӳ���
    int arr1[] = { 1, 4, 7, 9 };
    int arr2[] = { 2, 3, 5, 8 };
    int mergedInt[8];
    merge(arr1, arr2, mergedInt);
    for (const auto& num : mergedInt) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    char arr3[] = { 'a', 'c', 'e', 'g' };
    char arr4[] = { 'b', 'd', 'f', 'h' };
    char mergedChar[8];
    merge(arr3, arr4, mergedChar);
    for (const auto& ch : mergedChar) {
        std::cout << ch << " ";
    }
    std::cout << std::endl;

    return 0;
}
//
//������޸ĺ��ʵ���У�`merge`ģ���ӳ�������������������`arr1`��`arr2`�ֱ��ʾҪ�ϲ�����������������飬`mergedArr`��ʾ�洢�ϲ���������顣�ӳ�����������ϲ�����������洢��`mergedArr`�С�
//
//�����ͨ������ͬ���͵����鴫�ݸ�`merge`�ӳ���������������ʾ�������У�����ʹ��`int`��`char`���ͽ����˲��ԡ�
//
//��ע�⣺Ϊ��ʹ��C++��`cout`���ܣ�ȷ�������������ͷ�ļ�`#include <iostream>`��