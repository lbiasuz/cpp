#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>

class Fixed {
	private:
		static const int	fBits;
		int					value;

	public:
		Fixed(void);
		Fixed(const Fixed &old);
		~Fixed(void);
		Fixed&	operator=(const Fixed &old);

		Fixed(const int value);
		Fixed(const float value);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

		bool	operator>(const Fixed &old) const;
		bool	operator<(const Fixed &old) const;
		bool	operator>=(const Fixed &old) const;
		bool	operator<=(const Fixed &old) const;
		bool	operator==(const Fixed &old) const;
		bool	operator!=(const Fixed &old) const;

		Fixed	operator+(const Fixed &old) const;
		Fixed	operator-(const Fixed &old) const;
		Fixed	operator*(const Fixed &old) const;
		Fixed	operator/(const Fixed &old) const;

		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);

		static Fixed&	min(Fixed &a, Fixed &b);
		const static Fixed&	min(const Fixed &a, const Fixed &b);
		static Fixed&	max(Fixed &a, Fixed &b);
		const static Fixed&	max(const Fixed &a, const Fixed &b);
};

std::ostream&	operator<<(std::ostream& out, const Fixed &fixed);



#endif