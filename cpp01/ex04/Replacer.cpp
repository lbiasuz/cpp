#include "Replacer.hpp"

Replacer::Replacer( void )
{
	this->_old = "";
	this->_new = "";
}

Replacer::Replacer(char** argv)
{
	this->_old = argv[2];
	this->_new = argv[3];
}

Replacer::~Replacer( void )
{
	this->_in.close();
	this->_out.close();
}

int Replacer::open( const char* str, int read ) {
	if (read != 0)
	{
		this->_in.open(str);
		return (this->_in.good());
	}
	else
	{
		this->_out.open(str);
		return (this->_out.good());
	}
};

int Replacer::replace_inline( void )
{
	size_t	index = 0;

	index = this->_tmp.find(this->_old);
	while (index != std::string::npos)
	{
		this->_tmp.erase(index, this->_old.length());
		this->_tmp.insert(index, this->_new);
		index = this->_tmp.find(this->_old, index);
	}
	return (index != std::string::npos);
}

int Replacer::replace( std::string path ) {
	if (!this->open(path.c_str(), 1))
		return (0);
	if (!this->open((path + ".replace").c_str(), 0))
		return (0);
	while (std::getline(this->_in, this->_tmp))
	{
		this->replace_inline();
		this->_out << this->_tmp << std::endl;
	}
	return (1);
}