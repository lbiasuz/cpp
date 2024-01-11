#include "Data.hpp"
#include <iostream>


int	main(void)
{
	Data* teste = new Data();
	Data* teste2;

	teste2 = deserialize(serialize(teste));

	std::cout << teste << std::endl;
	std::cout << teste2 << std::endl;

	std::cout << teste2->getTeste() << std::endl;

	teste->setTeste("banana");

	std::cout << teste2->getTeste() << std::endl;

	delete teste;
}