//STL stands for Standard Template Library.It is a powerful library in C++ that provides a collection
//of generic algorithms and data structures.The STL includes various containers, algorithms, and
//iterators that help programmers to write efficient and reusable code.
//
//In addition to the stack data structure, the STL provides several other data structures, including:
//
//1. Vector : A dynamically resizable array.
//2. List : A doubly - linked list.
//3. Forward List : A singly - linked list.
//4. Deque : A double - ended queue.
//5. Queue : A queue to store elements in a FIFO(First - In - First - Out) order.
//6. Priority Queue : A queue that allows elements with higher priority to be processed first.
//7. Set : A container that stores unique elements in a sorted order.
//8. Map : A key - value pair container where the elements are sorted based on the key.
//9. Multiset : A set that allows duplicate elements.
//10. Multimap : A map that allows duplicate keys.
//
//To use any of the STL data structures, including `std: : stack`, you need to include the appropriate
//header file and use the `std` namespace.Here's an example of how to use `std::stack` in your main program:

#include <iostream>
#include <stack>

int main() {
    std::stack<int> myStack;

    myStack.push(10);   // Pushes element 10 into the stack
    myStack.push(20);   // Pushes element 20 into the stack
    myStack.push(30);   // Pushes element 30 into the stack

    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";  // Accesses the top element of the stack
        myStack.pop();                      // Removes the top element from the stack
    }

    return 0;
}

//In the above code, the `<stack > ` header file is included to use the `std::stack` data structure.
//By creating an object of `std::stack<int>`, we can perform stack operations including `push()`, `top()`,
//and `pop()`. Finally, the elements are printed in LIFO(Last - In - First - Out) order by repeatedly accessing
//the top element and removing it from the stack using `pop()`.