#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
#include "AMateria.hpp"

class ICharacter
{
	public:
		ICharacter(std::string name);
		ICharacter(const ICharacter &other);
		ICharacter& operator=(const ICharacter &other);
		virtual ~ICharacter();

		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;

	private :
		AMateria *_inventoy[4];
	//n inventaire de 4 items, soit 4 Materias maximum
};

#endif
