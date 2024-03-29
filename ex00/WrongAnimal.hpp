#ifndef WANIMAL_H
#define WANIMAL_H

#include <iostream>
#include <string>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &other);
		virtual ~WrongAnimal();

		WrongAnimal& operator=(const WrongAnimal &other);

		std::string getType() const;
		void makeSound() const;

	protected:
		std::string _type;

};

#endif
