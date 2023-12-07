#include "Form.hpp"
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
		bur.reallocate(120);
	} catch (Bureaucrat::GradeTooLowException & e) {
		std::cout << e.what();
	}
	std::cout << bur << std::endl;

	std::cout << "FORM TESTS" << std::endl;

	try {
		Form form("Form", 160, 160);
	} catch (Form::GradeTooLowException & e) {
		std::cerr << e.what();
	}
	try {
		Form form3("Form", 0, 0);
	} catch (Form::GradeTooHighException & e) {
		std::cerr << e.what();
	}
	Form form2("Form", 110, 110);
	bur.signForm(form2);
	form2.beSigned(bur);
	bur.promote(10);
	form2.beSigned(bur);
	std::cout << form2 << std::endl;
	std::cout << bur << std::endl;
}