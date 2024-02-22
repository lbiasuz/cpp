#ifndef ITER_HPP
# define ITER_HPP
#include <iostream>

template<class T>
void iter(T* array, int lenght, void (*f)(T&)) {
	if (lenght <= 0)
		return ;
	for (int i = 0; i < lenght; i++) {
		f(array[i]);
	};
	return ;
}

template<class T>
void iter(T* array, int lenght, void (*f)(const T&)) {
	if (lenght <= 0)
		return ;
	for (int i = 0; i < lenght; i++) {
		f(array[i]);
	};
	return ;
}

template<class T>
void	prnt(const T& arg) {
	std::cout << arg << std::endl;
};


#endif