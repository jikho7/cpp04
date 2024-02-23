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
    void setIdeas(std::string ideas, int i);
    std::string getIdeas(int i) const;

    protected :
    std::string _ideas[100];
};

#endif
