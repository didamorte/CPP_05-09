#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::cout << "=== Normal Test ===" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== Test with 10,000 numbers ===" << std::endl;
	{
		std::vector<int> vec;
		for (int i = 0; i < 10000; ++i)
			vec.push_back(std::rand());
		
		Span sp(10000);
		sp.addRange(vec.begin(), vec.end());
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== Test with 100,000 numbers ===" << std::endl;
	{
		std::vector<int> vec;
		for (int i = 0; i < 100000; ++i)
			vec.push_back(i);

		Span sp(100000);
		sp.addRange(vec.begin(), vec.end());
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== Test addRange ===" << std::endl;
	{
		Span sp(10);
		std::vector<int> vec;
		vec.push_back(5);
		vec.push_back(10);
		vec.push_back(15);
		vec.push_back(20);
		vec.push_back(25);
		sp.addRange(vec.begin(), vec.end());
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== Exception Tests ===" << std::endl;

	std::cout << "Test: Adding to full span" << std::endl;
	try
	{
		Span sp(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\nTest: shortestSpan with 0 elements" << std::endl;
	try
	{
		Span sp(5);
		sp.shortestSpan();
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\nTest: shortestSpan with 1 element" << std::endl;
	try
	{
		Span sp(5);
		sp.addNumber(42);
		sp.shortestSpan();
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\nTest: longestSpan with 0 elements" << std::endl;
	try
	{
		Span sp(5);
		sp.longestSpan();
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Edge Cases ===" << std::endl;

	std::cout << "Test: Duplicates" << std::endl;
	{
		Span sp(5);
		sp.addNumber(5);
		sp.addNumber(5);
		sp.addNumber(5);
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\nTest: Negative numbers" << std::endl;
	{
		Span sp(5);
		sp.addNumber(-100);
		sp.addNumber(-50);
		sp.addNumber(0);
		sp.addNumber(50);
		sp.addNumber(100);
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\nTest: Copy constructor" << std::endl;
	{
		Span sp1(5);
		sp1.addNumber(1);
		sp1.addNumber(2);
		sp1.addNumber(3);
		Span sp2(sp1);
		std::cout << "sp2 Shortest: " << sp2.shortestSpan() << std::endl;
		std::cout << "sp2 Longest: " << sp2.longestSpan() << std::endl;
	}

	std::cout << "\nTest: Assignment operator" << std::endl;
	{
		Span sp1(5);
		sp1.addNumber(10);
		sp1.addNumber(20);
		sp1.addNumber(30);
		Span sp2(10);
		sp2 = sp1;
		std::cout << "sp2 Shortest: " << sp2.shortestSpan() << std::endl;
		std::cout << "sp2 Longest: " << sp2.longestSpan() << std::endl;
	}

	return (0);
}
