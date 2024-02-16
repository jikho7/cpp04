#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout << "(Dog) Default constructor." << " Type: " << this->_type << std::endl;
}

Dog::~Dog()
{
	std::cout << "(Dog) Default destructor." << std::endl;
}

// Dog::Dog(std::string type): Animal(type)
// {
// 	std::cout << "(Dog) Parametric constructor" << std::endl;
// }

Dog::Dog(const Dog &other) // copy
{
	this->_type = other._type;
}

Dog& Dog::operator=(const Dog &other)
{
	(void)other;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Waouf" << std::endl;
}
