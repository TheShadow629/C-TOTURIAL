//Information hiding, also known as encapsulation, is a principle in software engineering
//that emphasizes hiding the internal implementation details of a module or class.It involves
//defining a clear boundary between the public interface(or API) and the private implementation details.
//The main reasons for using information hiding are :
//1. Modularity : Information hiding promotes modular design by separating the
//interface from the implementation.Modules can be developed and modified independently,
//as long as the public interface remains unchanged.This improves code maintainability
//and allows for easier collaboration among developers.
//2. Abstraction : Hiding internal details behind a well - defined interface provides
//abstraction.Clients only need to understand how to interact with the public interface
//without worrying about the underlying implementation.This simplifies code usage, reduces complexity, and improves code readability.
//3. Encapsulation : Information hiding encapsulates related data and behaviors within
//a module or class.By enforcing access through the defined interface, it allows for better
//control and encapsulation of data, preventing direct manipulation and ensuring consistency and integrity.
//Here's an example in C++ demonstrating how information hiding can be implemented:

// Public header file (MyClass.h)
class MyClass
{
public:
    void PublicMethod();

private:
    int privateData;

    void PrivateMethod();
};

// Private implementation file (MyClass.cpp)
//#include "MyClass.h"

void MyClass::PublicMethod()
{
    // Accessible to clients
    privateData = 42;  // Access private data
    PrivateMethod();   // Call private method
}

void MyClass::PrivateMethod()
{
    // Implementation details hidden from clients
}

//In the above example, the public header file `MyClass.h` defines the public interface of
//the class `MyClass`. The private implementation file `MyClass.cpp` contains the implementation details,
//including private data members(`privateData`) and private methods(`PrivateMethod()`).
//Clients using the class can only access the public methods, such as `PublicMethod()`,
//and have no direct knowledge or access to the private members or methods.

//By hiding the implementation details, the class author can modify the private implementation
//without affecting the clients as long as the public interface remains unchanged.This makes it
//easier to maintain and evolve the codebase over time.