//A memory leak occurs in a program when allocated memory is not properly deallocated or released,
//resulting in memory that is no longer accessible but still reserved by the program.As a result,
//the program gradually consumes more and more memory, leading to a decrease in available memory
//for other tasks and potentially causing the program to crash or slow down.
//
//Here's an example in C++ that demonstrates a memory leak:

void memoryLeakExample() {
    int* numPtr = new int;  // Allocate memory on the heap

    // Pointer is not deleted, causing a memory leak
}
//
//In this example, we allocate memory on the heap using the `new` operator to create an `int` object and store the address in the `numPtr` pointer.However, we forget to delete the allocated memory using the `delete` operator.
//
//A correct version of the code should include the deletion of the allocated memory :

void noMemoryLeakExample() {
    int* numPtr = new int;  // Allocate memory on the heap

    // Perform some operations with numPtr

    delete numPtr;  // Deallocate the memory to avoid a memory leak
}

//In this corrected version, the `delete` operator is used to deallocate the memory, preventing a memory leak.
//
//It is important to note that memory leaks can occur in more complex scenarios involving multiple objects
//and data structures.For example, if memory is allocated within loops or conditional blocks but not properly
//deallocated, memory leaks can accumulate over time.It is good practice to always ensure that every allocation
//is matched with a corresponding deallocation to avoid memory leaks and manage memory efficiently.