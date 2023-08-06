//word 45
//Here's the efficient C++ subroutine called "merge" that merges two pre-sorted vectors:

#include <iostream>
#include <vector>

template <typename T>
std::vector<T> merge(const std::vector<T>&arr1, const std::vector<T>&arr2) {
    std::vector<T> mergedArr;
    size_t i = 0;  // index for arr1
    size_t j = 0;  // index for arr2

    // Merge the two vectors until one of them is exhausted
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
    // Test the merge subroutine with integers
    std::vector<int> arr1 = { 1, 2, 3, 4 };
    std::vector<int> arr2 = { 2, 4, 6, 8 };
    std::vector<int> mergedInt = merge(arr1, arr2);
    for (const auto& num : mergedInt) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

//In this code, the `merge` subroutine takes two pre - sorted vectors `arr1` and `arr2` and merges them
//into a new vector `mergedArr`. The resulting vector contains all the values from the original vectors
//while being sorted in ascending order.
//
//To test the `merge` subroutine, I provided two test vectors `arr1` and `arr2` with pre - sorted integer
//values.I chose test data with some overlapping entries to ensure that the subroutine handles duplicates
//correctly.In this example, the test data includes integers sorted in ascending order.
//
//The algorithm is efficient because it only requires a single pass over the input vectors.It compares the
//elements at corresponding indices in `arr1` and `arr2`, selects the smaller one, and appends it to the
//`mergedArr`. This process continues until one of the input vectors is exhausted.The remaining elements
//from the non - exhausted vector are then appended to the `mergedArr`. Since the input vectors are already
//sorted, the algorithm can efficiently merge them without needing to perform additional sorting operations.