#include "AMateria.hpp"

AMateria::AMateria(){}

AMateria::AMateria(std::string const & type)// : _type(type)
{
	this->_type = type;
	std::cout << "(AMateria) parametric constructor called" << std::endl;
}

AMateria::~AMateria(){}

AMateria::AMateria(const AMateria &other)
{
	this->_type = other._type;
	//*this = other;
}

AMateria& AMateria::operator=(const AMateria &other)
{
	this->_type = other._type;
	return (*this);
}

std::string const & AMateria::getType() const //Returns the materia type
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "(AMateria use) * shoots an ice bolt at *" << target.getName() << std::endl;
	//Ice : "* shoots an ice bolt at <name> *"
	//std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	//• Cure : "* heals <name>’s wounds *"
}

