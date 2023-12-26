#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	this->inventory[0] = NULL;
	this->inventory[1] = NULL;
	this->inventory[2] = NULL;
	this->inventory[3] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource & old) {
	this->inventory[0] = old.inventory[0];
	this->inventory[1] = old.inventory[1];
	this->inventory[2] = old.inventory[2];
	this->inventory[3] = old.inventory[3];
}
MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
	}
}

void MateriaSource::learnMateria(AMateria * materia) {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] == NULL) {
			this->inventory[i] = materia;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] &&
			this->inventory[i]->getType() == type) {
				return ((AMateria *) this->inventory[i]->clone());
		}
	}
	return (NULL);
}