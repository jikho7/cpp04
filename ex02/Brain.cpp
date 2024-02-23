#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "(Brain) Default constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "(Brain) Default destructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
    *this = other;
}

Brain& Brain::operator=(const Brain &other)
{
	for (int i = 0; i < 100; ++i)
	{
		(this->_ideas)[i] = other.getIdeas(i);
	}
	return *this;
}

void Brain::setIdeas(std::string ideas, int i)
{
    if (i >= 0 and i <= 100)
        this->_ideas[i] = ideas;
}

std::string Brain::getIdeas(int i) const
{   if (i >= 0 and i <= 100)
        return this->_ideas[i];
    return(0);
}
