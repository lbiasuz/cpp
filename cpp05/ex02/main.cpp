#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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

	ShrubberyCreationForm form("Form");
	form.beSigned(bur);
	bur.executeForm(form);
	PresidentialPardonForm form2("Bob");
	bur.signForm(form2);
	bur.executeForm(form2);
	RobotomyRequestForm form3("ClapTrap");
	bur.signForm(form3);
	bur.executeForm(form3);
}