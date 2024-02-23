#include "Dog.hpp"

Dog::Dog(): Animal("Dog"), _brain(0)
{
	this->_brain = new Brain();
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
	delete this->_brain;
	std::cout << "(Dog) Default destructor." << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->_type = other.getType();
		delete this->_brain;
		this->_brain = new Brain(*(other._brain));
	}
	return *this;
}

Brain* Dog::getBrain() const
{
	return(this->_brain);
}

void Dog::makeSound() const
{
	std::cout << "Waouf" << std::endl;
}
