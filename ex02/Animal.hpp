#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal
{
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &other);
		virtual ~Animal();
		Animal& operator=(const Animal &other);

		std::string getType() const;
		virtual void makeSound() const = 0; // methode virtuelle pure, classe devient abstraite

	protected:
		std::string _type;

};

#endif
