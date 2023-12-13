#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm & ref);
		~RobotomyRequestForm(void);
		RobotomyRequestForm &operator=(const RobotomyRequestForm & ref);
		void	execute(Bureaucrat const & executor) const;

};

#endif