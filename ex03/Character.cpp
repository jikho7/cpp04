#include "Character.hpp"

Character::Character()
{
	this->_name = "Name";
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << "(Character) default constructor called" << std::endl;
}

Character::Character(std::string name) :
_name(name)
{
	for(int i(0); i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << "(Character) parametric constructor called" << std::endl;
}

Character::Character(const Character &other)
{
	for (int i = 0; i < 4; i++)
	{
		if (!(other._inventory)[i])
			(this->_inventory)[i] = NULL; // vraiment necessaire ?
		else
		{
			(this->_inventory)[i] = (other._inventory)[i]->clone();
		}
	}
	this->_name = other._name;
	// Pas de copie profonde car inventaire vide
}

Character& Character::operator=(const Character &other)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
		if (!(other._inventory)[i])
			(this->_inventory)[i] = NULL;
		else
		{
			(this->_inventory)[i] = (other._inventory)[i]->clone();
		}
	}
/*
	Chaque perso a son inventaire (constuctor), virer juste les adresses des Objets AMateria (Ice/Cure)
*/
	// faire copie profonde Materias du Character doivent être delete avant que les nouvelles ne les remplacent dans l’inventaire.
	// Bien évidemment, les Materias doivent aussi être supprimées à la destruction d’un Character.
	return (*this);
}

Character::~Character()
{
	for(int i(0); i < 4; i++)
	{
		if ((this->_inventory)[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
	std::cout << "(Character) default destructor called" << std::endl;
}


std::string const & Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!(this->_inventory)[i])
		{
			// std::cout << "* Equipping " << m->getType() << " into slot " << i << " *" <<std::endl;
			(this->_inventory)[i] = m;
			break ;
		}
	}
	// int i(0);

	// while (this->_inventory[i])
	// 	i++;
	// this->_inventory[i] = m;
	// std::cout << "equip" << std::endl;
	// //this->_inventory[i] = new AMateria();
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && (this->_inventory)[idx])
	{
		(this->_inventory)[idx] = NULL;
		std::cout << "unequip" << std::endl;
	}
	//delete this->_inventory[idx];
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && (this->_inventory)[idx])
	{
		(this->_inventory)[idx]->use(target);
		std::cout << "using item : " << this->_inventory[idx] << "on " << target.getName() << std::endl;
	}
}
