#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main( void )
{
	Animal* animals[10];

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
		std::cout << std::endl;
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << std::endl;
		animals[i]->makeSound();
		delete animals[i];
	}

	std::cout << "Brain tests" << std::endl;

	Dog* dog = new Dog();

	dog->getBrain().newIdea("food");
	std::cout << dog->getBrain().getIdea(0) << std::endl;
	dog->getBrain().newIdea("walk");
	std::cout << dog->getBrain().getIdea(1) << std::endl;

	Dog* dog2 = new Dog(*dog);

	delete dog;

	std::cout << dog2->getBrain().getIdea(0) << std::endl;
	std::cout << dog2->getBrain().getIdea(1) << std::endl;

	delete dog2;

	Cat* cat = new Cat();

	cat->getBrain().newIdea("scratch");
	std::cout << cat->getBrain().getIdea(0) << std::endl;
	cat->getBrain().newIdea("sleep");
	std::cout << cat->getBrain().getIdea(1) << std::endl;

	Cat* cat2 = new Cat(*cat);

	delete cat;

	std::cout << cat2->getBrain().getIdea(0) << std::endl;
	std::cout << cat2->getBrain().getIdea(1) << std::endl;

	delete cat2;


	return 0;
}