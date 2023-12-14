#include "Bureaucrat.hpp"
#include "iostream"

Bureaucrat::Bureaucrat(void) : name("John Doe") {
	this->grade = 0;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < 0)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat & ref) : name(ref.getName())
{
	this->grade = ref.getGrade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref) {
	this->grade = ref.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {}

const std::string Bureaucrat::getName(void) const {
	return (this->name);
}

int Bureaucrat::getGrade(void) const {
	return (this->grade);
}

void Bureaucrat::reallocate(int grade)
{
	if (grade < 0)
		return ;
	if (this->getGrade() + grade > 150)
		throw GradeTooLowException();
	this->grade += grade;
}

void Bureaucrat::promote(int grade)
{
	if (grade < 0)
		return ;
	if (this->getGrade() - grade < 0)
		throw GradeTooHighException();
	this->grade -= grade;
}

void Bureaucrat::signForm(AForm & form) {
	if (this->getGrade() >= form.getSignGrade())
	{
		std::cout	<< this->getName() << " did not sign " << form.getName() \
					<< ", he is not competent enough." << std::endl;
		return ;
	}
	form.setSign(true);
	std::cout << this->getName() << " signed " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
		std::cout << "executed" << std::endl;
	} catch (GradeTooLowException & e){
		std::cout << e.what() << std::endl;
	}
}

std::ostream& operator << (std::ostream& out, const Bureaucrat& bur) {
	out << bur.getName() << " , bureaucrat grade " << bur.getGrade() << ".";
	return (out);
}

const char * Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Grade too high, it can't go under 0.\n");
}

const char * Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Grade too low, it can't go over 150.\n");
}