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

//好的，我已经修改了代码以适应使用数组存储的输入数据。以下是修改后的C++模板子程序"merge"的实现：
#include <iostream>

template <typename T, size_t N, size_t M>
void merge(const T(&arr1)[N], const T(&arr2)[M], T(&mergedArr)[N + M]) {
    size_t i = 0;  // 索引变量用于arr1
    size_t j = 0;  // 索引变量用于arr2
    size_t k = 0;  // 索引变量用于mergedArr

    // 合并两个数组，直到其中一个数组遍历完
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

    // 将arr1中剩余的元素追加到mergedArr中（如果有的话）
    while (i < N) {
        mergedArr[k] = arr1[i];
        i++;
        k++;
    }

    // 将arr2中剩余的元素追加到mergedArr中（如果有的话）
    while (j < M) {
        mergedArr[k] = arr2[j];
        j++;
        k++;
    }
}

int main() {
    // 以不同的数据类型测试merge子程序
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
//在这个修改后的实现中，`merge`模板子程序接受两个输入参数，`arr1`和`arr2`分别表示要合并的两个已排序的数组，`mergedArr`表示存储合并结果的数组。子程序将两个数组合并，并将结果存储在`mergedArr`中。
//
//你可以通过将不同类型的数组传递给`merge`子程序来测试它。在示例代码中，我们使用`int`和`char`类型进行了测试。
//
//请注意：为了使用C++的`cout`功能，确保包含了所需的头文件`#include <iostream>`。