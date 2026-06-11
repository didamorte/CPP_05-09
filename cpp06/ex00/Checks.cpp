#include "ScalarConverter.hpp"

bool ScalarConverter::isLiteral(const std::string& s)
{
	return (s == "nan" || s == "nanf" ||
			s == "+inf" || s == "-inf" ||
			s == "+inff" || s == "-inff" ||
			s == "inf" || s == "inff");
}

bool ScalarConverter::isChar(const std::string& s)
{
	return (s.length() == 1 && !isdigit(s[0]));
}

bool ScalarConverter::isInt(const std::string& s)
{
	size_t i = 0;
	if (s[0] == '-' || s[0] == '+')
		i = 1;
	if (i == s.length())
		return false;
	for (; i < s.length(); i++) {
		if (!isdigit(s[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string& s)
{
	if (s.empty() || s[s.length() - 1] != 'f')
		return false;
	std::string tmp = s.substr(0, s.length() - 1);
	bool hasDot = false;
	size_t i = 0;
	if (tmp[0] == '-' || tmp[0] == '+')
		i = 1;
	for (; i < tmp.length(); i++) {
		if (tmp[i] == '.') {
			if (hasDot) return false;
			hasDot = true;
		} else if (!isdigit(tmp[i])) {
			return false;
		}
	}
	return hasDot;
}

bool ScalarConverter::isDouble(const std::string& s)
{
	bool hasDot = false;
	size_t i = 0;
	if (s[0] == '-' || s[0] == '+')
		i = 1;
	for (; i < s.length(); i++) {
		if (s[i] == '.') {
			if (hasDot) return false;
			hasDot = true;
		} else if (!isdigit(s[i])) {
			return false;
		}
	}
	return hasDot;
}
