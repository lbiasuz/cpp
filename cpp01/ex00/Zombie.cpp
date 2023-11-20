#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( void ) {
	this->name = "Anon";
	std::cout << this->name << " raised from the grave" << std::endl;
}

Zombie::Zombie( std::string name ) {
	this->name = name;
	std::cout << this->name << " raised from the grave" << std::endl;
}

Zombie::~Zombie( void ) {
	std::cout << this->name << " rotted to death?" << std::endl;
}

void	Zombie::announce( void ) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
