#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <cstdlib>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	_database = other._database;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_database = other._database;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open database file");

	std::string line;
	// Skip header
	std::getline(file, line);

	while (std::getline(file, line))
	{
		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos || commaPos == 0)
			continue;

		std::string date = line.substr(0, commaPos);
		std::string valueStr = line.substr(commaPos + 1);

		double value = std::atof(valueStr.c_str());
		_database[date] = value;
	}
	file.close();
}

static bool isValidDate(const std::string& date)
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	for (size_t i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysInMonth[2] = 29;

	if (day > daysInMonth[month])
		return false;

	return true;
}

static int parseValue(const std::string& valueStr, double& outValue)
{
	if (valueStr.empty())
		return 0;

	bool hasDot = false;
	bool hasDigit = false;
	size_t start = 0;

	if (valueStr[0] == '+')
		start = 1;
	else if (valueStr[0] == '-')
		return 2;

	if (start >= valueStr.length())
		return 0;

	for (size_t i = start; i < valueStr.length(); i++)
	{
		if (valueStr[i] == '.')
		{
			if (hasDot)
				return 0;
			hasDot = true;
		}
		else if (std::isdigit(static_cast<unsigned char>(valueStr[i])))
			hasDigit = true;
		else
			return 0;
	}

	if (!hasDigit)
		return 0;

	outValue = std::atof(valueStr.c_str());
	if (outValue > 1000)
		return 3;

	return 1;
}

void BitcoinExchange::processInput(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open input file" << std::endl;
		return;
	}

	std::string line;
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		size_t sepPos = line.find(" | ");
		if (sepPos == std::string::npos || sepPos == 0)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, sepPos);
		std::string valueStr = line.substr(sepPos + 3);

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		double value = 0;
		int parseResult = parseValue(valueStr, value);
		if (parseResult == 0)
		{
			std::cerr << "Error: bad input => " << valueStr << std::endl;
			continue;
		}
		else if (parseResult == 2)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		else if (parseResult == 3)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		std::map<std::string, double>::iterator it = _database.lower_bound(date);
		if (it == _database.end() || it->first != date)
		{
			if (it == _database.begin())
			{
				std::cerr << "Error: date is before first database entry." << std::endl;
				continue;
			}
			--it;
		}

		double result = value * it->second;
		std::cout << date << " => " << valueStr << " = " << result << std::endl;
	}
	file.close();
}
