## Prototype

Specify the kinds of objects to create using a prototypical instance, and create 
new objects by copying this prototype. Pattern has creational purpose and deals 
with object relationships, which are more dynamic. The pattern hides the complexities
of making new instances from the client. 


### UML class diagram example for the Prototype Design Pattern.

 - Client - creates a new object by asking a prototype to clone itself.
 - Prototype - declares an interface for cloning itself.
 - ConcretePrototype - implements the operation for cloning itself.

 
<p align="center">
<img 
src="https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp/blob/master/Creational/prototype/Prototype.PNG">
</p>

### When to use

* when the classes to instantiate are specified at run-time
* to avoid building a class hierarchy of factories that parallels the class hierarchy of products
* when instances of a class can have one of only a few different combinations of state 
