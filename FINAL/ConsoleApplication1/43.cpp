#include <iostream>
#include <memory>
//A smart pointer is a programming concept that represents an object that acts like a pointer while providing additional features such as automatic memory management, ownership semantics, and possibly thread safety.It is typically used in languages like C++ to manage dynamically allocated memory and avoid memory leaks and dangling pointer issues.
//
//Smart pointers handle memory deallocation automatically by keeping track of how many references exist to a dynamically allocated object.When the last reference goes out of scope or gets deleted, the smart pointer deallocates the memory automatically.This eliminates the need for manual memory management, like calling `delete` or `free` explicitly.
//
//There are different types of smart pointers available in C++, such as unique_ptr, shared_ptr, and weak_ptr.Each type has its own behavior and use cases.Unique_ptr represents exclusive ownership of an object, shared_ptr allows multiple pointers to share ownership, and weak_ptr is used in conjunction with shared_ptr to break circular dependencies.
//
//Using smart pointers can make your code more robust and less prone to memory management errors.
//
//在C++中，有四种常见的智能指针：unique_ptr、shared_ptr、weak_ptr和auto_ptr（已在C++11中弃用）。
//
//1. unique_ptr:
//-唯一拥有（独占）被指向对象的所有权。
//- 不能拷贝，但可以移动指针的所有权。
//- 当unique_ptr超出作用域时，它所管理的对象会被自动释放，无需手动释放内存。
//- 常用于表示独占性资源的所有权，例如动态分配的内存、文件句柄等。
//
//2. shared_ptr:
//-允许多个指针共享同一个对象的所有权。
//- 使用引用计数来跟踪对象的引用数量，当引用计数为0时，对象会被自动释放。
//- 可以通过拷贝构造函数和赋值运算符进行拷贝和赋值。
//- 可以通过make_shared函数创建shared_ptr，用于更方便地分配动态内存。
//- 常用于需要多个指针共享一个资源的情况。
//
//3. weak_ptr:
//-用于解决shared_ptr可能导致的循环引用问题。
//- 指向shared_ptr所管理的对象，但不会增加引用计数。
//- 可以通过lock()函数将weak_ptr转换为shared_ptr，以便访问所管理的对象。
//- 如果shared_ptr已经释放了对象，lock()函数会返回一个空shared_ptr。
//- 常用于缓存、观察者模式等场景。
//
//4. auto_ptr（已弃用）:
//-在C++11中已被废弃，建议使用unique_ptr替代。
//- 具有类似于unique_ptr的独占所有权特性，但存在一些不安全的行为。
//- 在拷贝时会导致所有权转移，这可能导致潜在的内存泄漏和程序错误。
//
//这些智能指针提供了更安全和方便的内存管理机制，可以避免内存泄漏和悬空指针等常见问题。根据场景和需求，选择适合的智能指针可以使代码更可靠和高效。
//
//在C++中，有四种主要的智能指针：unique_ptr、shared_ptr、weak_ptr和auto_ptr（在C++17中已经被弃用）。让我为你详细介绍每一种智能指针及其使用实例。
//
//1. unique_ptr:
//unique_ptr提供了独占所有权的智能指针，即同一时间只能有一个unique_ptr指向某个对象。当unique_ptr超出作用域或被删除时，它会自动释放所占有的对象内存。
//
//示例代码：
//```cpp
//#include <iostream>
//#include <memory>
//
//int main() {
//    std::unique_ptr<int> ptr(new int(5));
//    std::cout << *ptr << std::endl;  // 输出: 5
//
//    // 使用release()函数释放所有权
//    int* rawPtr = ptr.release();
//
//    // 使用reset()函数重新指定对象
//    ptr.reset(new int(10));
//
//    std::cout << *ptr << std::endl;  // 输出: 10
//
//    delete rawPtr;  // 在释放所有权后手动释放内存
//
//    return 0;
//}
//```
//
//2. shared_ptr:
//shared_ptr允许多个智能指针共享同一个对象，它使用引用计数来跟踪有多少个指针指向同一个对象。当最后一个指针超出作用域或被删除时，对象内存会自动释放。
//
//示例代码：
//```cpp
//#include <iostream>
//#include <memory>
//
//int main() {
//    std::shared_ptr<int> ptr1(new int(5));
//    std::shared_ptr<int> ptr2 = ptr1;
//
//    std::cout << *ptr1 << std::endl;  // 输出: 5
//    std::cout << *ptr2 << std::endl;  // 输出: 5
//
//    ptr1.reset();  // 释放ptr1的所有权
//
//    std::cout << *ptr2 << std::endl;  // 输出: 5
//
//    return 0;
//}
//```
//
//3. weak_ptr:
//weak_ptr是一种不增加引用计数的智能指针，它可以与shared_ptr一起使用，但不会增加引用计数。weak_ptr用于解决shared_ptr之间的循环引用问题。
//
//示例代码：
//```cpp
//#include <iostream>
//#include <memory>
//
int main() {
    std::shared_ptr<int> ptr1 = std::make_shared<int>(5);
    std::weak_ptr<int> ptr2 = ptr1;

    std::cout << *ptr1 << std::endl;  // 输出: 5
    std::cout << *ptr2.lock() << std::endl;  // 输出: 5

    ptr1.reset();  // 释放ptr1的所有权

    if (ptr2.expired()) {
        std::cout << "ptr2 is expired." << std::endl;
    }

    return 0;
}
//```
//
//4. auto_ptr(已弃用) :
//    auto_ptr是C++11之前提供的智能指针，它提供了独占所有权的功能，但在使用过程中存在一些问题，导致在C++17中被弃用。建议使用unique_ptr替代auto_ptr。
//
//    这些智能指针提供了简化内存管理的功能，避免了内存泄漏和悬空指针的问题。使用智能指针可以提高代码的安全性和可维护性。