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
//软件设计模式是在软件设计与开发过程中常见问题的可复用解决方案。它们提供了指导和结构化的方法，
//用于构建灵活、可维护和可扩展的软件系统。设计模式包含了经过验证的设计原则和最佳实践，可以应用于各种软件开发场景。
//
//策略设计模式是一种行为型设计模式，它定义了一组可互换的算法，并将每个算法封装在自己的类中。
//它允许根据客户端的需求在运行时选择和使用算法。该模式促进了客户端与算法之间的松耦合，使它们能够独立变化。
//
//以下是使用C++实现策略设计模式的示例：
//
//```cpp
//#include <iostream>
//
//// 策略接口
//class SortStrategy {
//public:
//    virtual void sort(int arr[], int size) = 0;
//};
//
//// 具体策略：冒泡排序
//class BubbleSortStrategy : public SortStrategy {
//public:
//    void sort(int arr[], int size) override {
//        // 冒泡排序具体实现
//        std::cout << "使用冒泡排序进行排序。\n";
//        // ...
//    }
//};
//
//// 具体策略：快速排序
//class QuickSortStrategy : public SortStrategy {
//public:
//    void sort(int arr[], int size) override {
//        // 快速排序具体实现
//        std::cout << "使用快速排序进行排序。\n";
//        // ...
//    }
//};
//
//// 上下文类
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
//    // 使用冒泡排序策略
//    BubbleSortStrategy bubbleSort;
//    Sorter sorter(&bubbleSort);
//    sorter.sortArray(arr, 5);
//
//    // 使用快速排序策略
//    QuickSortStrategy quickSort;
//    sorter.setStrategy(&quickSort);
//    sorter.sortArray(arr, 5);
//
//    return 0;
//}
//```
//
//在上述代码中，我们定义了一个`SortStrategy`接口，用于定义排序方法。
//具体策略`BubbleSortStrategy`和`QuickSortStrategy`根据各自的实现来实现排序算法。
//
//`Sorter`类充当了上下文，它使用策略。它具有对`SortStrategy`接口的引用，并将排序操作委托给所选策略。
//
//通过使用策略设计模式，我们可以轻松切换不同的排序算法（`BubbleSortStrategy`或`QuickSortStrategy`），
//而无需修改`Sorter`类。这提供了代码的灵活性和可扩展性。此外，它促进了关注点的分离，
//使得客户端代码能够独立于算法的实现细节而变化。
//
//下面是一个使用UML表示策略设计模式的图示：
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
//在代码中，使用策略设计模式的地方通过注释进行了突出显示，其中演示了如何动态地使用和交换策略。