#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character: public ICharacter {
	private:
		std::string name;
		AMateria* inventory[4];

	public:
		Character(void);
		Character( const std::string & name );
		Character( const Character & old );
		~Character(void);
		Character& operator= ( const Character & old );

		const std::string & getName( void ) const;
		void equip( AMateria* materia );
		void unequip( int i );
		void use( int i, ICharacter& target );
};

#endif