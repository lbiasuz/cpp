#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "AForm.hpp"
# include <string>
# include <ostream>

class AForm;

class Bureaucrat {
	private:
		const std::string	name;
		int					grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat(void);
		Bureaucrat(const Bureaucrat & ref);
		Bureaucrat& operator=(const Bureaucrat & ref);

		const std::string	getName(void) const;
		int					getGrade(void) const;
		void				promote(int grade);
		void				reallocate(int grade);
		void				signForm(AForm & form);
		void				executeForm(AForm const & form);

		class GradeTooHighException : public std::exception {
			public:
				const char * what () const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char * what () const throw();
		};

};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat &bureaucrat);

#endif