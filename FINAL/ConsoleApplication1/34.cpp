//https://zhuanlan.zhihu.com/p/163507047
//https://javatechonline.com/solid-principles-the-single-responsibility-principle/
//The SOLID principles are a set of five design principles in object - oriented programming that aim to make software designs more maintainable and flexible.Here is an overview of each principle :
//
//1. Single Responsibility Principle(SRP) :
//	-A class should have only one reason to change, i.e., it should have only one responsibility.
//	- Each class should be focused on performing a single task or responsibility.
//	- This principle helps in achieving high cohesion and reducing coupling between classes.
//
//	In my lab exercises and assignments, I have followed the SRP by designing classes with specific responsibilities.For example, in a banking system, I had separate classes for managing customer accounts, processing transactions, and generating reports.This way, each class had a single responsibility, making it easier to understand, test, and maintain the system.
//
//	2. Open - Closed Principle(OCP) :
//	-Software entities(classes, modules, functions, etc.) should be open for extension but closed for modification.
//	- The behavior of a class can be extended without modifying its source code.
//	- This principle promotes the use of abstractions, inheritance, and interfaces to allow for future changes or additions.
//
//	In my assignments, I have utilized the OCP by favoring abstraction over concrete implementations.For example, I created abstract classes or interfaces to define common behavior that can be extended by subclasses or implemented by multiple classes.This approach allows adding new functionality by creating new subclasses or implementing new interfaces without modifying existing code.
//
//	3. Liskov Substitution Principle(LSP) :
//	-Objects of a superclass should be replaceable with objects of its subclasses without breaking the correctness of the program.
//	- Subclasses should be able to be used in place of their base classes without causing unexpected behavior.
//	- This principle ensures that the inheritance hierarchy is designed properly, maintaining behavioral consistency.
//
//	In my lab exercises and assignments, I have followed the LSP by ensuring that subclasses can be substituted for their base classes without issues.For example, if I had a base class `Shape` with a virtual method `draw()`, I made sure that any derived class (e.g., `Circle`, `Rectangle`) could be used interchangeably in situations where `Shape` was expected.This principle helps create a robust and flexible object - oriented design.
//
//	4. Interface Segregation Principle(ISP) :
//		-Clients should not be forced to depend on interfaces they do not use.
//		- Classes should have granular interfaces, tailored to the specific needs of clients.
//		- This principle promotes the creation of smaller, focused interfaces rather than large, monolithic ones.
//
//		In my assignments, I have applied the ISP by designing interfaces that are specific and cohesive.For example, if I had a multimedia player, I would define separate interfaces for playback control, playlist management, and metadata retrieval rather than one encompassing interface.This allows clients to depend only on the interfaces they need, reducing coupling and making the codebase more maintainable.
//
//		5. Dependency Inversion Principle(DIP) :
//		-High - level modules should not depend on low - level modules.Both should depend on abstractions.
//		- Abstractions should not depend on details.Details should depend on abstractions.
//		- This principle encourages the use of abstractions and dependency injection to decouple classes, making them more flexible and promoting easier testing and maintenance.
//
//		In my lab exercises and assignments, I have followed the DIP by relying on abstractions and injecting dependencies.For example, I used interfaces or abstract classes to define dependencies between modules, allowing for easy swapping of implementations.This principle facilitates loose coupling and enables the creation of modular, testable, and extensible systems.
//
//		By adhering to the SOLID principles in my coding practices, I aim to create well - organized, maintainable, and easily extensible software systems.While I cannot provide specific code examples from my previous lab exercises or assignments, I hope that the explanations above illustrate how I have applied these principles in my programming practices.