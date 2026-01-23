#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		(this->_templates)[i] = NULL;
	return ;
} //sim

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if ((this->_templates)[i])
			delete (this->_templates)[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource &other) : IMateriaSource() //sim
{
	for (int i = 0; i < 4; i++)
	{
		if (!(other._templates)[i])
			(this->_templates)[i] = NULL;
		else
			(this->_templates)[i] = (other._templates)[i]->clone();
	}
	//*this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
	for (int i = 0; i < 4; i++)
	{
		if ((this->_templates)[i])
			delete ((this->_templates)[i]);
		if (!(other._templates)[i])
			(this->_templates)[i] = NULL;
		else
			(this->_templates)[i] = (other._templates)[i]->clone();
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!(this->_templates)[i])
		{
			// std::cout << "* learning new ability " << m->getType() << " *" << std::endl;
			(this->_templates)[i] = m;
			break ;
		}
	}
	// Ne PAS delete m ici - il est stocké dans _templates et sera delete dans le destructeur
	return ;
	// Copie la Materia passée en paramètre et la stocke en mémoire afin de la cloner
	// plus tard. Tout comme le Character, la MateriaSource peut contenir 4 Materias
	// maximum. Ces dernières ne sont pas forcément uniques.
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{

	for (int i = 0; i < 4; i++)
	{
		if ((this->_templates)[i])
		{
			if ((this->_templates)[i]->getType() == type)
			{
				return ((this->_templates)[i]->clone());
			}
		}
	}
	return (0);
	// Retourne une nouvelle Materia. Celle-ci est une copie de celle apprise précédemment
	// par la MateriaSource et dont le type est le même que celui passé en paramètre.
	// Retourne 0 si le type est inconnu.
}
