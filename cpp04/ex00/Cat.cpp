#include "Cat.hpp"
#include <iostream>

Cat::Cat( void ) : Animal()
{
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat & old) : Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = old.type;
}

Cat & Cat::operator=(const Cat & old)
{
	std::cout << "Cat copy asign constructor called" << std::endl;
	this->type = old.type;
	return (*this);
}

Cat::~Cat ( void )
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound( void ) const
{
	std::cout << "Meow!" << std::endl;
}