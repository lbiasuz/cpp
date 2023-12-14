#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#include <iostream>

Intern::Intern(void) {}

Intern::Intern(const Intern & ref) {
	*this = ref;
}

Intern::~Intern(void) {}

Intern &Intern::operator=(const Intern & ref) {
	(void)ref;
	return *this;
}

AForm *Intern::makeForm(std::string name, std::string target) {
	if (name == "shrubbery creation") {
		std::cout << name << " form created successfully" << std::endl;
		return new ShrubberyCreationForm(target);
	} else if (name == "robotomy request") {
		std::cout << name << " form created successfully" << std::endl;
		return new RobotomyRequestForm(target);
	} else if (name == "presidential pardon") {
		std::cout << name << " form created successfully" << std::endl;
		return new PresidentialPardonForm(target);
	} else {
		throw Intern::IncorrectFormName();
	}
}

const char *Intern::IncorrectFormName::what() const throw() {
	return "Incorrect form name";
}