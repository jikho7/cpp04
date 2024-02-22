#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

//valgrind --leak-check=full ./executable

int main()
{
	Cat chat1;
	Cat chat2;
	Cat chat3;

	std::cout << "type c1 : " << chat1.getType() << std::endl;
	std::cout << "type c2 : " << chat2.getType() << std::endl;
	chat1.getBrain()->setIdeas("c1 hapi", 0);
	chat1.getBrain()->setIdeas("c1 g fin", 1);
	chat1.getBrain()->setIdeas("c1 g soaf", 2);
	chat1.getBrain()->setIdeas("c1 g someil", 3);

	std::cout << "\n";

	chat2.getBrain()->setIdeas("c2 hapi", 0);
	chat2.getBrain()->setIdeas("c2 g fin", 1);
	chat2.getBrain()->setIdeas("c2 g soaf", 2);
	chat2.getBrain()->setIdeas("c2 g someil", 3);

	std::cout << "\n";

	std::cout << "c1 " << chat1.getBrain()->getIdeas(0) << std::endl;
	std::cout << "c1 " << chat1.getBrain()->getIdeas(1) << std::endl;
	std::cout << "c1 " << chat1.getBrain()->getIdeas(2) << std::endl;
	std::cout << "c1 " << chat1.getBrain()->getIdeas(3) << std::endl;
	//std::cout << "type : " << Plol.getType() << std::endl;

	std::cout << "\n";
	std::cout << "copie c1 dans c2" << std::endl;

	chat2 = chat1;

	std::cout << "c2 " << chat2.getBrain()->getIdeas(0) << std::endl;
	std::cout << "c2 " << chat2.getBrain()->getIdeas(1) << std::endl;
	std::cout << "c2 " << chat2.getBrain()->getIdeas(2) << std::endl;
	std::cout << "c2 " << chat2.getBrain()->getIdeas(3) << std::endl;

	std::cout << "\n";
	std::cout << "copie c1 dans c3" << std::endl;

	chat3 = chat1;

	std::cout << "c3 " << chat3.getBrain()->getIdeas(0) << std::endl;
	std::cout << "c3 " << chat3.getBrain()->getIdeas(1) << std::endl;
	std::cout << "c3 " << chat3.getBrain()->getIdeas(2) << std::endl;
	std::cout << "c3 " << chat3.getBrain()->getIdeas(3) << std::endl;

	std::cout << "adresse brain chat1 : " << chat1.getBrain() << std::endl;
	std::cout << "adresse brain chat2 : " << chat2.getBrain() << std::endl;
	std::cout << "adresse brain chat3 : " << chat3.getBrain() << std::endl;
	std::cout << "\n";

	Animal *liste[4];
	for(int i(0); i < 4; i++)
	{
		if (i % 2)
			liste[i] = new Cat();
		else
			liste[i] = new Dog();
	}

	for(int i(0); i < 4; i++)
	{
		liste[i]->makeSound();
	}

	for(int i(0); i < 4; i++)
	{
		delete (liste[i]);
	}

	return(0);
}
