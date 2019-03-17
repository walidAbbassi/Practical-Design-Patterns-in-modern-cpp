## Decorator

Attach additional responsibilities to an object dynamically. Decorators
provide a flexible alternative to subclassing for extending functionality.
The pattern has structural purpose and applies to objects.


### UML class diagram example for the Decorator Design Pattern.

 - Component - Interface for objects that can have responsibilities added to them dynamically.
 - ConcreteComponent - Defines an object to which additional responsibilities can be added.
 - Decorator - Maintains a reference to a Component object and defines an interface that conforms to Component's interface.
 - Concrete Decorators - Concrete Decorators extend the functionality of the component by adding state or adding behavior.

 
<p align="center">
<img 
src="https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp/blob/master/Structural/Decorator/Decorator.PNG">
</p>

### When to use

* to add responsibilities to individual objects dynamically and transparently, that is, without affecting other objects
* for responsibilities that can be withdrawn
* when extension by subclassing is impractical
