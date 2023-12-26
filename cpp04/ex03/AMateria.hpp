#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria {
	protected:
		std::string type;

	public:
		AMateria(std::string const & type);
		AMateria(void);
		AMateria(const AMateria & old);
		virtual ~AMateria(void);
		AMateria& operator= (const AMateria & old);

		std::string const & getType( void ) const;

		virtual AMateria* clone( void ) const = 0;
		virtual void use( ICharacter& target );
};

#endif