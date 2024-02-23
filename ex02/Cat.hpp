#ifndef CAT_H
#define CAT_H

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		//Cat(std::string name, std::string type);
		Cat(const Cat &other);
		virtual ~Cat();

		Cat& operator=(const Cat &other);
		Brain* getBrain() const;
		virtual void makeSound() const;

	private:
	Brain *_brain;

};

#endif
