#include "ScalarConverter.hpp"

void ScalarConverter::printLiteral(const std::string& s)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (s == "nan" || s == "nanf") {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	} else if (s == "+inf" || s == "+inff" || s == "inf" || s == "inff") {
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	} else if (s == "-inf" || s == "-inff") {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::printChar(double value)
{
	std::cout << "char: ";
	if (value < 0 || value > 127 || std::isnan(value) || std::isinf(value))
		std::cout << "impossible" << std::endl;
	else if (!isprint(static_cast<int>(value)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::printInt(double value, const std::string& s)
{
	(void)s;
	std::cout << "int: ";
	if (std::isnan(value) || std::isinf(value) ||
		value > std::numeric_limits<int>::max() ||
		value < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value)
{
	std::cout << "float: ";
	float f = static_cast<float>(value);
	if (f == static_cast<int>(f))
		std::cout << f << ".0f" << std::endl;
	else
		std::cout << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double value)
{
	std::cout << "double: ";
	if (value == static_cast<int>(value))
		std::cout << value << ".0" << std::endl;
	else
		std::cout << value << std::endl;
}

