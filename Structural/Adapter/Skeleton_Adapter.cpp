/*
* C++ Design Patterns: Adapter
* Author: walid Abbassi [https://github.com/walidAbbassi]
* 2019
*
* Source code is licensed under MIT License
* (for more details see LICENSE)
*
*/

#include <iostream>
#include <memory>

/*
* Target
* defines specific interface that Client uses
*/
class Target {
public:
	virtual void request_1() const = 0;
	virtual void request_2() const = 0;
	virtual void request_3() const = 0;
	virtual void request_4() const = 0;
	virtual ~Target(){}
	// ...
};

/*
* Adaptee
* all requests get delegated to the Adaptee which defines
* an existing interface that needs adapting
*/
class Adaptee {
public:
	void specificRequest_1() const
	{
		std::cout << " specific request 1 " << std::endl;
		// ...
	}
	void specificRequest_2() const
	{
		std::cout << " specific request 2 " << std::endl;
		// ...
	}
	void specificRequest_3(const int& value) const
	{
		std::cout << " specific request 3 set value = " << value << std::endl;
		// ...
	}
	void specificRequest_4() const
	{
		std::cout << " specific request 4 " << std::endl;
		// ...
	}
	void specificRequest_5() const
	{
		std::cout << " specific request 5 " << std::endl;
		// ...
	}
	~Adaptee(){}
	// ...
};

/*
*  Adapter (i don't have money yet to buy radiator)
* implements the Target interface and lets the Adaptee respond
* to request on a Target by extending both classes
* ie adapts the interface of Adaptee to the Target interface
*/
class Adapter : public Target, private Adaptee {
public:
	virtual void request_1() const override
	{
		specificRequest_1();
		specificRequest_2();
		// ...
	}

	virtual void request_2() const override
	{
		specificRequest_3(5);
		// ...
	}

	virtual void request_3() const override
	{
		specificRequest_3(10);
		// ...
	}

	virtual void request_4() const override
	{
		specificRequest_4();
		specificRequest_5();
		// ...
	}
	virtual ~Adapter(){}
	// ...
};


int main()
{
	std::unique_ptr<Target> target = std::make_unique<Adapter>();
	target->request_1();
	target->request_2();
	target->request_3();
	target->request_4();

	system("pause");
	return 0;
}
