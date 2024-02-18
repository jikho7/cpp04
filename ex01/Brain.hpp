#ifndef BRAIN_H
#define BRAIN_H

#include <string>
#include <iostream>

class Brain
{
    public :
    Brain();
    Brain(const Brain &other);
    ~Brain();

    Brain& operator=(const Brain &other);

    protected :
    std::string ideas[100];
};

#endif