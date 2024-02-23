#include "ICharacter.hpp"

ICharacter::ICharacter() {}

ICharacter::ICharacter(std::string name)
{

}

ICharacter::ICharacter(const ICharacter &other)
{
	*this = other;
	// faire copie profonde Materias du Character doivent être delete avant que les nouvelles ne les remplacent dans l’inventaire.
	// Bien évidemment, les Materias doivent aussi être supprimées à la destruction d’un Character.
}

ICharactera& ICharacter::operator=(const ICharacter &other)
{
	return *this;
	// faire copie profonde Materias du Character doivent être delete avant que les nouvelles ne les remplacent dans l’inventaire.
	// Bien évidemment, les Materias doivent aussi être supprimées à la destruction d’un Character.
}


ICharacter::~ICharacter() {}

//virtual std::string const & getName() const = 0;

//virtual void equip(AMateria* m) = 0;

//virtual void unequip(int idx) = 0;

//virtual void use(int idx, ICharacter& target) = 0;
// La fonction membre use(int, ICharacter&) utilisera la Materia de l’emplacement[idx],
// et passera la cible en paramètre à la fonction AMateria::use
