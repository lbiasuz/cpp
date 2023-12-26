#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure(void);
		Cure(const Cure & old);
		~Cure(void);
		Cure& operator= (const Cure & old);

		AMateria* clone( void ) const;
		void use( ICharacter& target );
};

#endif