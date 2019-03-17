## C++ SOLID 

is an acronym for the first five object-oriented design(OOD)** principles** by Robert C. Martin
These principles, when combined together, make it easy for a programmer to develop software that are easy to maintain and extend. They also make it easy for developers to avoid code smells, easily refactor code, and are also a part of the agile or adaptive software development.

- Single responsibility principle
- Open–closed principle
- Liskov substitution principle
- Interface segregation principle
- Dependency inversion principle


## C++ Design Patterns (do not abuse them: let the thing simple as possible)

Software design patterns are general reusable solutions to problems which occur
over and over again in object-oriented design enviroment. It is not a finished 
design that can be transformed into source code directly, but it is template how
to solve the problem. We can classify them by purpose into creational (abstract 
the instantiation process), structure (how classes and objects are composed to form 
larger structures) and behavioral patterns (the assignment of responsibilities between 
objects).  

#### Creational Patterns 
- [Abstract Factory], families of product objects
- [Builder], how a composite object gets created
- [Factory Method], subclass of object that is instantiated
- [Prototype], class of object that is instantiated
- [Singleton], the sole instance of a class 
#### Structural Patterns
- [Adapter], interface to an object
- [Bridge], implementation of an object 
- [Composite], structure and composition of an object
- [Decorator], responsibilities of an object without subclassing
- [Façade later], interface to a subsystem
- [Flyweight later], storage costs of objects
- [Proxy later], how an object is accessed (its location)
#### Behavioral Patterns
- [Chain of Responsibility later], object that can fulfill a request
- [Command later], when and how a request is fulfilled
- [Interpreter later], grammar and interpretation of a language
- [Iterator later], how an aggregate's elements are accessed
- [Mediator later], how and which objects interact with each other
- [Memento later], what private information is stored outside an object, and when 
- [Observer later], how the dependent objects stay up to date
- [State later], states of an object
- [Strategy later], an algorithm
- [Template Method later], steps of an algorithm
- [Visitor later], operations that can be applied to objects without changing their classes

### Other Languages
In my repository you can find implementation of desgin patterns also in languages as 

* [Design Patterns in C++]
* [Design Patterns in Python later]
* [Design Patterns in Java later]

### References
Design patterns in this repository are based on

* [SOLID]
* [Design Patterns by The "Gang of Four"]
* [Head First: Design Patterns]
* [Design Principles]
* [Wikipedia]

[Design Patterns in C++]: https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp
[Design Patterns in Python]: https://github.com/JakubVojvoda/design-patterns-python
[Design Patterns in Java]: https://github.com/JakubVojvoda/design-patterns-java

[SOLID]: https://en.wikipedia.org/wiki/SOLID
[Design Patterns by The "Gang of Four"]: https://en.wikipedia.org/wiki/Design_Patterns
[Head First: Design Patterns]: http://www.headfirstlabs.com/books/hfdp/ 
[Design Principles]: https://www.oodesign.com/design-principles.html
[Wikipedia]: https://en.wikipedia.org/wiki/Software_design_pattern

[Abstract Factory]: https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp/tree/master/Creational/Abstract%20Factory
[Builder]: https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp/tree/master/Creational/Builder
[Factory Method]: https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp/tree/master/Creational/Factory%20Method
[Prototype]: https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp/tree/master/Creational/prototype
[Singleton]: https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp/tree/master/Creational/Singleton
[Adapter]: https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp/tree/master/Structural/Adapter
[Bridge]: https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp/tree/master/Structural/Bridge
[Composite]: https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp/tree/master/Structural/Composite
[Decorator]: https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp/tree/master/Structural/Decorator
[Façade]: https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp
[Flyweight]: https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp
[Proxy]: https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp
[Chain of Responsibility]: https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp
[Command]: https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp
[Interpreter]: https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp
[Iterator]: https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp
[Mediator]: https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp
[Memento]: https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp
[Observer]: https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp
[State]: https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp
[Strategy]: https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp
[Template Method]: https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp
[Visitor]: https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp
