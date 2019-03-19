## Flyweight

Flyweight pattern has has structural purpose, applies to objects and uses sharing to support 
large numbers of fine-grained objects efficiently. The pattern can be used to reduce 
memory usage when you need to create a large number of similar objects.


### UML class diagram example for the Flyweight Design Pattern.

 - Flyweight - Declares an interface through which flyweights can receive and act on extrinsic state.
 - ConcreteFlyweight 
 	- Implements the Flyweight interface and stores intrinsic state. 
	- A ConcreteFlyweight object must be sharable. 
	- The Concrete flyweight object must maintain state that it is intrinsic to it, and must be able to manipulate state that is extrinsic. 
	- In the war game example graphical representation is an intrinsic state, where location and health states are extrinsic.
	- Soldier moves, the motion behavior manipulates the external state (location) to create a new location.
 - FlyweightFactory 
 	- The factory creates and manages flyweight objects. In addition the factory ensures sharing of the flyweight objects.
	- The factory maintains a pool of different flyweight objects and returns an object from the pool if it is already created, 
	- adds one to the pool and returns it in case it is new.
	- In the war example a Soldier Flyweight factory can create two types of flyweights : a Soldier flyweight,as well as a Colonel Flyweight. When the Client asks the Factory for a soldier,
		the factory checks to see if there is a soldier in the pool, if there is, it is returned to the client,
		if there is no soldier in pool, a soldier is created, added to pool, and returned to the client,
		the next time a client asks for a soldier, the soldier created previously is returned, no new soldier is created.
 - Client - A client maintains references to flyweights in addition to computing and maintaining extrinsic state

 
<p align="center">
<img 
src="https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp/blob/master/Structural/Flyweight/Flyweight.PNG">
</p>

### When to use

* when one instance of a class can be used to provide many "virtual instances"
* when all of the following are true
 * an application uses a large number of objects
 * storage costs are high because of the sheer quantity of objects
 * most object state can be made extrinsic
 * many groups of objects may be replaced by relatively few shared objects once extrinsic state is removed
 * the application doesn't depend on object identity 
