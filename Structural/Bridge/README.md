## Bridge

Decouple an abstraction from its implementation so that the two can vary independently. 
Bridge pattern has structural purpose and applies to objects, so it deals with the composition of objects. 


### UML class diagram example for the Bridge Design Pattern.

 - Abstraction - Abstraction defines abstraction interface.
 - AbstractionImpl - Implements the abstraction interface using a reference to an object of type Implementor.
 - Implementor - Implementor defines the interface for implementation classes. This interface does not need to correspond directly to abstraction interface and can be very different. Abstraction imp provides an implementation in terms of operations provided by Implementor interface.
 - ConcreteImplementor1, ConcreteImplementor2 - Implements the Implementor interface.

 
<p align="center">
<img 
src="https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp/blob/master/Structural/Bridge/Bridge.PNG">
</p>

### When to use

* you want to avoid a permanent binding between an abstraction and its implementation
* both the abstractions and their implementations should be extensible by subclassing
* changes in the implementation of an abstraction should have no impact on clients
* you want to hide the implementation of an abstraction completely from clients
