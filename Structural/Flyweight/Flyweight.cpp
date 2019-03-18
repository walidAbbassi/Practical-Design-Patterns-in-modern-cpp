/*
* C++ Design Patterns: Flyweight
* Author: walid Abbassi [https://github.com/walidAbbassi]
* 2019
*
* Source code is licensed under MIT License
* (for more details see LICENSE)
*
*/

#include <Windows.h>
#include <iostream>
#include <map>
#include <memory>
#include <random>
#include <string>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

enum Color
{
	colorBLUE = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE,
	colorGREEN = FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN,
	colorRED = FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_RED,
	colorDEFAULT = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
};

int generateRandomNumber(int min, int max) 
{
	std::random_device random;
	std::mt19937 generate(random());
	std::uniform_int_distribution<> distribution(min, max);	// distribution in range [min, max]
	return distribution(generate);
}

/*
 * Character  ==>  Flyweight
 * declares an interface through which flyweights can receive
 * and act on extrinsic state
 */
class Character {
public:
	virtual ~Character() { /* ... */ }
	virtual void display(const size_t& size) = 0;
};

/*
 * Number ==>UnsharedConcreteFlyweight
 * not all subclasses need to be shared
 */
class Number : public Character {
public:
	explicit Number(size_t intrinsic_state) :
		state(intrinsic_state) {}

	void display(const size_t& size)  override
	{
		std::cout << "Unshared Number with state " << state << size <<std::endl;
	}

private:
	size_t state;
};

/*
 * CharacterBlue ==> ConcreteFlyweight
 * implements the Flyweight interface and adds storage
 * for intrinsic state
 */
class CharacterBlue: public Character {
public:
	CharacterBlue(const Color& color, const char& symbol) :
		symbol(symbol),color(color) 
	{
		std::cout << "create new symbol " << symbol << "  ";
	}

	void display(const size_t& size) override
	{
		pointSize = size;
		SetConsoleTextAttribute(hConsole, color);
		std::cout << "symbol " << symbol ;
		SetConsoleTextAttribute(hConsole, colorDEFAULT);
		std::cout << " with color Blue " << " (pointsize " << pointSize << " )" << std::endl;
	}
private:
	size_t pointSize = 0;
	char symbol;
	Color color;
	//other Data width / height / ascent
};

/*
 * CharacterGreen ==> ConcreteFlyweight
 * implements the Flyweight interface and adds storage
 * for intrinsic state
 */
class CharacterGreen : public Character {
public:
	CharacterGreen(const Color& color, const char& symbol) :
		symbol(symbol), color(color) 
	{
		std::cout << "create new symbol " << symbol << "  ";
	}

	void display(const size_t& size)  override
	{
		pointSize = size;
		SetConsoleTextAttribute(hConsole, color);
		std::cout << "symbol " << symbol ;
		SetConsoleTextAttribute(hConsole, colorDEFAULT);
		std::cout << " with color Green " << " (pointsize " << pointSize << " )" << std::endl;
	}
private:
	size_t pointSize = 0;
	char symbol;
	Color color;
	//other Data width / height / ascent
};

/*
 * CharacterRed ==> ConcreteFlyweight
 * implements the Flyweight interface and adds storage
 * for intrinsic state
 */
class CharacterRed : public Character {
public:
	CharacterRed(const Color& color, const char& symbol) :
		symbol(symbol), color(color) 
	{
		std::cout << "create new symbol " << symbol << "  ";
	}

	void display(const size_t& size)  override
	{
		pointSize = size;
		SetConsoleTextAttribute(hConsole, color);
		std::cout << "symbol " << symbol ;
		SetConsoleTextAttribute(hConsole, colorDEFAULT);
		std::cout << " with color Red " << " (pointsize " << pointSize << " )" << std::endl;
	}
private:
	size_t pointSize = 0;
	char symbol;
	Color color;
	//other Data width / height / ascent
};

/*
 * CharacterFactory ==> FlyweightFactory
 * creates and manages flyweight objects and ensures
 * that flyweights are shared properly
 */
class CharacterFactory {
public:

	std::shared_ptr<Character> getFlyweight(const char& symbol)
	{
		std::shared_ptr<Character> character = nullptr;
		int indexColor = generateRandomNumber(0,2);							// distribution in range [0, 2]
		std::pair<char, int> key = std::make_pair(symbol, indexColor);

		if (characters.find(key) != characters.end()) {
			return characters[key];
		}
		switch (indexColor)
		{
		case 0:
			character = std::make_shared<CharacterBlue>(colorBLUE, symbol);
			break;
		case 1:
			character = std::make_shared<CharacterGreen>(colorGREEN, symbol);
			break;
		case 2:
			character = std::make_shared<CharacterRed>(colorRED, symbol);
			break;
		default:
			std::cout << "Not Implemented" << std::endl;
			throw("Not Implemented");
		}
		characters.insert(std::pair <std::pair<char, int> , std::shared_ptr<Character>>(key, character));
		return character;
}

private:
	std::map<std::pair<char, int>, std::shared_ptr<Character>> characters;
};



int main()
{

	std::string document;
	constexpr const char alphabets[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	for (size_t i = 0; i < 1000; i++)
	{
		document += alphabets[generateRandomNumber(0, 25)];
	}
	std::cout << "random message created" << std::endl;

	std::unique_ptr<CharacterFactory> factory = std::make_unique<CharacterFactory>();

	// extrinsic state
	int pointSize = 10;

	for (const char& c : document)
	{
		pointSize++;
		std::shared_ptr<Character> character = factory->getFlyweight(c);
		character->display(pointSize);
	}
	SetConsoleTextAttribute(hConsole, colorDEFAULT);
	// if we run example for document containe random 1000 ObjectCharWithColor and print out(oups need to remove std::endl for flush sorry) 
	// with random color(Blue/Green/Red):
	// code without Flyweight design : 1569546 microseconds ==> 1,569546 seconds
	// code with Flyweight design 	 : 1448003 microseconds ==> 1,448003 seconds
	
	// document containe random 100000 ObjectCharWithColor and print out with random color(Blue/Green/Red):
	// code without Flyweight design : 88187505 microseconds ==> 88,187505 seconds
	// code with Flyweight design 	 : 63950289 microseconds ==> 63,950289 seconds
	system("pause");
	return 0;
}
