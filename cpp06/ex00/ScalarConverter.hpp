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

public:
	static void convert(std::string s);
};

void printChar(double value);
void printInt(double value, const std::string& s);
void printFloat(double value);
void printDouble(double value);
void printLiteral(const std::string& s);

bool isLiteral(const std::string& s);
bool isChar(const std::string& s);
bool isInt(const std::string& s);
bool isFloat(const std::string& s);
bool isDouble(const std::string& s);

#endif