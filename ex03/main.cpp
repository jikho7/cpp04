#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"

void printSeparator(std::string title)
{
	std::cout << "\n========== " << title << " ==========\n" << std::endl;
}

int main()
{
	printSeparator("TEST 1: Basic Subject Tests");
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	printSeparator("TEST 2: MateriaSource - Learn Max Capacity (4)");
	{
		IMateriaSource* src = new MateriaSource();
		std::cout << "Learning 4 materias..." << std::endl;
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		std::cout << "Trying to learn a 5th materia (should be ignored)..." << std::endl;
		AMateria* overflow = new Ice();
		src->learnMateria(overflow);
		delete overflow; // Must delete manually since it wasn't stored

		delete src;
	}

	printSeparator("TEST 3: MateriaSource - Create Unknown Type");
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());

		std::cout << "Creating known type 'ice'..." << std::endl;
		AMateria* ice = src->createMateria("ice");
		if (ice)
			std::cout << "✓ Created: " << ice->getType() << std::endl;

		std::cout << "\nCreating unknown type 'fire'..." << std::endl;
		AMateria* fire = src->createMateria("fire");
		if (!fire)
			std::cout << "✓ NULL returned for unknown type" << std::endl;

		delete ice;
		delete src;
	}

	printSeparator("TEST 4: Character - Equip/Unequip");
	{
		ICharacter* warrior = new Character("Warrior");
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		AMateria* materias[4]; // Save pointers before equipping
		std::cout << "Equipping 4 materias..." << std::endl;
		for (int i = 0; i < 4; i++)
		{
			materias[i] = src->createMateria(i % 2 == 0 ? "ice" : "cure");
			warrior->equip(materias[i]);
			std::cout << "Slot " << i << " equipped" << std::endl;
		}

		std::cout << "\nTrying to equip a 5th materia (should be ignored)..." << std::endl;
		AMateria* overflow = src->createMateria("ice");
		warrior->equip(overflow);
		delete overflow; // Must delete manually

		std::cout << "\nUnequipping slot 1..." << std::endl;
		AMateria* unequipped = materias[1]; // Save pointer before unequip
		warrior->unequip(1);

		std::cout << "Equipping new materia in freed slot..." << std::endl;
		warrior->equip(src->createMateria("cure"));

		std::cout << "Deleting unequipped materia..." << std::endl;
		delete unequipped; // Delete the unequipped one

		delete warrior;
		delete src;
	}

	printSeparator("TEST 5: Character - Use Materias");
	{
		ICharacter* healer = new Character("Healer");
		ICharacter* target = new Character("Target");
		IMateriaSource* src = new MateriaSource();

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		healer->equip(src->createMateria("ice"));
		healer->equip(src->createMateria("cure"));

		std::cout << "Using slot 0 (ice):" << std::endl;
		healer->use(0, *target);

		std::cout << "\nUsing slot 1 (cure):" << std::endl;
		healer->use(1, *target);

		std::cout << "\nUsing empty slot 2:" << std::endl;
		healer->use(2, *target);

		std::cout << "\nUsing invalid slot -1:" << std::endl;
		healer->use(-1, *target);

		std::cout << "\nUsing invalid slot 10:" << std::endl;
		healer->use(10, *target);

		delete healer;
		delete target;
		delete src;
	}

	printSeparator("TEST 6: Character - Deep Copy (Copy Constructor)");
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		Character* original = new Character("Original");
		AMateria* ice = src->createMateria("ice");
		AMateria* cure = src->createMateria("cure");
		original->equip(ice);
		original->equip(cure);

		std::cout << "Creating copy of character..." << std::endl;
		Character* copy = new Character(*original);

		std::cout << "\nOriginal character name: " << original->getName() << std::endl;
		std::cout << "Copy character name: " << copy->getName() << std::endl;

		ICharacter* dummy = new Character("Dummy");

		std::cout << "\nOriginal using materias:" << std::endl;
		original->use(0, *dummy);
		original->use(1, *dummy);

		std::cout << "\nCopy using materias:" << std::endl;
		copy->use(0, *dummy);
		copy->use(1, *dummy);

		std::cout << "\nUnequipping from original (should not affect copy):" << std::endl;
		original->unequip(0);

		std::cout << "Original using slot 0 (should do nothing):" << std::endl;
		original->use(0, *dummy);

		std::cout << "Copy using slot 0 (should still work):" << std::endl;
		copy->use(0, *dummy);

		std::cout << "\nDeleting unequipped materia..." << std::endl;
		delete ice; // Delete the unequipped one

		delete dummy;
		delete original;
		delete copy;
		delete src;
	}

	printSeparator("TEST 7: Character - Assignment Operator");
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		Character* char1 = new Character("Char1");
		Character* char2 = new Character("Char2");

		char1->equip(src->createMateria("ice"));
		char1->equip(src->createMateria("cure"));

		char2->equip(src->createMateria("cure"));

		std::cout << "Before assignment:" << std::endl;
		std::cout << "Char1: " << char1->getName() << std::endl;
		std::cout << "Char2: " << char2->getName() << std::endl;

		std::cout << "\nAssigning char1 to char2..." << std::endl;
		*char2 = *char1;

		std::cout << "\nAfter assignment:" << std::endl;
		std::cout << "Char2 name: " << char2->getName() << std::endl;

		ICharacter* dummy = new Character("Dummy");
		std::cout << "\nChar2 using materias (should have char1's materias):" << std::endl;
		char2->use(0, *dummy);
		char2->use(1, *dummy);

		delete dummy;
		delete char1;
		delete char2;
		delete src;
	}

	printSeparator("TEST 8: MateriaSource - Deep Copy");
	{
		MateriaSource* src1 = new MateriaSource();
		src1->learnMateria(new Ice());
		src1->learnMateria(new Cure());

		std::cout << "Creating copy of MateriaSource..." << std::endl;
		MateriaSource* src2 = new MateriaSource(*src1);

		std::cout << "\nCreating materia from original source:" << std::endl;
		AMateria* m1 = src1->createMateria("ice");
		if (m1)
			std::cout << "✓ Created: " << m1->getType() << std::endl;

		std::cout << "\nCreating materia from copied source:" << std::endl;
		AMateria* m2 = src2->createMateria("cure");
		if (m2)
			std::cout << "✓ Created: " << m2->getType() << std::endl;

		delete m1;
		delete m2;
		delete src1;
		delete src2;
	}

	printSeparator("TEST 9: Memory Leak - Unequipped Materias");
	{
		std::cout << "Note: Unequipped materias must be manually deleted!" << std::endl;

		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());

		ICharacter* character = new Character("Test");
		AMateria* materia = src->createMateria("ice");
		character->equip(materia);

		std::cout << "Unequipping materia..." << std::endl;
		character->unequip(0);

		std::cout << "Deleting unequipped materia manually..." << std::endl;
		delete materia; // IMPORTANT: Must delete manually

		delete character;
		delete src;
	}

	printSeparator("TEST 10: Edge Cases - NULL and Invalid Operations");
	{
		ICharacter* character = new Character("EdgeCase");

		std::cout << "Equipping NULL materia..." << std::endl;
		character->equip(NULL);

		std::cout << "Unequipping invalid negative index..." << std::endl;
		character->unequip(-5);

		std::cout << "Unequipping invalid high index..." << std::endl;
		character->unequip(42);

		std::cout << "Unequipping already empty slot..." << std::endl;
		character->unequip(0);

		delete character;
	}

	printSeparator("ALL TESTS COMPLETED");
	std::cout << "\n✓ If no crashes or leaks, implementation is correct!\n" << std::endl;
	std::cout << "Run with valgrind to check for memory leaks:" << std::endl;
	std::cout << "valgrind --leak-check=full ./materia\n" << std::endl;

	return 0;
}