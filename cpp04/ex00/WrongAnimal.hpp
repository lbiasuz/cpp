#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal {
	protected:
		std::string type;

	public:
		WrongAnimal( void );
		WrongAnimal( const WrongAnimal & old);
		~WrongAnimal( void );
		WrongAnimal& operator=(const WrongAnimal & old);

		std::string getType( void );
		void makeSound( void );
};

#endif