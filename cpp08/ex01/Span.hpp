#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>

class Span {
	private:
		unsigned int n;
		std::vector<int> vtr;

	public:
		Span(void);
		Span(unsigned int n);
		Span(const Span & old);
		~Span(void);
		Span & operator=(Span const &old);

		void	addNumber(int n);
		void	addNumberArr(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan(void);
		int		longestSpan(void);
};

#endif
