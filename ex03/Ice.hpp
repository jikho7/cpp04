#ifndef ICE_H
#define ICE_H

#include <string>
#include <iostream>
#include "AMateria.hpp"
//# include "ICharacter.hpp"

class	ICharacter;

class Ice : public AMateria
{
	public:
		Ice();
		Ice(std::string type);
		virtual ~Ice();
		Ice(const Ice &other);
		Ice& operator=(const Ice &other);

		virtual Ice* clone() const;
		virtual void use(ICharacter& target);

	private:
	//	std::string _type;
};

#endif
