#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"

# include <string>

class Intern {
	public:
		Intern(void);
		Intern(const Intern & ref);
		~Intern(void);
		Intern &operator=(const Intern & ref);
		AForm *makeForm(std::string formName, std::string target);

		class IncorrectFormName: public std::exception {
			public:
				virtual const char *what() const throw();
		};
};


#endif