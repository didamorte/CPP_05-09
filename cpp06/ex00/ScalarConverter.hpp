#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>  // strtol, strtod
#include <limits>   // INT_MAX, INT_MIN
#include <cmath>    // isnan, isinf
#include <cctype>   // isprint, isdigit

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	static void printChar(double value);
	static void printInt(double value, const std::string& s);
	static void printFloat(double value);
	static void printDouble(double value);
	static void printLiteral(const std::string& s);

	static bool isLiteral(const std::string& s);
	static bool isChar(const std::string& s);
	static bool isInt(const std::string& s);
	static bool isFloat(const std::string& s);
	static bool isDouble(const std::string& s);

public:
	static void convert(std::string s);
};

#endif