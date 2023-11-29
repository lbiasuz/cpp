#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void): ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap("Not Diamond"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap name constructor called" << std::endl;
	this->name = name;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(DiamondTrap const & old): ClapTrap(old), ScavTrap(old), FragTrap(old)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = old;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & old)
{
	std::cout << "DiamondTrap assignation operator called" << std::endl;
	this->name = old.name;
	this->hitPoints = old.hitPoints;
	this->energyPoints = old.energyPoints;
	this->attackDamage = old.attackDamage;
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << this->name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}