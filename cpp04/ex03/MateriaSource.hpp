#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria * inventory[4];

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource & old);
		~MateriaSource(void);
		MateriaSource& operator=(const MateriaSource & old);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif