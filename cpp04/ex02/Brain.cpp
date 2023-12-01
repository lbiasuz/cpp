#include "Brain.hpp"
#include <iostream>

Brain::Brain( void )
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain & old)
{
	std::cout << "Brain copy contructor called" << std::endl;
	std::copy(old.ideas, old.ideas + 100, this->ideas);
}

Brain::~Brain( void )
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain & old)
{
	std::cout << "Brain copy assignment constructor called" << std::endl;
	std::copy(old.ideas, old.ideas + 100, this->ideas);
	return (*this);
}

void Brain::newIdea(std::string str)
{
	int i;
	for (i = 0; this->ideas[i] != ""; i++)
		;
	this->ideas[i] = str;
}

std::string Brain::getIdea(int i) const
{
	return (this->ideas[i]);
}