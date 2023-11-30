#include "Animal.hpp"
#include <iostream>

Animal::Animal( void ) {
	std::cout << "Animal constructor called" << std::endl;
	this->type = "Amalgam";
}

Animal::Animal (const Animal & old) {
	this->type = old.type;
}

Animal & Animal::operator= (const Animal & old) {
	this->type = old.type;
	return (*this);
}

Animal::~Animal( void ) {
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType( void )
{
	return (this->type);
}

void Animal::makeSound( void ) {
	std::cout << "!@#$#@$!@&-&-:#@" << std::endl;
}