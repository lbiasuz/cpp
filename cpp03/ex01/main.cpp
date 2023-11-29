#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
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

	std::cout << "SCAVTRAP" << std::endl;

	ScavTrap scav("Scav");
	std::cout << std::endl;
	
	ScavTrap scav2(scav);
	std::cout << std::endl;
	scav.takeDamage(5);
	scav.attack("Murader");
	scav.beRepaired(2);
	scav.takeDamage(10);
	scav.attack("Murader");
	scav.guardGate();

	std::cout << std::endl;
	scav = scav2;
	scav.guardGate();
	std::cout << std::endl;
}