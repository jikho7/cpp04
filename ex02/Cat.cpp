#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() : Animal("Cat"), _brain(0)
{
	this->_brain = new Brain();
	std::cout << "(Cat) Default constructor." << std::endl;
}

// Cat::Cat(std::string name, std::string type) : Animal(type), _brain(0)
// {
// 	this->_brain = new Brain();
// 	std::cout << "(Cat) Parametric constructor." << std::endl;
// }

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "(Cat) Default destructor." << std::endl;
}

// Cat::Cat(std::string type): Animal(type)
// {
// 	std::cout << "(Cat) Parametric constructor" << std::endl;
// }

Cat::Cat(const Cat &other) : Animal(other), _brain(0)
{
	this->_brain = new Brain(*(other._brain));
	*this = other;
	std::cout << "Cat copy constructor called." << std::endl;
}

// Cat::Cat(Cat const &src)
// {
// 	this->_brain = new Brain;
// 	*this = src;
// 	std::cout << "Cat copy constructor called." << std::endl;
// }

Cat& Cat::operator=(const Cat &other)
{
	if(this != &other)
	{
		this->_type = other.getType();
		delete this->_brain;
        this->_brain = new Brain(*(other._brain));
	}
	return *this;
}

Brain* Cat::getBrain() const
{
	return(this->_brain);
}

void Cat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}
