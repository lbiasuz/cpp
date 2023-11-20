#include "Zombie.hpp"

int	main( void )
{
	Zombie *heap;

	heap = newZombie("Sam");
	randomChump("Roger");
	heap->announce();
	delete heap;
}