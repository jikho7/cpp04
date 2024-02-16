#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* l = new Cat();
	const WrongAnimal* k = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();

	std::cout << "\n";

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;

	std::cout << "\n";

	std::cout << "Animal makes sound : ";
	meta->makeSound();
	std::cout << "Dog makes sound : ";
	j->makeSound();
	std::cout << "Cat makes sound : ";
	l->makeSound();

	std::cout << "\n";

	std::cout << "Wrong animal makes sound : ";
	k->makeSound();
	std::cout << "Wrong cat makes sound : ";
	i->makeSound();

	return 0;
}
