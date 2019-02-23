/*
* C++ Design Patterns: Singleton
* Author: walid Abbassi [https://github.com/walidAbbassi]
* 2019
*
* Source code is licensed under MIT License
* (for more details see LICENSE)
*
*/

#include <iostream>
#include <memory>
#include <mutex>

/*
* Singleton
* has private static variable to hold one instance of the class
* and method which gives us a way to instantiate the class
*/
class Singleton {
public:
	static void NofityInit()
	{
		std::cout << "Initializing Singleton" << std::endl;
	}

	static Singleton &getInstance() 
	{
		std::call_once(Singleton::onceFlag, []() {
			NofityInit();
			instance.reset(new Singleton());
		});
		std::cout << "Getting  Singleton instance" << std::endl;
		return *(instance.get());
	}

private:
	static std::unique_ptr<Singleton> instance;
	static std::once_flag onceFlag;

	Singleton() = default;
	Singleton(const Singleton& instance) = delete;
	Singleton &operator=(const Singleton& instance) = delete;
};

std::unique_ptr<Singleton> Singleton::instance;
std::once_flag Singleton::onceFlag;

int main()
{
	Singleton& s1 = Singleton::getInstance();
	Singleton& s2 = Singleton::getInstance();

	system("pause");
	return 0;
}
