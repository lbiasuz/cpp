#ifndef REPLACER_HPP
# define REPLACER_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>

class Replacer {
	private:
		std::ifstream _in;
		std::ofstream _out;

		std::string	_new;
		std::string	_old;
		std::string	_tmp;

	public:
		Replacer( void );
		Replacer( char** argv );
		~Replacer( void );

		int	open( const char*, int read);
		int replace_inline ( void );
		int replace ( std::string path );
};

#endif