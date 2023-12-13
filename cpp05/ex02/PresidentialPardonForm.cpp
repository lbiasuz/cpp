#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void) : AForm ("Trash", 25, 5) {}
PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm (target, 145, 137), target(target) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & ref)
    : AForm(ref.getName(), ref.getSignGrade(), ref.getExecGrade()), target(ref.target) {}
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & ref)
    : AForm(ref.getName(), ref.getSignGrade(), ref.getExecGrade()), target(ref.target) { return (*this);}
PresidentialPardonForm::~PresidentialPardonForm(void) {}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > AForm::getExecGrade() || !AForm::getSign())
		throw AForm::GradeTooLowException();
	std::cout << this->target << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}
