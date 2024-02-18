#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() :
_type("no type")
{
	std::cout << "(WrongAnimal) Default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) :
_type(type)
{
	std::cout << "(WrongAnimal) Parametric constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	*this = other;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "(WrongAnimal) Default destructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "(WrongAnimal) makesound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->_type;
}
