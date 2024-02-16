#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << "(Cat) Default constructor." << " Type: " << this->_type << std::endl;
}

Cat::~Cat()
{
	std::cout << "(Cat) Default destructor." << std::endl;
}

// Cat::Cat(std::string type): Animal(type)
// {
// 	std::cout << "(Cat) Parametric constructor" << std::endl;
// }

Cat::Cat(const Cat &other) // copy
{
	this->_type = other._type;
}

Cat& Cat::operator=(const Cat &other)
{
	(void)other;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}
