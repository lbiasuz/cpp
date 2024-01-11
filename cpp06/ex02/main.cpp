#include "Classes.hpp"
#include <iostream>
#include <cstdlib>

int	main(void)
{
	std::srand(time(0));

	Base *x = generate();
	Base *y = generate();
	Base *z = generate();

	identify(x);
	identify(y);
	identify(*z);

	delete x;
	delete y;
	delete z;
}