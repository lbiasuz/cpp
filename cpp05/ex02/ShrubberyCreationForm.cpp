#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm ("Trash", 145, 137) {}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm (target, 145, 137), target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & ref)
    : AForm(ref.getName(), ref.getSignGrade(), ref.getExecGrade()), target(ref.target) {}
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & ref)
    : AForm(ref.getName(), ref.getSignGrade(), ref.getExecGrade()), target(ref.target) { return (*this);}
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	std::ofstream	of;
	std::string		suffix("_shrubbery");

	if (executor.getGrade() > AForm::getExecGrade() || !AForm::getSign())
		throw AForm::GradeTooLowException();
	of.open(this->target + suffix);
	if (of.good())
		of << "
             /\ \n \
            <  > \n \
             \/ \n \
             /\ \n \
            /  \ \n \
           /++++\ \n \
          /  ()  \ \n \
          /      \ \n \
         /~`~`~`~`\ \n \
        /  ()  ()  \ \n \
        /          \ \n \
       /*&*&*&*&*&*&\ \n \
      /  ()  ()  ()  \ \n \
      /              \ \n \
     /++++++++++++++++\ \n \
    /  ()  ()  ()  ()  \ \n \
    /                  \ \n \
   /~`~`~`~`~`~`~`~`~`~`\ \n \
  /  ()  ()  ()  ()  ()  \ \n \
  /*&*&*&*&*&*&*&*&*&*&*&\ \n \
 /                        \ \n \
/,.,.,.,.,.,.,.,.,.,.,.,.,.\ \n \
            |   | \n \
            |`````| \n \
            \_____/ \n \
"
		of.close();
}