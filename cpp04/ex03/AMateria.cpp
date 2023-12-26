#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(void) : type("") {}
AMateria::AMateria(std::string const & type) : type(type) {}
AMateria::AMateria(const AMateria & old) : type(old.getType()) {}
AMateria::~AMateria() {}
AMateria & AMateria::operator=(const AMateria & old) {
	this->type = old.getType();
	return (*this);
}

std::string const & AMateria::getType( void ) const {
	return (this->type);
}

void AMateria::use(ICharacter & target) {
	std::cout << target.getName() << "is referenced by it;" << std::endl;
}