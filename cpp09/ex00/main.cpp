#include "BitcoinExchange.hpp"
#include <iostream>
#include <stdexcept>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open input file" << std::endl;
		return (1);
	}

	try
	{
		BitcoinExchange exchange;
		exchange.loadDatabase("data.csv");
		exchange.processInput(argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
