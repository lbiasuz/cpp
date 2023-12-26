#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(const Cure & old) : AMateria(old) {}

Cure::~Cure( void ) {}

Cure & Cure::operator=(const Cure & old) {
	this->type = old.getType();
	return (*this);
}

AMateria * Cure::clone ( void ) const {
	return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
		std::cout << "* heals "
			<< target.getName() << "'s wounds *"
			<< std::endl;
}