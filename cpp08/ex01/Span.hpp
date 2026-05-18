#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span
{
private:
	unsigned int _maxSize;
	std::vector<int> _numbers;
	Span();

public:
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int x);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	template <typename Iterator>
	void addRange(Iterator begin, Iterator end)
	{
		while (begin != end)
		{
			addNumber(*begin);
			++begin;
		}
	}

	class SpanFullException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class NoSpanException : public std::exception
	{
	public:
		const char* what() const throw();
	};

};

#endif

