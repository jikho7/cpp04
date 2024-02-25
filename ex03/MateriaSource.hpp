#ifndef MATERIA_H
#define MATERIA_H

#include <string>
#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
// En bref, votre MateriaSource doit pouvoir apprendre des "modèles" de Materias
// afin de les recréer à volonté. Ainsi, vous serez capable de générer une nouvelle Materia à
// partir de son type sous forme de chaîne de caractères.

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		virtual ~MateriaSource();
		MateriaSource(const MateriaSource &other);
		MateriaSource& operator=(const MateriaSource &other);

		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);

	private:
		AMateria	*_templates[4]; //sim
};

#endif
