#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat(): WrongAnimal("Cat")
{
	std::cout << "(WrongCat) Default constructor." << " Type: " << this->_type << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "(WrongCat) Default destructor." << std::endl;
}

// Cat::Cat(std::string type): Animal(type)
// {
// 	std::cout << "(Cat) Parametric constructor" << std::endl;
// }

WrongCat::WrongCat(const WrongCat &other) // copy
{
	this->_type = other._type;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
	(void)other;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong Miaou" << std::endl;
}
