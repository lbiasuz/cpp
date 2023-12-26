#include "Ice.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(const Ice & old) : AMateria(old) {}

Ice::~Ice(void) {}

Ice& Ice::operator= (const Ice & old) {
	this->type = old.getType();
	return (*this);
}

AMateria* Ice::clone( void ) const {
	return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at "
				<< target.getName() << " *" << std::endl;
}