#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename s>
void swap(s &a, s &b)
{
	s temp;

	temp = a;
	a = b;
	b = temp;
	
}

template <typename m>
m min(m a, m b)
{
	return ((a < b) ? a : b);
}

template <typename M>
M max(M a, M b)
{
	return ((a > b) ? a : b);
}

#endif