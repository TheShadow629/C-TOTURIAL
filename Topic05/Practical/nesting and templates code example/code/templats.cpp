#include <iostream>

	// use of accessors/getters and mutators/setters in nested classes.
	// Instead of creating separate classes, nested classes created using the template mechanism
	// Enables deeper level of nesting classes for demonstration purposes without having to write a lot
	// of code. Also shows the utility of the template mechanism.

	// Normally a template class would in its own .h file. In this demo, it is kept in the same file
	// for demonstration purposes only.


	// modified March 2022
	// smr March 2018

	// Use a debugger to single step through each call. Check if the Law of Demeter is kept.

using std::cout; // exposing only what is needed instead of the whole std namespace
using std::endl;
using std::ostream;

template <class T>
class A
{
    T dat; // private by default. Normally declared as private, after the public stuff, but kept at the top to show what data is going to be nested.

public:
    const T& get() const  // accessor/getter is const. Why const twice?
    {
        return dat;
    }

		// mutator/setter is not const. parameter is const as setter shouldn't modify the parameter sent by caller
    void set(const T& in)
    {
        dat = in;
    }
};

typedef A<int> AintType;
typedef A<AintType> B; // class B is class A bound to AintType
typedef A<B> C; // class C is class A bound to B

	// If you like, keep going using the same pattern above to increase nesting
	// A::dat is int, but, B::dat and C::dat are not integers
	// Draw an UML diagram for the relationship above.

	// //////////////////////////////
	// As each nested class has the same "data" and methods, one output routine will do.
	// If each class is different, then an output routine is needed for each.
template <class T>
ostream& operator<<(ostream &os, const A<T> &d)
		// will bind to classes based on class A - the binding needed as method get() is used
		// ostream& operator<<(ostream &os, const T &d)  // commented out version will work, but will bind to other types not based on class A.
{
    cout << d.get();
		//cout << d << endl; // would result in repeated calls of the operator - would not go to the internal data - try it with the debugger single step

    return os;
}

int main()
{
    AintType a; // object a has integer internal data will be set by the setter
    B b;  // object b will contain object a via the setter
    C c; // object c will contain object b via the setter

    int i = 5;      // Use the debugger and single step

    a.set(i); // a contains a built in type integer value

    cout << i << endl;

    cout << a << endl;

    b.set(a);  // object b contains object a

    cout << b << endl;   // b contains a. Which operator << is called?

    c.set(b);  // object c contains object b

    cout << c << endl; //c contains b, b contains a - draw UML class diagram to check

    return 0;
}
