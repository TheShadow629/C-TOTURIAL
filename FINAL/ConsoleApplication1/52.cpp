//The binary search algorithm is used to efficiently search for a specific element in
//a sorted array or container.It follows a divide - and -conquer approach by repeatedly
//dividing the search space in half, discarding the half of the search space that cannot
//contain the target element.
//
//Preconditions for the binary search algorithm :
//1. Sorted Collection : The binary search algorithm requires the collection to be sorted
//in ascending or descending order.If the collection is unsorted, the algorithm will not work correctly.
//
//2. Random Access : The binary search algorithm assumes random access to elements in the
//collection.This means that the elements can be accessed directly by their index or have constant
//time complexity for accessing any element.
//
//The preconditions affect the runtime performance(Big - O) of the binary search algorithm as follows :
//
//1. Sorted Collection : The binary search algorithm takes advantage of the sorted nature of the collection.
//It divides the search space in half at each step, resulting in a logarithmic time complexity of O(log n),
//where n is the size of the collection.This is significantly more efficient than a linear search, which
//would have a time complexity of O(n) for an unsorted collection.
//
//2. Random Access : The binary search algorithm requires random access to elements to access the middle
//element for comparison.Random access allows accessing any element in the collection in constant time.If
//random access is not available or slow, it will impact the performance of the algorithm.For example, if
//the collection is implemented as a linked list, the time complexity for accessing the middle element would
//be O(n), resulting in a degraded performance compared to random access.
//
//Here's an implementation of the binary search algorithm in C++:

#include <iostream>
#include <vector>

template<typename T>
int binarySearch(const std::vector<T>&collection, const T & target) {
    int left = 0;
    int right = collection.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (collection[mid] == target) {
            return mid;
        }
        else if (collection[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1; // Element not found
}

int main() {
    std::vector<int> collection = { 1, 3, 5, 7, 9, 11, 13 };

    int target = 9;
    int index = binarySearch(collection, target);

    if (index != -1) {
        std::cout << "Element " << target << " found at index " << index << std::endl;
    }
    else {
        std::cout << "Element " << target << " not found in the collection" << std::endl;
    }

    return 0;
}

//In this example, the `binarySearch` function performs a binary search on a sorted vector `collection` for
//a target element `target`. It returns the index of the target element if found, or -1 if the element is
//not present in the collection.The algorithm repeatedly divides the search space by comparing the target
//element with the middle element of the current range and adjusts the left and right bounds accordingly.