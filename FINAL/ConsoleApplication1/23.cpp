//A stack and a queue are both linear data structures but differ in their behavior and specific operations.
//
//1. Stack:
//A stack follows the Last - In - First - Out(LIFO) principle, where the last element added is the first one
//to be removed.The main operations for a stack are :
//-Push : Adds an element to the top of the stack.
//- Pop : Removes the topmost element from the stack.
//- Top : Returns the value of the topmost element without removing it.
//- Empty : Checks if the stack is empty.
//
//Here's an example of implementing a stack using C++:

#include <iostream>
#include <stack>

int testSTLStack() {
    std::stack<int> myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    while (!myStack.empty()) {
        std::cout << myStack.top() << " "; // Print the topmost element
        myStack.pop(); // Remove the topmost element
    }
    return 0;
}

//2. Queue:
//A queue follows the First - In - First - Out(FIFO) principle, where the first element added is the first
//one to be removed.The main operations for a queue are :
//-Enqueue : Adds an element to the back of the queue.
//- Dequeue : Removes the frontmost element from the queue.
//- Front : Returns the value of the frontmost element without removing it.
//- Empty : Checks if the queue is empty.
//
//Here's an example of implementing a queue using C++:

#include <iostream>
#include <queue>

int TestStlQueue() {
    std::queue<int> myQueue;

    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    while (!myQueue.empty()) {
        std::cout << myQueue.front() << " "; // Print the frontmost element
        myQueue.pop(); // Remove the frontmost element
    }
    return 0;
}

//While a stack and a queue have different behavior and operations, it is possible to implement one using the other.Here's an example of implementing a stack using a queue:

#include <iostream>
#include <queue>

class Stack {
private:
    std::queue<int> q;

public:
    void push(int value) {
        int size = q.size();
        q.push(value);

        // Rotate the elements to make the newly added element at the front
        for (int i = 0; i < size; i++) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    //123
    //7654321
    void pop() {
        q.pop();
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int TestMyStack() {
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    while (!myStack.empty()) {
        std::cout << myStack.top() << " "; // Print the topmost element
        myStack.pop(); // Remove the topmost element
    }

    return 0;
}

//In this example, a stack is implemented using a queue by utilizing the `push()` operation to rotate the elements and make the newly added element at the front.
//
//Similarly, it is possible to implement a queue using two stacks by simulating the behavior of a queue with the help of two stacks.


#include <iostream>
#include <stack>

class Queue {
private:
    std::stack<int> inbox;  // Stack to enqueue elements
    std::stack<int> outbox; // Stack to dequeue elements

public:
    void enqueue(int value) {
        inbox.push(value);
    }

    void dequeue() {
        if (outbox.empty()) 
        {
            // Move all elements from inbox to outbox to reverse their order
            while (!inbox.empty()) {
                outbox.push(inbox.top());
                inbox.pop();
            }
        }
        outbox.pop(); // Remove the frontmost element
    }

    int front() {
        if (outbox.empty()) {
            // Move all elements from inbox to outbox to reverse their order
            while (!inbox.empty()) {
                outbox.push(inbox.top());
                inbox.pop();
            }
        }
        return outbox.top(); // Return the frontmost element
    }

    bool empty() {
        return inbox.empty() && outbox.empty();
    }
};

int TestMyQueue() {
    Queue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    while (!myQueue.empty()) {
        std::cout << myQueue.front() << " "; // Print the frontmost element
        myQueue.dequeue(); // Remove the frontmost element
    }

    return 0;
}

//In this example, a queue is implemented using two stacks(`inbox` and `outbox`).The `enqueue()`
//operation is performed by simply pushing elements onto the `inbox` stack.The `dequeue()` and
//`front()` operations are implemented by transferring elements from the `inbox` stack to the `outbox` stack.The frontmost element can be accessed by returning the top of the `outbox` stack.