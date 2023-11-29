#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap("", 100, 50, 20){
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->gateKeeping = 0;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {
	std::cout << "ScavTrap parameter constructor called" << std::endl;
	this->gateKeeping = 0;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &old) : ClapTrap(old) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &old)
{
	std::cout << "ScavTrap assignation operator called" << std::endl;
	this->name = old.name;
	this->hitPoints = old.hitPoints;
	this->hitPointsMax = old.hitPointsMax;
	this->energyPoints = old.energyPoints;
	this->attackDamage = old.attackDamage;
	this->gateKeeping = old.gateKeeping;
	return (*this);
}

void ScavTrap::guardGate(void)
{
	if (this->hitPoints <= 0)
	{
		std::cout << this->name << " is dead, it cant take actions" << std::endl;
		return ;
	}
	if (this->energyPoints <= 0)
	{
		std::cout << this->name << " has no energy left" << std::endl;
		return ;
	}
	this->gateKeeping = 1;
	std::cout << "ScavTrap " << this->name << " has entered in Gate keeper mode" << std::endl;
}