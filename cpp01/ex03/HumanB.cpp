#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB( std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB( void ) {}

void HumanB::setWeapon( Weapon& weapon )
{
	this->weapon = &weapon;
}

void HumanB::attack( void )
{
	if (this->weapon)
		std::cout	<< this->name << " attacks with their " \
					<< this->weapon->getType() << std::endl;
}