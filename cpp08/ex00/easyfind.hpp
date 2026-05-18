#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &v, int i)
{
	typename T::iterator it = std::find(v.begin(), v.end(), i);
	if (it == v.end())
		throw std::runtime_error("Value not found");
	return(it);
}

#endif