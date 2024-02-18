#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		//Dog(std::string type);
		Dog(const Dog &other);
		virtual ~Dog();
		
		Dog& operator=(const Dog &other);

		virtual void makeSound() const;

	private:
		Brain *brain;

};

#endif
