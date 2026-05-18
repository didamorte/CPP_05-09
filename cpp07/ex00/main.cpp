#include "whatever.hpp"

int main()
{
	int a = 2;
	int b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	int e = 5;
	int f = 5;
	std::cout << "min(5, 5) = " << ::min(e, f) << std::endl;
	std::cout << "max(5, 5) = " << ::max(e, f) << std::endl;

	double g = 3.14;
	double h = 2.71;

	std::cout << "min(3.14, 2.71) = " << ::min(g, h) << std::endl;
	std::cout << "max(3.14, 2.71) = " << ::max(g, h) << std::endl;

	return 0;
}