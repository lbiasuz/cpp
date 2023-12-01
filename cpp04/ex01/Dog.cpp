#include "Dog.hpp"
#include <iostream>

Dog::Dog( void ) : Animal()
{
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog & old) : Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = old.type;
	this->brain = new Brain(*old.brain);
}

Dog & Dog::operator=(const Dog & old)
{
	std::cout << "Dog copy asign constructor called" << std::endl;
	this->type = old.type;
	this->brain = new Brain(*old.brain);
	return (*this);
}

Dog::~Dog ( void )
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

Brain& Dog::getBrain( void )
{
	return (*this->brain);
}

void Dog::makeSound( void )
{
	std::cout << "WoOf WOof!" << std::endl;
}