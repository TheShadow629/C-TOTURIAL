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
//�鲢�����㷨���÷��β��ԡ�������������ݹ�طָ�ɽ�С�������飬�ֱ�����������Ȼ���ٽ����Ǻϲ��Բ���һ������������
//
//�鲢�����㷨��Ч��ΪO(n log n)������n�������е�Ԫ������������ζ������ʱ�临�Ӷ�����Ԫ�����������Ӷ�����������
//������Ԫ�ش�С�����ӳʶ���������
//
//�����ǹ鲢�����㷨��α���룺
//
//```
//function mergeSort(arr):
//    ��� arr �ĳ��� <= 1��
//        ���� arr
//
//    mid = arr �ĳ��� / 2
//    left = mergeSort(arr �������� 0 �� mid-1 ��������)
//    right = mergeSort(arr �������� mid ��ĩβ ��������)
//
//    ���� merge(left, right)
//
//function merge(left, right):
//    mergedArr = []
//    i = 0  // �������������
//    j = 0  // �������������
//
//    �� i < ��������ĳ��� �� j < ��������ĳ���ʱ��
//        ��� left[i] <= right[j]��
//            mergedArr ��� left[i]
//            i++
//        ����
//            mergedArr ��� right[j]
//            j++
//
//    ������������ʣ���Ԫ�أ�����еĻ���׷�ӵ� mergedArr ��
//    ������������ʣ���Ԫ�أ�����еĻ���׷�ӵ� mergedArr ��
//
//    ���� mergedArr
//```
//
//�ڹ鲢�����㷨�У�`mergeSort` ��������Ҫ�ĵݹ麯����������������ָ�ɽ�С�������飬ʹ�ù鲢����ݹ�ض����ǽ�������
//Ȼ��ʹ�� `merge` ���������Ǻϲ���һ����������顣`merge` ����������������������飨`left` �� `right`����
//�������Ǻϲ�Ϊһ����������顣`mergeSort` �����ڴﵽ�������ʱ�����ָ����飨�������СΪ1���Сʱ����
//Ȼ������õ���������������Բ������յ����������
//
//�鲢�����㷨�ĸ�Ч��Դ�����ܹ�������ָ�Ϊ��С�������飬�����ܹ���Ч�ؽ��кϲ���������ʱ�临�Ӷ�Ϊ O(n log n)��
//ʹ���Ϊһ�ָ�Ч�������㷨���ر������ڴ������顣