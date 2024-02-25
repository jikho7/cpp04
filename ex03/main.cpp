#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	//src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	std::cout << "fuck0" << std::endl;
	AMateria* tmp;
	std::cout << "fuck1" << std::endl;
	tmp = src->createMateria("ice");
	std::cout << "fuck2" << std::endl;
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}
