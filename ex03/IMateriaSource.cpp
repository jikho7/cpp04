#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource() {}

IMateriaSource::~IMateriaSource() {}

IMateriaSource::IMateriaSource(const IMateriaSource &other)
{
	*this = other;
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource &other)
{
	return *this;
}

//virtual void learnMateria(AMateria*) = 0;
// {
// 	Copie la Materia passée en paramètre et la stocke en mémoire afin de la cloner
// 	plus tard. Tout comme le Character, la MateriaSource peut contenir 4 Materias
// 	maximum. Ces dernières ne sont pas forcément uniques.
// }

// //virtual AMateria* createMateria(std::string const & type) = 0;
// {
// 	Retourne une nouvelle Materia. Celle-ci est une copie de celle apprise précédemment
// 	par la MateriaSource et dont le type est le même que celui passé en paramètre.
// 	Retourne 0 si le type est inconnu.
// }
