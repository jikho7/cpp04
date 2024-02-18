#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "(Cat) Default constructor." << std::endl;
}

Cat::~Cat()
{
	std::cout << "(Cat) Default destructor." << std::endl;
}

// Cat::Cat(std::string type): Animal(type)
// {
// 	std::cout << "(Cat) Parametric constructor" << std::endl;
// }

Cat::Cat(const Cat &other) : Animal(other)
{
	*this = other;
}

Cat& Cat::operator=(const Cat &other)
{
	if(this != &other)
	{
		this->_type = other.getType();
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}
