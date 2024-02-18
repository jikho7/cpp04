#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
//valgrind --leak-check=full ./executable
int main()
{
	const Animal* meta = new Animal();
	const Animal* cat1 = new Cat();
	const Animal* b;
	const Animal* dog1 = new Dog();
	const WrongAnimal* wani = new WrongAnimal();
	const WrongAnimal* wcat = new WrongCat();

	std::cout << "\n";
	std::cout << "Get type : \n" << std::endl;

	std::cout << "animal : " << meta->getType() << " " << std::endl;
	std::cout << "cat : " << cat1->getType() << " " << std::endl;
	std::cout << "dog : " << dog1->getType() << " " << std::endl;
	std::cout << "wrong animal : " << wani->getType() << " " << std::endl;
	std::cout << "wrong cat : " << wcat->getType() << " " << std::endl;

	b = cat1;
	std::cout << "b = cat : " << b->getType() << " " << std::endl;

	std::cout << "\n";

	std::cout << "Animal makes sound : ";
	meta->makeSound();
	std::cout << "Cat makes sound : ";
	cat1->makeSound();
	std::cout << "Dog makes sound : ";
	dog1->makeSound();
	std::cout << "Wrong animal makes sound : ";
	wani->makeSound();
	std::cout << "Wrong cat makes sound : ";
	wcat->makeSound();
	std::cout << "b = cat Wrong cat makes sound : ";
	b->makeSound();

	delete cat1;
	delete meta;
	delete dog1;
	delete wani;
	delete wcat;

	cat1 = 0;
	meta = 0;
	dog1 = 0;
	wani = 0;
	wcat = 0;

	return 0;
}
