/*
* C++ Design Patterns: Flyweight
* Author: walid Abbassi [https://github.com/walidAbbassi]
* 2019
*
* Source code is licensed under MIT License
* (for more details see LICENSE)
*
*/

#include <iostream>
#include <map>
#include <memory>
#include <string>

/*
 * FlyWeight
 * declares an interface through which flyweights can receive
 * and act on extrinsic state
 */
class FlyWeight {
public:
	virtual ~FlyWeight() { /* ... */ }
	virtual void operation() const = 0;
};

/*
 * Number ==>UnsharedConcreteFlyweight
 * not all subclasses need to be shared
 */
class Number : public FlyWeight {
public:
	explicit Number(const int& intrinsic_state) :
		state(intrinsic_state) {}

	void operation()  const override
	{
		std::cout << "Unshared Number with state " << state <<std::endl;
	}

private:
	int state;
};

/*
 * ConcreteFlyweight
 * implements the Flyweight interface and adds storage
 * for intrinsic state
 */
class ConcreteFlyweight : public FlyWeight {
public:
	ConcreteFlyweight(const int& all_state) :
		state(all_state) {}

	void operation()  const override 
	{
		std::cout << "Concrete Flyweight with state " << state << std::endl;
	}
private:
	int state;
};



/*
 * CharacterFactory ==> FlyweightFactory
 * creates and manages flyweight objects and ensures
 * that flyweights are shared properly
 */
class FlyweightFactory {
public:
	std::shared_ptr<FlyWeight>getFlyweight(int key) 
	{
		if (flies.find(key) != flies.end()) 
		{
			return flies[key];
		}
		std::shared_ptr<FlyWeight>fly = std::make_shared<ConcreteFlyweight>(key);
		flies.insert(std::pair<int, std::shared_ptr<FlyWeight>>(key, fly));
		return fly;
	}

private:
	std::map<int, std::shared_ptr<FlyWeight>> flies;
};



int main()
{

	std::unique_ptr<FlyweightFactory> factory = std::make_unique<FlyweightFactory>();
	for (size_t i = 0; i < 100; i++)
	{
		factory->getFlyweight(i)->operation();
	}
	system("pause");
	return 0;
}
