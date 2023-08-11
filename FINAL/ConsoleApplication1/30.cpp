//A dangling pointer is a pointer that points to a memory location that has been
//deallocated or freed.The memory that the pointer is pointing to may have been
//released explicitly using the `delete` operator or it may have gone out of scope.
//Accessing or dereferencing a dangling pointer can lead to undefined behavior,
//as the memory it points to may have been reallocated for another purpose or may no longer exist.
//
//Here's an example in C++ that demonstrates how a dangling pointer may arise:

#include <iostream>
#include <ostream>

int* createInt() {
    int num = 10;
    int* numPtr = &num;
    return numPtr;
}

void danglingPointerExample() {
    int* ptr = createInt();  // Function creates a pointer to a local variable

    // The pointer 'ptr' now points to a memory location that is deallocated
    // and accessing or dereferencing it will result in undefined behavior
    std::cout << *ptr << std::endl;

    int* pptr = new int(5);
    delete pptr;
    pptr = nullptr;
}

//In this example, the `createInt()` function creates a local integer variable `num` and assigns its address to the pointer
//`numPtr`. The function then returns the pointer `numPtr`. However, `num` is a local variable within the function's scope,
//and when the function ends, the memory allocated for `num` is deallocated. As a result, the pointer `ptr` in the
//`danglingPointerExample()` function becomes a dangling pointer.
//
//When we attempt to dereference or access the value pointed to by `ptr` using `*ptr`, undefined behavior occurs since the
//memory it points to is no longer valid.
//
//To avoid dangling pointers, it is important to ensure that pointers are always pointing to valid memory locations
//This can be achieved by either allocating memory dynamically on the heap using `new` and properly freeing it
//using `delete` or by ensuring that pointers are not pointing to memory locations that have gone out of scope.
