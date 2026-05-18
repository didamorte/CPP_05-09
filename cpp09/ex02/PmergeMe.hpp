#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>

class PmergeMe
{
private:

public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	static std::vector<int>	sortWithVector(const std::vector<int>& input);
	static std::deque<int>	sortWithDeque(const std::deque<int>& input);
	static bool		isValidNumber(const std::string& str);
};

#endif
