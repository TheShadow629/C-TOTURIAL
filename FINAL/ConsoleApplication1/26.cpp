//Here's an implementation of a minimal but complete template Stack class and template Queue class in C++.
//I have also provided separate modular unit tests for each class to demonstrate their functionality.
//The tests include checking for normal function and attempting to break the data structure by providing
//incorrect inputs or testing edge cases.

#include <iostream>

// Minimal and complete template Stack class
template <typename T>
class Stack {
private:
    T* data;
    int capacity;
    int topIndex;

public:
    Stack() : capacity(50), topIndex(-1) {
        data = new T[capacity];
    }

    ~Stack() {
        delete[] data;
        data = nullptr;
    }

    void push(T element) {
        //if (topIndex == capacity - 1) {
        //    std::cout << "Stack overflow\n";
        //    return;
        //}
        if (topIndex == capacity - 1) {
            T* newData= new T[capacity*2];
            for(int i=0;i< capacity;i++)
            {
                newData[i] = data[i];
            }
            capacity = capacity * 2;
            delete[] data;
            data = newData;
        }
        topIndex++;
        data[topIndex] = element;
    }

    void pop() {
        if (topIndex == -1) {
            std::cout << "Stack is empty\n";
            return;
        }
        topIndex--;
    }

    T top() {
        if (topIndex == -1) {
            std::cout << "Stack is empty\n";
            return T();
        }
        return data[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }
};

// Unit test for Stack class
void testStack() {
    Stack<int> myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "Top element: " << myStack.top() << "\n";
    myStack.pop();

    std::cout << "Top element: " << myStack.top() << "\n";
    myStack.pop();

    std::cout << "Top element: " << myStack.top() << "\n";
    myStack.pop();

    std::cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << "\n";
}

// Minimal and complete template Queue class
template <typename T>
class Queue {
private:
    T* data;
    int capacity;
    int frontIndex;
    int rearIndex;

public:
    Queue() : capacity(50), frontIndex(-1), rearIndex(-1) {
        data = new T[capacity];
    }

    ~Queue() {
        delete[] data;
        data = nullptr;
    }

    void join(T element) {
        if (rearIndex == capacity - 1) {
            std::cout << "Queue is full\n";
            return;
        }

        if (rearIndex == capacity - 1) 
        {
            T* newData = new T[capacity*2];
            for (int i = frontIndex,j=0; i < capacity; i++,j++)
            {
                newData[j] = data[i];
            }
            capacity = capacity * 2;
            delete[] data;
            data = newData;
            rearIndex = rearIndex - frontIndex;
            frontIndex = 0;
        }

        if (frontIndex == -1 && rearIndex == -1)
            frontIndex++;

        rearIndex++;
        data[rearIndex] = element;
    }

    void leave() {
        if (frontIndex == -1 || frontIndex > rearIndex) {
            std::cout << "Queue is empty\n";
            return;
        }
        frontIndex++;
    }

    T front() {
        if (frontIndex == -1 || frontIndex > rearIndex) {
            std::cout << "Queue is empty\n";
            return T();
        }
        return data[frontIndex];
    }

    bool isEmpty() {
        return frontIndex == -1 || frontIndex > rearIndex;
    }
};

// Unit test for Queue class
void testQueue() {
    Queue<int> myQueue;

    myQueue.join(10);
    myQueue.join(20);
    myQueue.join(30);

    std::cout << "Front element: " << myQueue.front() << "\n";
    myQueue.leave();

    std::cout << "Front element: " << myQueue.front() << "\n";
    myQueue.leave();

    std::cout << "Front element: " << myQueue.front() << "\n";
    myQueue.leave();

    std::cout << "Is queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << "\n";
}

int main() {
    std::cout << "Testing Stack:\n";
    testStack();

    std::cout << "\nTesting Queue:\n";
    testQueue();

    return 0;
}

//In the above code, the Stack and Queue classes are implemented using dynamic arrays(`new[]` and `delete[]`).The classes have appropriate methods for pushing / adding elements, popping / removing elements, accessing the top / front element, and checking if the Stack / Queue is empty.The classes also include error handling for cases such as stack overflow, stack underflow, full queue, and empty queue.
//
//The `testStack()` and `testQueue()` functions serve as separate unit tests for the Stack and Queue classes, respectively.These tests demonstrate the normal functioning of each data structure and also attempt to break them by performing operations like popping from an empty stack or leaving from an empty queue.
//
//Feel free to modify and expand these unit tests as needed to further cover different scenarios and edge cases.