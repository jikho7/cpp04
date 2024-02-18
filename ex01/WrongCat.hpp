#ifndef WCAT_H
#define WCAT_H

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();
		//Cat(std::string type);
		WrongCat(const WrongCat &other);
		WrongCat& operator=(const WrongCat &other);

		void makeSound() const;

	private:

};

#endif
