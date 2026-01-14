#ifndef CURE_H
#define CURE_H

#include <string>
#include <iostream>
#include "AMateria.hpp"
//# include "ICharacter.hpp"

class	ICharacter;

class Cure : public AMateria
{
	public:
		Cure();
		//Cure(std::string type);
		virtual ~Cure();
		Cure(const Cure &other);
		Cure& operator=(const Cure &other);

		virtual Cure* clone() const;
		virtual void use(ICharacter& target);

	private:

};

// virer virtual pour le deconstructor ?
#endif
