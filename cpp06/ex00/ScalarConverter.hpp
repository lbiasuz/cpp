#ifndef SCALARCONVERTER_HPP

# define SCALARCONVERTER_HPP
# include <string>
# include <iostream>

class ScalarConverter {

	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &old);
		ScalarConverter &operator=(ScalarConverter const &old);
		~ScalarConverter(void);

	public:
		static	void	convert(std::string str);
		static	void	print(double _double, float _float, int _int, char _char);
};

#endif