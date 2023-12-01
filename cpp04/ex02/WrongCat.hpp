#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat(void);
		WrongCat(const WrongCat & old);
		~WrongCat(void);
		WrongCat& operator= (const WrongCat & old);

		void makeSound( void );
};

#endif