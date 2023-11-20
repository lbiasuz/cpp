#include "Weapon.hpp"

Weapon::Weapon( void ) {
	this->type = "";
}
Weapon::~Weapon( void ) { }

Weapon::Weapon( std::string type )
{
	this->type = type;
}

std::string Weapon::getType( void ) {
	return (this->type);
}

void	Weapon::setType( std::string type ) {
	this->type = type;
}