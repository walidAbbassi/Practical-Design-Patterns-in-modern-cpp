## Singleton

Ensure a class only has one instance, and provide a global point of access to it.
Pattern has creational purpose and deals with object relationships, which are more 
dynamic.


### UML class diagram example for the Singleton Design Pattern.

 - The Singleton Pattern defines a getInstance operation which exposes the unique instance which is accessed by the clients. 
 - getInstance() - is is responsible for creating its class unique instance in case it is not created yet and to return that instance.

 
<p align="center">
<img 
src="https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp/blob/master/Creational/Singleton/Singleton.PNG">
</p>

### When to use

* there must be exactly one instance of a class, and it must be accessible to clients from a well-known access point
* when the sole instance should be extensible by subclassing, and clients should be able to use an extended instance without modifying their code
