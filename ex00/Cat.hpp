#ifndef CAT_H
#define CAT_H

#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		//Cat(std::string type);
		Cat(const Cat &other);
		Cat& operator=(const Cat &other);

		virtual void makeSound() const;

	private:

};

#endif
