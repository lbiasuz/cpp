#ifndef RPN_HPP
# define RPN_HPP
# include <stack>
# include <string>

class RPN {
	private:
		std::stack<int> stk;

	public:
		RPN(void);
		RPN(const RPN & rpn);
		~RPN(void);
		RPN &	operator=(const RPN & rpn);
		bool	is_valid_input(char *argv);
		int		calculate(char **argv);
};

#endif