#include "Bureaucrat.hpp"

// ORTODOX CANONICA FORM

Bureaucrat::Bureaucrat(void) : name("John Doe") {
	this->grade = 0;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < 0)
		throw GradeTooLowException();
	if (grade > 150)
		throw GradeTooHighException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat & ref)
{
	this->grade = ref.getGrade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref) {
	this->grade = ref.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {}

// ORTODOX CANONICA FORM -- END

const std::string Bureaucrat::getName(void) const {
	return (this->name);
}

int Bureaucrat::getGrade(void) const {
	return (this->grade);
}

void Bureaucrat::promote(int grade)
{
	if (grade < 0)
		return ;
	if (this->getGrade() + grade > 150)
		throw GradeTooHighException();
	this->grade += grade;
}

void Bureaucrat::realocate(int grade)
{
	if (grade < 0)
		return ;
	if (this->getGrade() - grade < 0)
		throw GradeTooLowException();
	this->grade -= grade;
}

std::ostream& operator << (std::ostream& out, const Bureaucrat& bur) {
	out << bur.getName() << " , bureaucrat grade " << bur.getGrade() << ".";
	return (out);
}

const char * Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Grade too high, it can't go over 150.\n");
}

const char * Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Grade too low, it can't go under 0.\n");
}