#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) {
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->name = "";
	this->hitPoints = 10;
	this->hitPointsMax = hitPoints;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << "ClapTrap parameter constructor called" << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->hitPointsMax = hitPoints;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name, int life, int stamina, int damage)
	: name(name), hitPoints(life), hitPointsMax(life), energyPoints(stamina), attackDamage(damage)
{
	std::cout << "ClapTrap multiple parameter constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &old) 
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	this->name = old.name;
	this->hitPoints = old.hitPoints;
	this->hitPointsMax = old.hitPointsMax;
	this->energyPoints = old.energyPoints;
	this->attackDamage = old.attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &old)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	this->name = old.name;
	this->hitPoints = old.hitPoints;
	this->hitPointsMax = old.hitPointsMax;
	this->energyPoints = old.energyPoints;
	this->attackDamage = old.attackDamage;
	return (*this);
}

void	ClapTrap::attack(std::string const & target)
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
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints - (int) amount < 0)
		this->hitPoints = 0;
	else
		this->hitPoints -= amount;
	std::cout << this->name << " takes " << amount << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
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
	std::cout << this->name << " is repaired by " << amount << " points of life!" << std::endl;
	if (this->hitPoints + (int) amount > this->hitPointsMax)
		this->hitPoints = this->hitPointsMax;
	else
		this->hitPoints += amount;
	this->energyPoints--;
}