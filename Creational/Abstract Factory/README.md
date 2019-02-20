## Abstract Factory

Abstract factory pattern has creational purpose and provides an interface for 
creating families of related or dependent objects without specifying their 
concrete classes. Pattern applies to object and deal with object relationships, 
which are more dynamic. In contrast to Factory Method, Abstract Factory pattern
produces family of types that are related, ie. it has more than one method of 
types it produces.
So at runtime, abstract factory is coupled with any desired concrete factory which can create objects of desired type.


### UML class diagram example for the Abstract Factory Design Pattern.

 - AbstractFactory : Declares an interface for operations that create abstract product objects.
 - ConcreteFactory : Implements the operations declared in the AbstractFactory to create concrete product objects.
 - Product : Defines a product object to be created by the corresponding concrete factory and implements the AbstractProduct interface.
 - Client : Uses only interfaces declared by AbstractFactory and AbstractProduct classes.
 
<p align="center">
<img 
src="https://github.com/walidAbbassi/Example-Design-Patterns/blob/master/Creational/Abstract%20Factory/AbstractFactory.PNG">
</p>

### When to use

* a system should be independent of how its products are created, composed, and represented
* a system should be configured with one of multiple families of products
* a family of related product objects is designed to be used together
* you want to provide a class library of products, and you want to reveal just their interfaces, not their implementations
