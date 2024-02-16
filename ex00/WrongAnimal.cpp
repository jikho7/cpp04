#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "(WrongAnimal) Default constructor" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "(WrongAnimal) Default destructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "(WrongAnimal) Parametric constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) // copy
{
	this->_type = other._type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
	(void)other;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal ft_makesound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->_type;
}
