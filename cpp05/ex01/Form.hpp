#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <ostream>

class Bureaucrat;

class Form {
	private:
		const std::string	name;
		bool				sign;
		const int			signGrade;
		const int			execGrade;

	public:
		Form(void);
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form & ref);
		~Form(void);
		Form& operator=(const Form& ref);

		std::string	getName(void) const;
		bool		getSign(void) const;
		int			getSignGrade(void) const;
		int			getExecGrade(void) const;

		void		setSign(bool sign);
		void		beSigned(Bureaucrat & bur);
		void		beExecuted(Bureaucrat & bur);

		class GradeTooHighException : public std::exception {
			public:
				const char * what () const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char * what () const throw();
		};

};

std::ostream& operator<<(std::ostream& out, const Form& ref);

#endif