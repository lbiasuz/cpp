#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main( void )
{
	Animal* meta = new Animal();
	Animal* j = new Dog();
	Animal* i = new Cat();
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;
	std::cout << "WRONG ANIMAL" << std::endl;
	std::cout << std::endl;
	WrongAnimal* wrong = new WrongAnimal();
	WrongAnimal* l = new WrongCat();
	l->makeSound();
	wrong->makeSound();

	delete meta;
	delete j;
	delete i;
	delete wrong;
	delete l;
	return 0;
}