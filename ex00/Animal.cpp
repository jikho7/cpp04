#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "(Animal) Default constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "(Animal) Default destructor" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "(Animal) Parametric constructor" << std::endl;
}

Animal::Animal(const Animal &other) // copy
{
	this->_type = other._type;
}

Animal& Animal::operator=(const Animal &other)
{
	(void)other;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "Animal ft_makesound" << std::endl;
}

std::string Animal::getType() const
{
	return this->_type;
}
