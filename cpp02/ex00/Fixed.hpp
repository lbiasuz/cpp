#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	private:
		static const int	fBits;
		int					value;
	public:
		Fixed(void);
		Fixed(const Fixed &old);
		~Fixed(void);

		Fixed&	operator=(const Fixed &old);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif