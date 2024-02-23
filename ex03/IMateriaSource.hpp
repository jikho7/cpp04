#ifndef IMATERIA_H
#define IMATERIA_H

#include <string>
#include <iostream>
#include "AMateria.hpp"

// En bref, votre MateriaSource doit pouvoir apprendre des "modèles" de Materias
// afin de les recréer à volonté. Ainsi, vous serez capable de générer une nouvelle Materia à
// partir de son type sous forme de chaîne de caractères.

class IMateriaSource
{
	public:
		IMateriaSource();
		virtual ~IMateriaSource();
		IMateriaSource(const IMateriaSource &other);
		IMateriaSource& operator=(const IMateriaSource &other);

		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
