#include "Cat.hpp"
#include <iostream>

Cat::Cat( void ) : Animal()
{
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat & old) : Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = old.type;
	this->brain = new Brain(*old.brain);
}

Cat & Cat::operator=(const Cat & old)
{
	std::cout << "Cat copy asign constructor called" << std::endl;
	this->type = old.type;
	this->brain = new Brain(*old.brain);
	return (*this);
}

Cat::~Cat ( void )
{
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

Brain& Cat::getBrain( void )
{
	return (*this->brain);
}

void Cat::makeSound( void )
{
	std::cout << "Meow!" << std::endl;
}