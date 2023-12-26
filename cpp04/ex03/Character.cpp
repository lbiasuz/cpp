#include "Character.hpp"
#include "ICharacter.hpp"
#include <string>

Character::Character(void) : name("") {
	this->inventory[0] = NULL;
	this->inventory[1] = NULL;
	this->inventory[2] = NULL;
	this->inventory[3] = NULL;
}

Character::Character(const std::string &name) : name(name) {
	this->inventory[0] = NULL;
	this->inventory[1] = NULL;
	this->inventory[2] = NULL;
	this->inventory[3] = NULL;
}

Character::Character(const Character &old)
	: name(old.getName())
{
	if (old.inventory[0] != NULL)
		this->inventory[0] = old.inventory[0]->clone();
	if (old.inventory[1] != NULL)
		this->inventory[1] = old.inventory[1]->clone();
	if (old.inventory[2] != NULL)
		this->inventory[2] = old.inventory[2]->clone();
	if (old.inventory[3] != NULL)
		this->inventory[3] = old.inventory[3]->clone();
}

Character &Character::operator=(const Character &old)
{
	this->name = old.getName();
	this->inventory[0] = old.inventory[0]->clone();
	this->inventory[1] = old.inventory[1]->clone();
	this->inventory[2] = old.inventory[2]->clone();
	this->inventory[3] = old.inventory[3]->clone();
	return (* this);
}

Character::~Character(void) {
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
	}
}

const std::string &Character::getName(void) const
{
	return (this->name);
}

void Character::equip(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = materia;
			return;
		}
	}
}

void Character::unequip(int i)
{
	if (i < 0 || i >= 4)
		return;
	this->inventory[i] = NULL;
}

void Character::use(int i, ICharacter &target)
{
	if (i < 0 || i >= 4)
		return;
	this->inventory[i]->use(target);
}