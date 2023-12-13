#include "AForm.hpp"
#include <iostream>

AForm::AForm(void) : name("Form"),signGrade(150), execGrade(150){
	this->sign = false;
}

AForm::AForm(std::string name, int signGrade, int execGrade)
	: name(name), signGrade(signGrade), execGrade(execGrade){
	this->sign = false;
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm & ref)
	: name(ref.getName()), signGrade(ref.getSignGrade()), execGrade(ref.getExecGrade()) {
	this->sign = ref.getSign();
}

AForm::~AForm(void) { }

AForm& AForm::operator=(const AForm& ref){
	this->sign = ref.getSign();
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const AForm& ref) {
	if (ref.getSign())
		std::cout << ref.getName() << ": signed, ";
	else
		std::cout << ref.getName() << ": not signed, ";
	std::cout << "sign grade: " << ref.getSignGrade() \
			 << ", exec grade: " << ref.getExecGrade() << ".";
	return (out);
}

std::string	AForm::getName(void) const {
	return (this->name);
}

bool	AForm::getSign(void) const {
	return (this->sign);
}

 int	AForm::getSignGrade(void) const {
	return (this->signGrade);
}

 int	AForm::getExecGrade(void) const {
	return (this->execGrade);
}

void	AForm::setSign(bool sign) {
	this->sign = sign;
}

void		AForm::beSigned(Bureaucrat &bur) {
	if (bur.getGrade() >= this->signGrade)
	{
		std::cout 	<< this->getName() << " was not signed by " << bur.getName() \
					<< ", he is not competent enough." << std::endl;
		return ;
	}
	this->sign = true;
	std::cout << this->getName() << " signed by " << bur.getName() << std::endl;
}

void	AForm::execute(Bureaucrat const & executor) const {
	if (bur.getGrade() > this->execGrade || !this->getSign())
		throw AForm::GradeTooLowException();
}

const char * AForm::GradeTooHighException::what(void) const throw() {
	return ("Grade too high, it can't go under 0.\n");
}

const char * AForm::GradeTooLowException::what(void) const throw() {
	return ("Grade too low, it can't go over 150.\n");
}