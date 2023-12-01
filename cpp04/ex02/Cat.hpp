#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
#include  "Brain.hpp"

class Cat : public Animal {
	private:
		Brain* brain;

	public:
		Cat(void);
		Cat( const Cat & old);
		~Cat(void);
		Cat& operator= ( const Cat & old);

		Brain& getBrain( void );
		void makeSound( void );
};

#endif