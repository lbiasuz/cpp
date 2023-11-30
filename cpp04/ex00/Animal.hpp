#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {
	protected:
		std::string type;

	public:
		Animal( void );
		Animal( const Animal & old);
		virtual	~Animal( void );
		Animal& operator=(const Animal & old);

		std::string getType( void );
		virtual void makeSound( void );
};

#endif