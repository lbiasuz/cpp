#include "Dog.hpp"
#include <iostream>

Dog::Dog( void ) : Animal()
{
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog & old) : Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = old.type;
}

Dog & Dog::operator=(const Dog & old)
{
	std::cout << "Dog copy asign constructor called" << std::endl;
	this->type = old.type;
	return (*this);
}

Dog::~Dog ( void )
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound( void ) const
{
	std::cout << "WoOf WOof!" << std::endl;
}