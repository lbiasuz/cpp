#include "Form.hpp"
#include <iostream>

Form::Form(void) : name("Form"),signGrade(150), execGrade(150){
	this->sign = false;
}

Form::Form(std::string name, int signGrade, int execGrade)
	: name(name), signGrade(signGrade), execGrade(execGrade){
	this->sign = false;
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form & ref)
	: name(ref.getName()), signGrade(ref.getSignGrade()), execGrade(ref.getExecGrade()) {
	this->sign = ref.getSign();
}

Form::~Form(void) { }

Form& Form::operator=(const Form& ref){
	this->sign = ref.getSign();
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const Form& ref) {
	if (ref.getSign())
		std::cout << ref.getName() << ": signed, ";
	else
		std::cout << ref.getName() << ": not signed, ";
	std::cout << "sign grade: " << ref.getSignGrade() \
			 << ", exec grade: " << ref.getExecGrade() << ".";
	return (out);
}

std::string	Form::getName(void) const {
	return (this->name);
}

bool	Form::getSign(void) const {
	return (this->sign);
}

 int	Form::getSignGrade(void) const {
	return (this->signGrade);
}

 int	Form::getExecGrade(void) const {
	return (this->execGrade);
}

void	Form::setSign(bool sign) {
	this->sign = sign;
}

void		Form::beSigned(Bureaucrat &bur) {
	if (bur.getGrade() >= this->signGrade)
	{
		std::cout 	<< this->getName() << " was not signed by " << bur.getName() \
					<< ", he is not competent enough." << std::endl;
		return ;
	}
	this->sign = true;
	std::cout << this->getName() << " signed by " << bur.getName() << std::endl;
}

void	Form::beExecuted(Bureaucrat &bur) {
	if (bur.getGrade() > this->execGrade)
		throw Form::GradeTooLowException();
}

const char * Form::GradeTooHighException::what(void) const throw() {
	return ("Grade too high, it can't go under 0.\n");
}

const char * Form::GradeTooLowException::what(void) const throw() {
	return ("Grade too low, it can't go over 150.\n");
}