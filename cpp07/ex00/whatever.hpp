#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<class T>
void swap(T& a, T& b) {
	T c = a;

	a = b;
	b = c;
}

template<class T>
T&	min(T& a, T& b) {
	if (a < b)
		return (a);
	return (b);
}

template<class T>
T&	max(T& a, T& b) {
	if (a > b)
		return (a);
	return (b);
}

#endif