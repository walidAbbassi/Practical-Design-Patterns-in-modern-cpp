/*
* C++ Design Patterns: Facade
* Author: walid Abbassi [https://github.com/walidAbbassi]
* 2019
*
* Source code is licensed under MIT License
* (for more details see LICENSE)
*
*/

#include <iostream>
#include <ostream>
#include <string>
#include <memory>

/*
 * Subsystems A
 * implement more complex subsystem functionality
 * and have no knowledge of the facade
 */
class Subsystems_A {
public:
	void suboperation_A() const 
	{
		std::cout << "Subsystem A method" << std::endl;
	}
};

/*
 * Subsystems B
 * implement more complex subsystem functionality
 * and have no knowledge of the facade
 */
class Subsystems_B {
public:
	void suboperation_B() const 
	{
		std::cout << "Subsystem B method" << std::endl;
	}
};

/*
 * Subsystems C
 * implement more complex subsystem functionality
 * and have no knowledge of the facade
 */
class Subsystems_C {
public:
	void suboperation_C() const 
	{
		std::cout << "Subsystem C method" << std::endl;
	}
};

/*
 * Facade
 * delegates client requests to appropriate subsystem object
 * and unified interface that is easier to use
 */
class Facade {
public:
	Facade() :
		subsystems_A(std::make_unique<Subsystems_A>()), subsystems_B(std::make_unique<Subsystems_B>()), subsystems_C(std::make_unique<Subsystems_C>())
	{
		std::cout << " --- Welcome --- " << std::endl;
	}
	void operation1() {
		std::cout << " --- operation 1 --- " << std::endl;
		subsystems_A->suboperation_A();
		subsystems_B->suboperation_B();
	}

	void operation2() {
		std::cout << " --- operation 2 --- " << std::endl;
		subsystems_C->suboperation_C();
	}

private:
	std::unique_ptr<Subsystems_A> subsystems_A;
	std::unique_ptr<Subsystems_B> subsystems_B;
	std::unique_ptr<Subsystems_C> subsystems_C;
};


int main()
{
	std::unique_ptr<Facade> facade = std::make_unique<Facade>();
	facade->operation1();
	facade->operation2();
	system("pause");
	return 0;
}
