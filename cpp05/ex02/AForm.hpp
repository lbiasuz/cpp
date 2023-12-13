#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <ostream>

class Bureaucrat;

class AForm {
	private:
		const std::string	name;
		bool				sign;
		const int			signGrade;
		const int			execGrade;

	protected:
		AForm(void);
		AForm(std::string name, int signGrade, int execGrade);
		AForm(const AForm & ref);
		virtual ~AForm(void);
		AForm& operator=(const AForm& ref);

	public:
		std::string	getName(void) const;
		bool		getSign(void) const;
		int			getSignGrade(void) const;
		int			getExecGrade(void) const;

		void		setSign(bool sign);
		void		beSigned(Bureaucrat & bur);
		virtual void	execute(Bureaucrat & bur) const;

		class GradeTooHighException : public std::exception {
			public:
				const char * what () const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char * what () const throw();
		};

};

std::ostream& operator<<(std::ostream& out, const AForm& ref);

#endif