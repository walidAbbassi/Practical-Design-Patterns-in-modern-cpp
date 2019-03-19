## Proxy

Proxy pattern provides a surrogate or placeholder for another object to control access to it.
The pattern has structural purpose and applies to objects. 


### UML class diagram example for the Bridge Design Pattern.

 - Subject - Interface implemented by the RealSubject and representing its services. 
					The interface must be implemented by the proxy as well so that the proxy can be used in any location where the RealSubject can be used.
 - Proxy	
   - Maintains a reference that allows the Proxy to access the RealSubject.
   - Implements the same interface implemented by the RealSubject so that the Proxy can be substituted for the RealSubject.
   - Controls access to the RealSubject and may be responsible for its creation and deletion.
 - RealSubject - the real object that the proxy represents.

 
<p align="center">
<img 
src="https://github.com/walidAbbassi/Practical-Design-Patterns-in-modern-cpp/blob/master/Structural/Proxy/Proxy.PNG">
</p>

### When to use

* whenever there is a need for a more versatile or sophisticated reference to an object than a simple pointer
