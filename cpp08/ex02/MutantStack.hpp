#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T> {

	public:
		typedef typename std::stack<T>::container_type::iterator	iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator	reverse_iterator;

		MutantStack(void) {};
		~MutantStack(void) {};
		MutantStack(const MutantStack<T> &old) : std::stack<T>(old){
			*this = old;
		};
		MutantStack<T> &operator=(const MutantStack<T> &old) {
			std::stack<T>::operator=(old);
			return (*this);
		};

		typename std::stack<T>::container_type::iterator			begin() {return (this->c.begin());};
		typename std::stack<T>::container_type::iterator			end() {return (this->c.end());};
		typename std::stack<T>::container_type::reverse_iterator	rbegin() {return (this->c.rbegin());};
		typename std::stack<T>::container_type::reverse_iterator	rend() {return (this->c.rend());};
};

#endif