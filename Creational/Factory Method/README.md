## Factory Method

Define an interface for creating an object, but let subclasses decide which class to instantiate. 
Factory Method lets a class defer instantiation to subclasses. The pattern has creational purpose
and applies to classes where deals with relationships through inheritence ie. they are static-fixed 
at compile time. In contrast to Abstract Factory, Factory Method contain method to produce only one
type of product.  


### UML class diagram example for the Factory Method Design Pattern.

 - Product – Declares an interface for operations that create abstract product objects.
 - ConcreteProduct – Implements the operations declared in the Factory Method to create concrete product objects.
 - Creator – (also refered as Factory because it creates the Product objects) declares the method FactoryMethod, 
			which returns a Product object. May call the generating method for creating Product objects
 - ConcreteCreator – overrides the generating method for creating ConcreteProduct objects
 
<p align="center">
<img 
src="https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp/blob/master/Creational/Factory%20Method/FactoryMethod.PNG">
</p>

### When to use

* a class cant anticipate the class of objects it must create
* a class wants its subclasses to specify the objects it creates
* classes delegate responsibility to one of several helper subclasses, and you want to localize the knowledge of which helper subclass is the delegate 
