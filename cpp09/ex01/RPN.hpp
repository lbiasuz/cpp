#ifndef RPN_HPP
# define RPN_HPP
# include <list>
# include <string>

class RPN {
	private:
		std::list<std::string> lst;

	public:
		RPN(void);
		RPN(const RPN & rpn);
		~RPN(void);
		RPN &	operator=(const RPN & rpn);
		bool	is_valid_input();
		void	initialize_data(char *argv);
		int		calculate(void);

};

#endif