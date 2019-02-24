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
* Heater  ==>  Target
* defines specific interface that Client uses
*/
class Heater {
public:
	virtual void requestTurnOn() const = 0;
	virtual void requestTemperatureHot() const = 0;
	virtual void requestTemperatureVeryHot() const = 0;
	virtual void requestTurnOff() const = 0;
	// ...
};

/*
* Furnace  ==>  Adaptee
* all requests get delegated to the Adaptee which defines
* an existing interface that needs adapting
*/
class Furnace {
public:
	void specificRequestOpen() const 
	{
		std::cout << " specific request Open " << std::endl;
		// ...
	}
	void specificRequestClose() const 
	{
		std::cout << " specific request Close " << std::endl;
		// ...
	}
	void specificRequestThermostat(const int& temperature) const 
	{
		std::cout << " specific request set temperature = " << temperature << std::endl;
		// ...
	}
	void specificRequestTurnOn() const 
	{
		std::cout << " specific request Turn On " << std::endl;
		// ...
	}
	void specificRequestTurnOff() const 
	{
		std::cout << " specific request Turn Off " << std::endl;
		// ...
	}
	// ...
};

/*
* FurnaceAsRadiator  ==>  Adapter (i don't have money yet to buy radiator)
* implements the Target interface and lets the Adaptee respond
* to request on a Target by extending both classes
* ie adapts the interface of Adaptee to the Target interface
*/
class FurnaceAsRadiator : public Heater, private Furnace {
public:
	virtual void requestTurnOn() const override 
	{
		specificRequestOpen();
		specificRequestTurnOn();
		// ...
	}

	virtual void requestTemperatureHot() const override 
	{
		specificRequestThermostat(5);
		// ...
	}

	virtual void requestTemperatureVeryHot() const override 
	{
		specificRequestThermostat(10);
		// ...
	}

	virtual void requestTurnOff() const override 
	{
		specificRequestClose();
		specificRequestTurnOff();
		// ...
	}
	// ...
};


int main()
{
	std::unique_ptr<Heater> heater = std::make_unique<FurnaceAsRadiator>();
	heater->requestTurnOn();
	heater->requestTemperatureHot();
	heater->requestTurnOn();

	system("pause");
	return 0;
}
