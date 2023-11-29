#include "ClapTrap.hpp"
#include <iostream>

int main( void ) {

	ClapTrap clap2("Trap2");
	std::cout << std::endl;
	ClapTrap clap;
	std::cout << std::endl;
	clap = ClapTrap("Trap");
	std::cout << std::endl;
	clap.takeDamage(5);
	clap.attack("Murader");
	clap.beRepaired(2);
	clap.takeDamage(10);
	clap.attack("Murader");
	std::cout << std::endl;
	clap = clap2;
	clap.attack("Murader");
	clap.takeDamage(10);
	clap.beRepaired(2);
	std::cout << std::endl;
}