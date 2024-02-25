#include "Ice.hpp"
//#include "AMateria.hpp"

Ice::Ice() {std::cout << "(Ice) default constructor called" << std::endl;}
Ice::~Ice() {std::cout << "(Ice) default decontructor called" << std::endl;}
Ice::Ice(const Ice &other) {*this = other;}

Ice::Ice(std::string type) : AMateria(type)
{
	std::cout << "(Ice) parametric constructor called" << std::endl;
}

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
   std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
