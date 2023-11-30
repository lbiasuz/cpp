#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
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

	std::cout << "FRAGTRAP" << std::endl;
	FragTrap frag("Frag");
	std::cout << std::endl;

	FragTrap frag2(frag);
	std::cout << std::endl;

	frag.takeDamage(5);
	frag.attack("Murader");
	frag.beRepaired(2);
	frag.takeDamage(10);
	frag.attack("Murader");
	frag.highFivesGuys();
	std::cout << std::endl;

	frag2 = frag;
	frag2.highFivesGuys();
	std::cout << std::endl;

	std::cout << "DIAMONDTRAP" << std::endl;
	DiamondTrap diamond("Diamond");
	std::cout << std::endl;

	diamond.takeDamage(5);
	diamond.attack("Murader");
	diamond.beRepaired(2);
	diamond.takeDamage(10);
	diamond.attack("Murader");
	diamond.highFivesGuys();
	diamond.guardGate();
	diamond.whoAmI();
	std::cout << std::endl;
}