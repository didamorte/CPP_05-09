#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(std::string s)
{
	if (isLiteral(s)) {
		printLiteral(s);
		return;
	}

	double value;
	if (isChar(s)) {
		value = static_cast<double>(s[0]);
	} else if (isInt(s)) {
		value = static_cast<double>(std::strtol(s.c_str(), NULL, 10));
	} else if (isFloat(s)) {
		value = std::strtod(s.c_str(), NULL);
	} else if (isDouble(s)) {
		value = std::strtod(s.c_str(), NULL);
	} else {
		std::cout << "Invalid input" << std::endl;
		return;
	}

	printChar(value);
	printInt(value, s);
	printFloat(value);
	printDouble(value);
}