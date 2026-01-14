#include "Ice.hpp"
//#include "AMateria.hpp"

// Ice::Ice() {std::cout << "(Ice) default constructor called" << std::endl;}
Ice::~Ice() {std::cout << "(Ice) default decontructor called" << std::endl;}
Ice::Ice() : AMateria()
{
	this->_type = "ice";
	std::cout << "(Ice) parametric constructor called. Type : " << this->_type << std::endl;
}

Ice::Ice(const Ice &other) : AMateria() {*this = other;}


Ice& Ice::operator=(const Ice &other)
{
	(void)other;
	return *this;
}

Ice* Ice::clone() const
{
	return new Ice(*this);
	//return (*this);
}

void Ice::use(ICharacter& target)
{
   std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
