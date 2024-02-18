#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	std::cout << "(WrongCat) Default constructor." << std::endl;
}

// Cat::Cat(std::string type): Animal(type)
// {
// 	std::cout << "(Cat) Parametric constructor" << std::endl;
// }

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	*this = other;
}

WrongCat::~WrongCat()
{
	std::cout << "(WrongCat) Default destructor." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "(Wrong cat) Miaou" << std::endl;
}
