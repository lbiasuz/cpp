#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <exception>
# include <string>
# include <algorithm>

template<class T>
typename T::iterator	easyfind(T arr, int n) {
	typename	T::iterator it;

	it = std::find(arr.begin(), arr.end(), n);
	if (it == arr.end())
		throw std::exception();
	return (it);
};

#endif