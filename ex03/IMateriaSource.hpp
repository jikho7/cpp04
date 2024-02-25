#ifndef IMATERIA_H
#define IMATERIA_H
// une interface est un ensemble de méthodes déclarées dans une classe, mais non implémentées
#include <string>
#include <iostream>
#include "AMateria.hpp"

// En bref, votre MateriaSource doit pouvoir apprendre des "modèles" de Materias
// afin de les recréer à volonté. Ainsi, vous serez capable de générer une nouvelle Materia à
// partir de son type sous forme de chaîne de caractères.

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
