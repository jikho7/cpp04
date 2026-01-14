#include "Cure.hpp"
//#include "AMateria.hpp"

Cure::Cure() : AMateria()
{
 	this->_type = "cure";
	std::cout << "(Cure) default constructor called. Type : " << this->_type << std::endl;
}

Cure::~Cure() {std::cout << "(Cure) default decontructor called" << std::endl;}

Cure::Cure(const Cure &other) : AMateria() {*this = other;}

// Cure::Cure(std::string type) : AMateria(type)
// {
// 	std::cout << "(Cure) parametric constructor called" << std::endl;
// }

Cure& Cure::operator=(const Cure &other)
{
	(void)other;
	return *this;
}

Cure* Cure::clone() const
{
	return new Cure(*this);
	//return (*this);
}

void Cure::use(ICharacter& target)
{
   std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
