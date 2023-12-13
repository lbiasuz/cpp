#include "RobotomyRequestForm.hpp"
#include <cstdlib> 
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm ("Trash", 72, 45) {}
RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm(target, 145, 137), target(target) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & ref)
    : AForm(ref.getName(), ref.getSignGrade(), ref.getExecGrade()), target(ref.target) {}
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & ref)
    : AForm(ref.getName(), ref.getSignGrade(), ref.getExecGrade()), target(ref.target) { return (*this);}
RobotomyRequestForm::~RobotomyRequestForm(void) {}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > AForm::getExecGrade() || !AForm::getSign())
		throw AForm::GradeTooLowException();
	std::cout << "Brrrrrrrrrrr..." << std::endl;
	std::cout << "ZzZZZzzzZzzZzzZZz..." << std::endl;
	std::cout << "Clack Pow Piiiiiiii..." << std::endl;
	std::cout << "Shhh..." << std::endl;
	std::cout << "Bip..." << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->target << "successfully robotomized" << std::endl;
	else
		std::cout << "Error Error Err..." << std::endl;
}
