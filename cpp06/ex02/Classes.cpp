#include "Classes.hpp"
#include <cstdlib>
#include <iostream>

Base::~Base(void) {}

A::A(void) {
	std::cout << "A created" << std::endl;
}
B::B(void) {
	std::cout << "B created" << std::endl;
}
C::C(void) {
	std::cout << "C created" << std::endl;
}

A::~A(void) {}
B::~B(void) {}
C::~C(void) {}

Base *generate(void) {
	int i = (std::rand() % 3) + 1;
	switch (i)
	{
	case 1:
		return new A();
	case 2:
		return new B();
	case 3:
		return new C();
	}
	return (NULL);
}

void identify(Base *p)
{
	if(dynamic_cast<A*>(p)) {
		std::cout << "It's A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "It's B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "It's C" << std::endl;
	} else {
		std::cout << "Error" << std::endl;
	}
}

void	identify(Base &p) {
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "It's A" << std::endl;
		return ;
	} catch (std::exception &e) {}
	try {
		B b = dynamic_cast<B&>(p);
		std::cout << "It's B" << std::endl;
		return ;
	} catch (std::exception &e) {}
	try {
		C c = dynamic_cast<C&>(p);
		std::cout << "It's C" << std::endl;
		return ;
	} catch (std::exception &e) {}
	std::cout << "Error" << std::endl;
}