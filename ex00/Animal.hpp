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
		virtual void makeSound() const;

	protected:
		std::string _type;

};

#endif
