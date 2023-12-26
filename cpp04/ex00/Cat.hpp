#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat(void);
		Cat( const Cat & old);
		~Cat(void);
		Cat& operator= ( const Cat & old);

		void makeSound( void ) const;
};

#endif