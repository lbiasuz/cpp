#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm ("Trash", 145, 137), target("") {}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm (target, 145, 137), target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & ref)
    : AForm(ref.getName(), ref.getSignGrade(), ref.getExecGrade()), target(ref.target) {}
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & ref)
{
	this->setSign(ref.getSign());
	this->target = target;
	return (*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	std::ofstream	of;
	std::string		suffix = "_shrubbery";

	if (executor.getGrade() > AForm::getExecGrade() || !AForm::getSign())
		throw AForm::GradeTooLowException();
	of.open((this->target + suffix).c_str());
	if (of.good())
		of << "             /\\ \n            <  > \n             \\/ \n             /\\ \n            /  \\ \n           /++++\\ \n          /  ()  \\ \n          /      \\ \n         /~`~`~`~`\\ \n        /  ()  ()  \\ \n        /          \\ \n       /*&*&*&*&*&*&\\ \n      /  ()  ()  ()  \\ \n      /              \\ \n     /++++++++++++++++\\ \n    /  ()  ()  ()  ()  \\ \n    /                  \\ \n   /~`~`~`~`~`~`~`~`~`~`\\ \n  /  ()  ()  ()  ()  ()  \\ \n  /*&*&*&*&*&*&*&*&*&*&*&\\ \n /                        \\ \n/,.,.,.,.,.,.,.,.,.,.,.,.,.\\ \n            |   | \n            |`````| \n            \\_____/ \n";
	of.close();
}