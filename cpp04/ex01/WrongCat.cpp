#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat( void ) : WrongAnimal()
{
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat & old) : WrongAnimal()
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->type = old.type;
}

WrongCat & WrongCat::operator=(const WrongCat & old)
{
	std::cout << "WrongCat copy asign constructor called" << std::endl;
	this->type = old.type;
	return (*this);
}

WrongCat::~WrongCat ( void )
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound( void )
{
	std::cout << "Meow!" << std::endl;
}