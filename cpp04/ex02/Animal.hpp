#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {
	protected:
		std::string type;

		Animal( void );
		Animal( const Animal & old);
		virtual	~Animal( void );
		Animal& operator=(const Animal & old);

	public:
		std::string getType( void );
		virtual void makeSound( void );
};

#endif