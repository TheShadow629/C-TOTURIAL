////The merge sort algorithm uses the divide - and -conquer strategy.It recursively divides
////the input array into smaller subarrays, sorts them individually, and then merges them
////back together to produce a sorted output.
////
////The efficiency of the merge sort algorithm is O(n log n), where n is the number
////of elements in the array.This means that its time complexity grows linearly with
////the number of elements but logarithmically with the size of each element.
////
////Here's the pseudo-code for the merge sort algorithm:
////
///
///
///1 2 3 4 5 6 7 8
////```
////function mergeSort(arr) :
////    if length of arr <= 1 :
////        return arr
////
////        mid = length of arr / 2
////        left = mergeSort(subarray from index 0 to mid - 1 of arr)
////        right = mergeSort(subarray from index mid to end of arr)
////
////        return merge(left, right)
////
////        function merge(left, right) :
////        mergedArr = []
////        i = 0  // index for left subarray
////        j = 0  // index for right subarray
////
////        while i < length of left and j < length of right :
////if left[i] <= right[j] :
////    mergedArr.append(left[i])
////    i++
////else :
////    mergedArr.append(right[j])
////    j++
////
////    append remaining elements from left(if any) to mergedArr
////    append remaining elements from right(if any) to mergedArr
////
////    return mergedArr
////    ```
////
////    In the merge sort algorithm, the `mergeSort` function is the main recursive function that divides
////    the input array into smaller subarrays, sorts them individually using merge sort, and then merges
////    them back together using the `merge` function.The `merge` function takes two sorted subarrays
////    (`left` and `right`) and merges them into a single sorted array.The `mergeSort` function continues
////    dividing the array until the base case is reached(when the array size is 1 or smaller), and then it
////    combines the sorted subarrays to produce the final sorted output.
////
////        The merge sort algorithm's efficiency stems from its ability to divide the array into smaller
////        subarrays and then merge them efficiently. Its time complexity of O(n log n) makes it one of
////        the most efficient sorting algorithms, especially for large arrays.
//
//
//
//
//归并排序算法采用分治策略。它将输入数组递归地分割成较小的子数组，分别对其进行排序，然后再将它们合并以产生一个有序的输出。
//
//归并排序算法的效率为O(n log n)，其中n是数组中的元素数量。这意味着它的时间复杂度随着元素数量的增加而线性增长，
//但随着元素大小的增加呈对数增长。
//
//以下是归并排序算法的伪代码：
//
//```
//function mergeSort(arr):
//    如果 arr 的长度 <= 1：
//        返回 arr
//
//    mid = arr 的长度 / 2
//    left = mergeSort(arr 的索引从 0 到 mid-1 的子数组)
//    right = mergeSort(arr 的索引从 mid 到末尾 的子数组)
//
//    返回 merge(left, right)
//
//function merge(left, right):
//    mergedArr = []
//    i = 0  // 左子数组的索引
//    j = 0  // 右子数组的索引
//
//    当 i < 左子数组的长度 且 j < 右子数组的长度时：
//        如果 left[i] <= right[j]：
//            mergedArr 添加 left[i]
//            i++
//        否则：
//            mergedArr 添加 right[j]
//            j++
//
//    将左子数组中剩余的元素（如果有的话）追加到 mergedArr 中
//    将右子数组中剩余的元素（如果有的话）追加到 mergedArr 中
//
//    返回 mergedArr
//```
//
//在归并排序算法中，`mergeSort` 函数是主要的递归函数，它将输入数组分割成较小的子数组，使用归并排序递归地对它们进行排序，
//然后使用 `merge` 函数将它们合并成一个有序的数组。`merge` 函数接受两个有序的子数组（`left` 和 `right`），
//并将它们合并为一个有序的数组。`mergeSort` 函数在达到基本情况时继续分割数组（当数组大小为1或更小时），
//然后将排序好的子数组组合起来以产生最终的有序输出。
//
//归并排序算法的高效性源于其能够将数组分割为较小的子数组，并且能够有效地进行合并操作。其时间复杂度为 O(n log n)，
//使其成为一种高效的排序算法，特别适用于大型数组。