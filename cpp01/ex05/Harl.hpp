#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl {
	private:
		std::string	keys[4];
		void (Harl::*values[4])();

		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

	public:
		Harl( void );
		~Harl( void );

		void complain( std::string str );
};

#endif