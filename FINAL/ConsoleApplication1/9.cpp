#include <string>
#include <vector>
//C++ templates provide a powerful mechanism for abstraction by allowing code
//to be written in a generic way, independent of specific types.Templates
//enable the creation of generic algorithms and data structures that can work with
//different types without the need for code duplication.
//Here are a few examples to illustrate how C++ templates provide abstraction :
//1. Generic Function Template :
template <typename T>
T multiply(T a, T b) {
    return a * b;
}

int testTempletFun() {
    int result1 = multiply(5, 2);        // using the template with int
    double result2 = multiply(2.5, 3.5); // using the template with double

    return 0;
}
//In this example, the `multiply` function template is defined to work with any type `T`.
//It allows us to multiply two values of the same type, regardless of whether they are integers,
//floating - point numbers, or any other type that supports the `*` operator.
//The template abstracts the multiplication operation and provides a generic implementation
//that works with multiple types.
//
//2. Generic Class Template :
template <typename T>
class Stack {
private:
    std::vector<T> m_data;

public:
    void push(T value) {
        m_data.push_back(value);
    }

    T pop() {
        T value = m_data.back();
        m_data.pop_back();
        return value;
    }
};

int testTempletClass() {
    Stack<int> intStack;
    intStack.push(5);
    intStack.push(10);
    int result1 = intStack.pop(); // pops the last value (10)

    Stack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");
    std::string result2 = stringStack.pop(); // pops the last value ("World")

    return 0;
}
//In this example, the `Stack` class template is defined to work with any type `T`.
//It represents a generic stack data structure that can store elements of any type.
//The template abstracts the implementation of the stack and allows the user to create
//stack objects for different types.It provides a generic interface with methods like
//`push` and `pop`, without the need for separate implementations for each specific type.

//These examples demonstrate how C++ templates provide a mechanism for abstraction by
//allowing the creation of generic code that can work with different types.Templates enable
//us to write algorithms and data structures that are independent of specific types, promoting
//code reuse and avoiding code duplication.Templates provide a flexible way to abstract common
//operations and create generic components that can be used with various types without
//sacrificing performance or type safety.

int main()
{
    testTempletFun();
    testTempletClass();
}