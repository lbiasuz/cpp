#include "Data.hpp"

Data::Data(void) : teste("batata") {}
Data::Data(const Data & old) : teste(old.teste) {}
Data::~Data() {}
Data & Data::operator=(const Data & old)
{
	this->teste = old.teste;
	return (* this);
}

std::string Data::getTeste(void)
{
	return (this->teste);
}

void Data::setTeste(std::string str)
{
	this->teste = str;
}

uintptr_t serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data * deserialize(uintptr_t ptr)
{
	return (reinterpret_cast<Data *>(ptr));
}