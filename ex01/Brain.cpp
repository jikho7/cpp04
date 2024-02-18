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
    (void)other;
    // if (this != &other)
    //     this->_type = other._type
    return *this;
}