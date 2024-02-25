#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string name);
		Character(const Character &other);
		Character& operator=(const Character &other);
		virtual ~Character();

		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

	private :
		std::string _name;
		AMateria *_inventory[4];
	//n inventaire de 4 items, soit 4 Materias maximum
};

#endif
