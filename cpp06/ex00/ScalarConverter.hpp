#ifndef SCALARCONVERTER_HPP

# define SCALARCONVERTER_HPP
# include <string>
# include <iostream>

class ScalarConverter {

	private:
		std::string	_input;
		char		_char;
		int			_int;
		float		_float;
		double		_double;
		bool		_converted;

	public:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &old);
		ScalarConverter &operator=(ScalarConverter const &old);
		~ScalarConverter(void);

		void	convert(std::string str);
		void	print(void) const;
};

#endif