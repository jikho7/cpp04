#ifndef CAT_H
#define CAT_H

#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		//Cat(std::string type);
		Cat(const Cat &other);
		virtual ~Cat();
		
		Cat& operator=(const Cat &other);

		virtual void makeSound() const;

	private:

};

#endif
