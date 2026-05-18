#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <sys/time.h>

static double getTimeMicroseconds()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000.0 + tv.tv_usec);
}

static void printContainer(const std::vector<int>& c, size_t maxPrint)
{
	size_t limit = (c.size() < maxPrint) ? c.size() : maxPrint;
	for (size_t i = 0; i < limit; i++)
	{
		if (i > 0)
			std::cout << " ";
		std::cout << c[i];
	}
	if (c.size() > maxPrint)
		std::cout << " [...]";
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	std::vector<int> vecInput;
	std::deque<int> deqInput;

	for (int i = 1; i < argc; i++)
	{
		if (!PmergeMe::isValidNumber(argv[i]))
		{
			std::cerr << "Error" << std::endl;
			return (1);
		}
		int val = std::atoi(argv[i]);
		vecInput.push_back(val);
		deqInput.push_back(val);
	}

	std::cout << "Before: ";
	printContainer(vecInput, 20);
	std::cout << std::endl;

	double vecStart = getTimeMicroseconds();
	std::vector<int> vecResult = PmergeMe::sortWithVector(vecInput);
	double vecEnd = getTimeMicroseconds();
	double vecTime = vecEnd - vecStart;

	double deqStart = getTimeMicroseconds();
	std::deque<int> deqResult = PmergeMe::sortWithDeque(deqInput);
	double deqEnd = getTimeMicroseconds();
	double deqTime = deqEnd - deqStart;

	std::cout << "After: ";
	printContainer(vecResult, 20);
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vecInput.size()
		<< " elements with std::vector<int> : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << deqInput.size()
		<< " elements with std::deque<int> : " << deqTime << " us" << std::endl;

	return (0);
}
