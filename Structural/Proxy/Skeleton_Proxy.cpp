/*
* C++ Design Patterns: Proxy
* Author: walid Abbassi [https://github.com/walidAbbassi]
* 2019
*
* Source code is licensed under MIT License
* (for more details see LICENSE)
*
*/

#include <iostream>
#include <memory>
#include <string>

/*
 * Subject
 * defines the common interface for RealSubject and Proxy
 * so that a Proxy can be used anywhere a RealSubject is expected
 */
class Subject {
public:
	virtual ~Subject() { /* ... */ }

	virtual void operation() const = 0;
};

/*
 * Real Subject
 * defines the real object that the proxy represents
 */
class RealSubject : public Subject {
public:
	RealSubject() = default;
	void operation() const override
	{
		std::cout << "Real Subject request" << std::endl;
	}
};

/*
 * Proxy
 * maintains a reference that lets the proxy access the real subject
 */
class Proxy : public Subject {
public:
	Proxy() : realSubject(std::make_unique<RealSubject>()) {}

	void operation() const override
	{
		std::cout << "pass by proxy" << std::endl;
		realSubject->operation();
	}

private:
	std::unique_ptr<RealSubject> realSubject;
};


int main()
{
	std::unique_ptr<Proxy> proxy = std::make_unique<Proxy>();
	proxy->operation();
	system("pause");
	return 0;
}
