#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal( void ) {
	std::cout << "WrongAnimal constructor called" << std::endl;
	this->type = "Amalgam";
}

WrongAnimal::WrongAnimal (const WrongAnimal & old) {
	this->type = old.type;
}

WrongAnimal & WrongAnimal::operator= (const WrongAnimal & old) {
	this->type = old.type;
	return (*this);
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType( void )
{
	return (this->type);
}

void WrongAnimal::makeSound( void ) {
	std::cout << "!@#$#@$!@&-&-:#@" << std::endl;
}