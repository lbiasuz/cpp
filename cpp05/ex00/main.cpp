#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

int	main(void) {
	Bureaucrat bur;

	try {
		bur = Bureaucrat("George", 160);
	} catch (Bureaucrat::GradeTooLowException & e) {
		std::cerr << e.what();
	}
	try {
		bur = Bureaucrat("Christopher", -160);
	} catch (Bureaucrat::GradeTooHighException & e) {
		std::cerr << e.what();
	}
	bur = Bureaucrat("Alan", 15);
	std::cout << bur << std::endl;
	bur.reallocate(100);
	std::cout << bur << std::endl;
	try {
		bur.promote(120);
	} catch (Bureaucrat::GradeTooHighException & e) {
		std::cout << e.what();
	}
	std::cout << bur << std::endl;
}