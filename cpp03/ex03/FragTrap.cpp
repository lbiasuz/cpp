#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap("", 100, 100, 30){
	std::cout << "FragTrap default constructor called" << std::endl;
	this->hitPoints = 100;
	this->hitPointsMax = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	std::cout << "FragTrap parameter constructor called" << std::endl;
	this->hitPoints = 100;
	this->hitPointsMax = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &old) : ClapTrap(old) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &old)
{
	std::cout << "FragTrap assignation operator called" << std::endl;
	this->hitPoints = old.hitPoints;
	this->hitPointsMax = old.hitPointsMax;
	this->energyPoints = old.energyPoints;
	this->attackDamage = old.attackDamage;
	return (*this);
}

void FragTrap::attack(std::string const & target)
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
	std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
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
	std::cout << "FragTrap " << this->name << " wants to high five you for the win!" << std::endl;
}