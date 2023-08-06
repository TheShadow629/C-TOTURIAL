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
//��C++�У������ֳ���������ָ�룺unique_ptr��shared_ptr��weak_ptr��auto_ptr������C++11�����ã���
//
//1. unique_ptr:
//-Ψһӵ�У���ռ����ָ����������Ȩ��
//- ���ܿ������������ƶ�ָ�������Ȩ��
//- ��unique_ptr����������ʱ����������Ķ���ᱻ�Զ��ͷţ������ֶ��ͷ��ڴ档
//- �����ڱ�ʾ��ռ����Դ������Ȩ�����綯̬������ڴ桢�ļ�����ȡ�
//
//2. shared_ptr:
//-������ָ�빲��ͬһ�����������Ȩ��
//- ʹ�����ü��������ٶ�������������������ü���Ϊ0ʱ������ᱻ�Զ��ͷš�
//- ����ͨ���������캯���͸�ֵ��������п����͸�ֵ��
//- ����ͨ��make_shared��������shared_ptr�����ڸ�����ط��䶯̬�ڴ档
//- ��������Ҫ���ָ�빲��һ����Դ�������
//
//3. weak_ptr:
//-���ڽ��shared_ptr���ܵ��µ�ѭ���������⡣
//- ָ��shared_ptr������Ķ��󣬵������������ü�����
//- ����ͨ��lock()������weak_ptrת��Ϊshared_ptr���Ա����������Ķ���
//- ���shared_ptr�Ѿ��ͷ��˶���lock()�����᷵��һ����shared_ptr��
//- �����ڻ��桢�۲���ģʽ�ȳ�����
//
//4. auto_ptr�������ã�:
//-��C++11���ѱ�����������ʹ��unique_ptr�����
//- ����������unique_ptr�Ķ�ռ����Ȩ���ԣ�������һЩ����ȫ����Ϊ��
//- �ڿ���ʱ�ᵼ������Ȩת�ƣ�����ܵ���Ǳ�ڵ��ڴ�й©�ͳ������
//
//��Щ����ָ���ṩ�˸���ȫ�ͷ�����ڴ������ƣ����Ա����ڴ�й©������ָ��ȳ������⡣���ݳ���������ѡ���ʺϵ�����ָ�����ʹ������ɿ��͸�Ч��
//
//��C++�У���������Ҫ������ָ�룺unique_ptr��shared_ptr��weak_ptr��auto_ptr����C++17���Ѿ������ã�������Ϊ����ϸ����ÿһ������ָ�뼰��ʹ��ʵ����
//
//1. unique_ptr:
//unique_ptr�ṩ�˶�ռ����Ȩ������ָ�룬��ͬһʱ��ֻ����һ��unique_ptrָ��ĳ�����󡣵�unique_ptr�����������ɾ��ʱ�������Զ��ͷ���ռ�еĶ����ڴ档
//
//ʾ�����룺
//```cpp
//#include <iostream>
//#include <memory>
//
//int main() {
//    std::unique_ptr<int> ptr(new int(5));
//    std::cout << *ptr << std::endl;  // ���: 5
//
//    // ʹ��release()�����ͷ�����Ȩ
//    int* rawPtr = ptr.release();
//
//    // ʹ��reset()��������ָ������
//    ptr.reset(new int(10));
//
//    std::cout << *ptr << std::endl;  // ���: 10
//
//    delete rawPtr;  // ���ͷ�����Ȩ���ֶ��ͷ��ڴ�
//
//    return 0;
//}
//```
//
//2. shared_ptr:
//shared_ptr����������ָ�빲��ͬһ��������ʹ�����ü����������ж��ٸ�ָ��ָ��ͬһ�����󡣵����һ��ָ�볬���������ɾ��ʱ�������ڴ���Զ��ͷš�
//
//ʾ�����룺
//```cpp
//#include <iostream>
//#include <memory>
//
//int main() {
//    std::shared_ptr<int> ptr1(new int(5));
//    std::shared_ptr<int> ptr2 = ptr1;
//
//    std::cout << *ptr1 << std::endl;  // ���: 5
//    std::cout << *ptr2 << std::endl;  // ���: 5
//
//    ptr1.reset();  // �ͷ�ptr1������Ȩ
//
//    std::cout << *ptr2 << std::endl;  // ���: 5
//
//    return 0;
//}
//```
//
//3. weak_ptr:
//weak_ptr��һ�ֲ��������ü���������ָ�룬��������shared_ptrһ��ʹ�ã��������������ü�����weak_ptr���ڽ��shared_ptr֮���ѭ���������⡣
//
//ʾ�����룺
//```cpp
//#include <iostream>
//#include <memory>
//
int main() {
    std::shared_ptr<int> ptr1 = std::make_shared<int>(5);
    std::weak_ptr<int> ptr2 = ptr1;

    std::cout << *ptr1 << std::endl;  // ���: 5
    std::cout << *ptr2.lock() << std::endl;  // ���: 5

    ptr1.reset();  // �ͷ�ptr1������Ȩ

    if (ptr2.expired()) {
        std::cout << "ptr2 is expired." << std::endl;
    }

    return 0;
}
//```
//
//4. auto_ptr(������) :
//    auto_ptr��C++11֮ǰ�ṩ������ָ�룬���ṩ�˶�ռ����Ȩ�Ĺ��ܣ�����ʹ�ù����д���һЩ���⣬������C++17�б����á�����ʹ��unique_ptr���auto_ptr��
//
//    ��Щ����ָ���ṩ�˼��ڴ����Ĺ��ܣ��������ڴ�й©������ָ������⡣ʹ������ָ�������ߴ���İ�ȫ�ԺͿ�ά���ԡ�