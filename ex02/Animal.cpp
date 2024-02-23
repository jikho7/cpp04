#include "Animal.hpp"

Animal::Animal() :
_type("no type")
{
	std::cout << "(Animal) Default constructor" << std::endl;
}


Animal::Animal(std::string const type) :
_type(type)
{
	std::cout << "(Animal) Parametric constructor" << std::endl;
}

Animal::Animal(const Animal &other)
{
	*this = other;
}

Animal::~Animal()
{
	std::cout << "(Animal) Default destructor" << std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->_type = other.getType();
	}
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "(Animal) makesound" << std::endl;
}

std::string Animal::getType() const
{
	return this->_type;
}
