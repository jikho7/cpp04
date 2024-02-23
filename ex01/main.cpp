#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

//valgrind --leak-check=full ./executable

int main()
{
	Cat chat1;
	Cat chat2;
	Cat chat3;

	std::cout << "\n";

	std::cout << "type chat1 : " << chat1.getType() << std::endl;
	std::cout << "type chat2 : " << chat2.getType() << std::endl;
	std::cout << "adresse brain chat1 : " << chat1.getBrain() << std::endl;
	std::cout << "adresse brain chat2 : " << chat2.getBrain() << std::endl;

	chat1.getBrain()->setIdeas("chat1 hapi", 0);
	chat1.getBrain()->setIdeas("chat1 g fin", 1);
	chat1.getBrain()->setIdeas("chat1 g soaf", 2);
	chat1.getBrain()->setIdeas("chat1 g someil", 3);

	std::cout << "\n";

	chat2.getBrain()->setIdeas("chat2 hapi", 0);
	chat2.getBrain()->setIdeas("chat2 g fin", 1);
	chat2.getBrain()->setIdeas("chat2 g soaf", 2);
	chat2.getBrain()->setIdeas("chat2 g someil", 3);

	std::cout << "\n";

	std::cout << "chat1 " << chat1.getBrain()->getIdeas(0) << std::endl;
	std::cout << "chat1 " << chat1.getBrain()->getIdeas(1) << std::endl;
	std::cout << "chat1 " << chat1.getBrain()->getIdeas(2) << std::endl;
	std::cout << "chat1 " << chat1.getBrain()->getIdeas(3) << std::endl;
	//std::cout << "type : " << Plol.getType() << std::endl;

	std::cout << "\n";
	std::cout << "copie chat1 dans chat2" << std::endl;

	chat2 = chat1;

	std::cout << "chat2 " << chat2.getBrain()->getIdeas(0) << std::endl;
	std::cout << "chat2 " << chat2.getBrain()->getIdeas(1) << std::endl;
	std::cout << "chat2 " << chat2.getBrain()->getIdeas(2) << std::endl;
	std::cout << "chat2 " << chat2.getBrain()->getIdeas(3) << std::endl;

	std::cout << "\n";
	std::cout << "copie chat1 dans chat3" << std::endl;

	chat3 = chat1;

	std::cout << "chat3 " << chat3.getBrain()->getIdeas(0) << std::endl;
	std::cout << "chat3 " << chat3.getBrain()->getIdeas(1) << std::endl;
	std::cout << "chat3 " << chat3.getBrain()->getIdeas(2) << std::endl;
	std::cout << "chat3 " << chat3.getBrain()->getIdeas(3) << std::endl;

	std::cout << "\n";

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

	std::cout << "\n";

	for(int i(0); i < 4; i++)
	{
		std::cout << "makesound : ";
		liste[i]->makeSound();
	}

	std::cout << "\n";

	for(int i(0); i < 4; i++)
	{
		delete (liste[i]);
		liste[i] = 0;
	}

	return(0);
}
