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
};

std::ostream&	operator<<(std::ostream& out, const Fixed &fixed);

#endif