#include "iter.hpp"

template <typename T>
void print(T &elem)
{
	std::cout << elem << " ";
}

void increment(int &n)
{
	n++;
}

void toUpper(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
}

int main()
{
	int intArr[] = {1, 2, 3, 4, 5};
	const size_t intSize = sizeof(intArr) / sizeof(intArr[0]);

	std::cout << "Int array: ";
	iter(intArr, intSize, print<int>);
	std::cout << std::endl;

	iter(intArr, intSize, increment);
	std::cout << "After increment: ";
	iter(intArr, intSize, print<int>);
	std::cout << std::endl;

	double doubleArr[] = {1.1, 2.2, 3.3, 4.4};
	size_t doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);

	std::cout << "Double array: ";
	iter(doubleArr, doubleSize, print<double>);
	std::cout << std::endl;

	std::string strArr[] = {"hello", "world", "test"};
	size_t strSize = sizeof(strArr) / sizeof(strArr[0]);

	std::cout << "String array: ";
	iter(strArr, strSize, print<std::string>);
	std::cout << std::endl;

	iter(strArr, strSize, toUpper);
	std::cout << "After toUpper: ";
	iter(strArr, strSize, print<std::string>);
	std::cout << std::endl;

	return 0;
}
