#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <sys/time.h>
#include <algorithm>
#include <iterator>

static std::vector<int> generateJacobsthal(int max)
{
	std::vector<int> J;
	J.push_back(0);
	J.push_back(1);
	while (true)
	{
		int next = J[J.size() - 1] + 2 * J[J.size() - 2];
		if (next > max)
			break;
		J.push_back(next);
	}
	return (J);
}

static void vectorInsertSorted(std::vector<int>& chain, int value)
{
	std::vector<int>::iterator pos = std::lower_bound(chain.begin(), chain.end(), value);
	chain.insert(pos, value);
}

static void vectorMergeInsertRec(std::vector<int>& arr)
{
	size_t n = arr.size();
	if (n <= 1)
		return;
	if (n == 2)
	{
		if (arr[0] > arr[1])
		{
			int tmp = arr[0];
			arr[0] = arr[1];
			arr[1] = tmp;
		}
		return;
	}

	std::vector<std::pair<int, int> > pairs;
	size_t numPairs = n / 2;
	for (size_t i = 0; i < numPairs; i++)
	{
		int a = arr[2 * i];
		int b = arr[2 * i + 1];
		if (a > b)
		{
			int tmp = a;
			a = b;
			b = tmp;
		}
		pairs.push_back(std::make_pair(a, b));
	}
	int pending = -1;
	bool hasPending = false;
	if (n % 2 == 1)
	{
		pending = arr[n - 1];
		hasPending = true;
	}

	std::vector<int> largers;
	for (size_t i = 0; i < pairs.size(); i++)
		largers.push_back(pairs[i].second);
	vectorMergeInsertRec(largers);

	std::vector<std::pair<int, int> > sorted_pairs;
	std::vector<bool> used(pairs.size(), false);
	for (size_t i = 0; i < largers.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (!used[j] && pairs[j].second == largers[i])
			{
				sorted_pairs.push_back(pairs[j]);
				used[j] = true;
				break;
			}
		}
	}
	pairs = sorted_pairs;

	std::vector<int> main_chain;
	main_chain.push_back(pairs[0].first);
	for (size_t i = 0; i < largers.size(); i++)
		main_chain.push_back(largers[i]);

	std::vector<int> J = generateJacobsthal(static_cast<int>(pairs.size()) - 1);

	std::vector<int> insert_order;
	for (int k = 1; k < static_cast<int>(J.size()); k++)
	{
		int upper = J[k];
		if (upper >= static_cast<int>(pairs.size()))
			upper = static_cast<int>(pairs.size()) - 1;
		int lower = J[k - 1] + 1;
		for (int j = upper; j >= lower; j--)
		{
			if (j > 0)
				insert_order.push_back(j);
		}
	}

	for (size_t j = 1; j < pairs.size(); j++)
	{
		bool found = false;
		for (size_t i = 0; i < insert_order.size(); i++)
		{
			if (insert_order[i] == static_cast<int>(j))
			{
				found = true;
				break;
			}
		}
		if (!found)
			insert_order.push_back(static_cast<int>(j));
	}

	for (size_t i = 0; i < insert_order.size(); i++)
		vectorInsertSorted(main_chain, pairs[static_cast<size_t>(insert_order[i])].first);

	if (hasPending)
		vectorInsertSorted(main_chain, pending);

	arr = main_chain;
}

std::vector<int> PmergeMe::sortWithVector(const std::vector<int>& input)
{
	std::vector<int> result(input);
	vectorMergeInsertRec(result);
	return (result);
}

/* ========================================================================== */
/*                            Deque: Binary Insert                            */
/* ========================================================================== */

static void dequeInsertSorted(std::deque<int>& chain, int value)
{
	std::deque<int>::iterator pos = std::lower_bound(chain.begin(), chain.end(), value);
	chain.insert(pos, value);
}

/* ========================================================================== */
/*                          Deque: Ford-Johnson Sort                          */
/* ========================================================================== */

static void dequeMergeInsertRec(std::deque<int>& arr)
{
	size_t n = arr.size();
	if (n <= 1)
		return;
	if (n == 2)
	{
		if (arr[0] > arr[1])
		{
			int tmp = arr[0];
			arr[0] = arr[1];
			arr[1] = tmp;
		}
		return;
	}

	// --- Phase 1 & 2: Create pairs, compare within each pair ---
	std::vector<std::pair<int, int> > pairs;
	size_t numPairs = n / 2;
	for (size_t i = 0; i < numPairs; i++)
	{
		int a = arr[2 * i];
		int b = arr[2 * i + 1];
		if (a > b)
		{
			int tmp = a;
			a = b;
			b = tmp;
		}
		pairs.push_back(std::make_pair(a, b));
	}
	int pending = -1;
	bool hasPending = false;
	if (n % 2 == 1)
	{
		pending = arr[n - 1];
		hasPending = true;
	}

	// --- Phase 3: Recursively sort the larger elements ---
	std::deque<int> largers;
	for (size_t i = 0; i < pairs.size(); i++)
		largers.push_back(pairs[i].second);
	dequeMergeInsertRec(largers);

	// Reorder pairs to match sorted larger elements
	std::vector<std::pair<int, int> > sorted_pairs;
	std::vector<bool> used(pairs.size(), false);
	for (size_t i = 0; i < largers.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (!used[j] && pairs[j].second == largers[i])
			{
				sorted_pairs.push_back(pairs[j]);
				used[j] = true;
				break;
			}
		}
	}
	pairs = sorted_pairs;

	// --- Phase 4: Build main chain from sorted largers, insert smaller elements ---
	// Main chain: pair[0].first goes first
	std::deque<int> main_chain;
	main_chain.push_back(pairs[0].first);
	for (size_t i = 0; i < largers.size(); i++)
		main_chain.push_back(largers[i]);

	// Generate Jacobsthal: 0, 1, 3, 5, 11, ...
	std::vector<int> J = generateJacobsthal(static_cast<int>(pairs.size()) - 1);

	// Build insertion order for indices 1..pairs.size()-1
	std::vector<int> insert_order;
	for (int k = 1; k < static_cast<int>(J.size()); k++)
	{
		int upper = J[k];
		if (upper >= static_cast<int>(pairs.size()))
			upper = static_cast<int>(pairs.size()) - 1;
		int lower = J[k - 1] + 1;
		for (int j = upper; j >= lower; j--)
		{
			if (j > 0)
				insert_order.push_back(j);
		}
	}

	for (size_t j = 1; j < pairs.size(); j++)
	{
		bool found = false;
		for (size_t i = 0; i < insert_order.size(); i++)
		{
			if (insert_order[i] == static_cast<int>(j))
			{
				found = true;
				break;
			}
		}
		if (!found)
			insert_order.push_back(static_cast<int>(j));
	}

	// Binary insert smaller elements
	for (size_t i = 0; i < insert_order.size(); i++)
		dequeInsertSorted(main_chain, pairs[static_cast<size_t>(insert_order[i])].first);

	// Insert pending
	if (hasPending)
		dequeInsertSorted(main_chain, pending);

	// Copy back
	arr.clear();
	for (size_t i = 0; i < main_chain.size(); i++)
		arr.push_back(main_chain[i]);
}

std::deque<int> PmergeMe::sortWithDeque(const std::deque<int>& input)
{
	std::deque<int> result(input);
	dequeMergeInsertRec(result);
	return (result);
}

/* ========================================================================== */
/*                              Validation                                    */
/* ========================================================================== */

bool PmergeMe::isValidNumber(const std::string& str)
{
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return false;
	}
	long val = std::atol(str.c_str());
	if (val <= 0 || val > 2147483647L)
		return false;
	return true;
}

/* ========================================================================== */
/*                         Orthodox Canonical Form                             */
/* ========================================================================== */

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	(void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	(void)other;
	return (*this);
}

PmergeMe::~PmergeMe()
{
}
