//The PIMPL(Pointer to Implementation) idiom, also known as the Opaque Pointer idiom, is a technique used in C++ to achieve information hiding and separate the interface from the implementation details of a class.It involves using a pointer to a separate, private implementation class that holds the actual implementation details.The public class serves as a wrapper or interface that delegates calls to the private implementation class.
//
//The main purpose of using the PIMPL idiom is to minimize compile - time dependencies and achieve binary compatibility.It allows changes in the implementation class without requiring recompilation of the client code that uses the public class.This can be beneficial in scenarios such as :
//
//1. Encapsulation and Information Hiding : The PIMPL idiom allows you to hide the implementation details of a class from the client code.Only the public interface is visible, providing better encapsulation and reducing the chances of breaking client code when implementation details change.
//
//2. Reducing Compile - time Dependencies : By separating the interface and implementation, any changes made to the implementation class won't affect the client code. This reduces the need for recompilation of dependent code, leading to faster build times and greater flexibility in evolving the codebase.
//
//3. Enhancing Binary Compatibility : The PIMPL idiom enables forward compatibility, where the binary compatibility of a library or API is maintained across versions.With the implementation details hidden behind the PIMPL pointer, you can add, remove, or modify members of the private implementation class without affecting the existing binary interface exposed by the public class.
//
//4. Reducing Header File Dependencies : Since the private implementation class is not exposed in the header file of the public class, the client code doesn't need to include the implementation-specific headers. This reduces the compilation time and avoids exposing unnecessary implementation details to the client code.
//
//It is important to note that the PIMPL idiom introduces an additional level of indirection and dynamic memory allocation, which can have a slight impact on performance.Therefore, it is recommended to use the PIMPL idiom judiciously and only when the benefits of information hiding, reduced dependencies, and binary compatibility outweigh the associated costs.
//
//PIMPL（Pointer to Implementation）习语，也被称为Opaque Pointer（不透明指针）习语，
//是一种在C++中用于实现信息隐藏和将类的接口与实现细节分离的技术。它涉及使用指向私有实现类的指针，
//该实现类保存了真正的实现细节。公共类作为一个包装器或接口，将调用委托给私有实现类。
//
//使用PIMPL习语的主要目的是减少编译时依赖关系并实现二进制兼容性。它允许在不需要重新编译使用公共类的客户端代码的情况下更改实现类。
//这在以下情况下很有用：
//
//1. 封装和信息隐藏：PIMPL习语允许你隐藏类的实现细节，客户端代码只能看到公共接口，提供更好的封装性，并减少实现细节更改对客户端代码的影响。
//
//2. 减少编译时依赖：通过分离接口和实现，对实现类的任何更改都不会影响客户端代码。这减少了依赖代码重新编译的需求，提高了构建速度，
//并在代码库演进时提供了更大的灵活性。
//
//3. 增强二进制兼容性：PIMPL习语实现了向前兼容性，即在版本之间保持库或API的二进制兼容性。通过将实现细节隐藏在PIMPL指针后面，
//你可以添加、删除或修改私有实现类的成员，而不会影响公共类所暴露的现有二进制接口。
//
//4. 减少头文件依赖：由于私有实现类不会在公共类的头文件中公开，客户端代码不需要包含与实现相关的头文件。
//这减少了编译时间，并避免将不必要的实现细节暴露给客户端代码。
//
//需要注意的是，PIMPL习语引入了额外的间接层和动态内存分配，这可能会对性能产生轻微影响。
//因此，建议谨慎使用PIMPL习语，只有在信息隐藏、降低依赖关系和二进制兼容性的好处超过相关成本时才使用。

















