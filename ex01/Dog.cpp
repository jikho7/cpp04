#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout << "(Dog) Default constructor." << std::endl;
}

// Dog::Dog(std::string type): Animal(type)
// {
// 	std::cout << "(Dog) Parametric constructor" << std::endl;
// }

Dog::Dog(const Dog &other) : Animal(other)
{
	*this = other;
}

Dog::~Dog()
{
	std::cout << "(Dog) Default destructor." << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->_type = other.getType();
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Waouf" << std::endl;
}
