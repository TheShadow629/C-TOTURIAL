//////ppt324
////Software Design Patterns are reusable solutions to common problems that occur during software design
////and development. They provide guidance and a structured approach to building software systems that are
////flexible, maintainable, and scalable. Design patterns capture proven design principles and best practices
////that can be applied to various software development scenarios.
////
////The Strategy Design Pattern is a behavioral design pattern that defines a family of interchangeable
////algorithms and encapsulates each algorithm within its own class. It allows the algorithms to be selected
////and used at runtime based on the requirements of the client. This pattern promotes loose coupling between
////the client and the algorithms, enabling them to vary independently.
////
////Here's an example implementation of the Strategy Design Pattern in C++:
////
////```cpp
////#include <iostream>
////
////// Strategy interface
////class SortStrategy {
////public:
////    virtual void sort(int arr[], int size) = 0;
////};
////
////// Concrete strategy: Bubble Sort
////class BubbleSortStrategy : public SortStrategy {
////public:
////    void sort(int arr[], int size) override {
////        // Bubble sort implementation
////        std::cout << "Sorting using bubble sort.\n";
////        // ...
////    }
////};
////
////// Concrete strategy: Quick Sort
////class QuickSortStrategy : public SortStrategy {
////public:
////    void sort(int arr[], int size) override {
////        // Quick sort implementation
////        std::cout << "Sorting using quick sort.\n";
////        // ...
////    }
////};
////
////// Context class
////class Sorter {
////private:
////    SortStrategy* strategy;
////
////public:
////    Sorter(SortStrategy* strategy) : strategy(strategy) {}
////
////    void setStrategy(SortStrategy* strategy) {
////        this->strategy = strategy;
////    }
////
////    void sortArray(int arr[], int size) {
////        strategy->sort(arr, size);
////    }
////};
////
////int main() {
////    int arr[] = { 5, 2, 9, 1, 3 };
////
////    // Using bubble sort strategy
////    BubbleSortStrategy bubbleSort;
////    Sorter sorter(&bubbleSort);
////    sorter.sortArray(arr, 5);
////
////    // Using quick sort strategy
////    QuickSortStrategy quickSort;
////    sorter.setStrategy(&quickSort);
////    sorter.sortArray(arr, 5);
////
////    return 0;
////}
////```
////
////In the above code, we have a `SortStrategy` interface that defines the sorting method.
////The concrete strategies `BubbleSortStrategy` and `QuickSortStrategy` implement the sorting algorithm based on
////their respective implementations.
////
////The `Sorter` class acts as a context that uses the strategy. It has a reference to the `SortStrategy`
////interface and delegates the sorting operation to the selected strategy.
////
////By using the Strategy Design Pattern, we can easily switch between different sorting algorithms
////(`BubbleSortStrategy` or `QuickSortStrategy`) without modifying the `Sorter` class. This provides flexibility
////and extensibility to our code. Additionally, it promotes separation of concerns and enables the client code
////to vary independently from the implementation details of the algorithms.
////
////Here's a UML diagram representing the Strategy Design Pattern:
////
////```
////-------------------------------------
////|             SortStrategy           |
////-------------------------------------
////| + sort(int arr[], int size)        |
////-------------------------------------
////                     /_\
////                      |
////       ----------------------------------------------
////       |                                            |
////-------------------              -------------------
////| BubbleSortStrategy|              | QuickSortStrategy |
////-------------------              -------------------
////| + sort(int arr[], int size) |   | + sort(int arr[], int size) |
////-------------------              -------------------
////
////                     |
////                  ---------
////                  | Sorter |
////                  ---------
////                  | - strategy: SortStrategy* |
////                  -----------------------------
////                  | + setStrategy(SortStrategy* strategy) |
////                  | + sortArray(int arr[], int size) |
////                  -------------------------------------
////```
////
////In the code, the usage of the Strategy Design Pattern is highlighted with comments where the strategies
////are utilized and interchanged dynamically.
//
//������ģʽ�����������뿪�������г�������Ŀɸ��ý�������������ṩ��ָ���ͽṹ���ķ�����
//���ڹ�������ά���Ϳ���չ�����ϵͳ�����ģʽ�����˾�����֤�����ԭ������ʵ��������Ӧ���ڸ����������������
//
//�������ģʽ��һ����Ϊ�����ģʽ����������һ��ɻ������㷨������ÿ���㷨��װ���Լ������С�
//��������ݿͻ��˵�����������ʱѡ���ʹ���㷨����ģʽ�ٽ��˿ͻ������㷨֮�������ϣ�ʹ�����ܹ������仯��
//
//������ʹ��C++ʵ�ֲ������ģʽ��ʾ����
//
//```cpp
//#include <iostream>
//
//// ���Խӿ�
//class SortStrategy {
//public:
//    virtual void sort(int arr[], int size) = 0;
//};
//
//// ������ԣ�ð������
//class BubbleSortStrategy : public SortStrategy {
//public:
//    void sort(int arr[], int size) override {
//        // ð���������ʵ��
//        std::cout << "ʹ��ð�������������\n";
//        // ...
//    }
//};
//
//// ������ԣ���������
//class QuickSortStrategy : public SortStrategy {
//public:
//    void sort(int arr[], int size) override {
//        // �����������ʵ��
//        std::cout << "ʹ�ÿ��������������\n";
//        // ...
//    }
//};
//
//// ��������
//class Sorter {
//private:
//    SortStrategy* strategy;
//
//public:
//    Sorter(SortStrategy* strategy) : strategy(strategy) {}
//
//    void setStrategy(SortStrategy* strategy) {
//        this->strategy = strategy;
//    }
//
//    void sortArray(int arr[], int size) {
//        strategy->sort(arr, size);
//    }
//};
//
//int main() {
//    int arr[] = { 5, 2, 9, 1, 3 };
//
//    // ʹ��ð���������
//    BubbleSortStrategy bubbleSort;
//    Sorter sorter(&bubbleSort);
//    sorter.sortArray(arr, 5);
//
//    // ʹ�ÿ����������
//    QuickSortStrategy quickSort;
//    sorter.setStrategy(&quickSort);
//    sorter.sortArray(arr, 5);
//
//    return 0;
//}
//```
//
//�����������У����Ƕ�����һ��`SortStrategy`�ӿڣ����ڶ������򷽷���
//�������`BubbleSortStrategy`��`QuickSortStrategy`���ݸ��Ե�ʵ����ʵ�������㷨��
//
//`Sorter`��䵱�������ģ���ʹ�ò��ԡ������ж�`SortStrategy`�ӿڵ����ã������������ί�и���ѡ���ԡ�
//
//ͨ��ʹ�ò������ģʽ�����ǿ��������л���ͬ�������㷨��`BubbleSortStrategy`��`QuickSortStrategy`����
//�������޸�`Sorter`�ࡣ���ṩ�˴��������ԺͿ���չ�ԡ����⣬���ٽ��˹�ע��ķ��룬
//ʹ�ÿͻ��˴����ܹ��������㷨��ʵ��ϸ�ڶ��仯��
//
//������һ��ʹ��UML��ʾ�������ģʽ��ͼʾ��
//
//```
//-------------------------------------
//|             SortStrategy           |
//-------------------------------------
//| + sort(int arr[], int size)        |
//-------------------------------------
//                     /_\
//                      |
//       ----------------------------------------------
//       |                                            |
//-------------------              -------------------
//| BubbleSortStrategy|              | QuickSortStrategy |
//-------------------              -------------------
//| + sort(int arr[], int size) |   | + sort(int arr[], int size) |
//-------------------              -------------------
//
//                     |
//                  ---------
//                  | Sorter |
//                  ---------
//                  | - strategy: SortStrategy* |
//                  -----------------------------
//                  | + setStrategy(SortStrategy* strategy) |
//                  | + sortArray(int arr[], int size) |
//                  -------------------------------------
//```
//
//�ڴ����У�ʹ�ò������ģʽ�ĵط�ͨ��ע�ͽ�����ͻ����ʾ��������ʾ����ζ�̬��ʹ�úͽ������ԡ�