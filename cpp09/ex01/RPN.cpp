#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stack>
#include <cstdlib>

RPN::RPN()
{
}

RPN::RPN(const RPN& other)
{
	(void)other;
}

RPN& RPN::operator=(const RPN& other)
{
	(void)other;
	return (*this);
}

RPN::~RPN()
{
}

bool RPN::isOperator(const std::string& token)
{
	return (token.length() == 1 &&
			(token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'));
}

double RPN::applyOperator(double a, double b, char op)
{
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (a - b);
	if (op == '*')
		return (a * b);
	if (op == '/')
	{
		if (b == 0)
			throw std::runtime_error("Error");
		return (a / b);
	}
	return (0);
}

void RPN::evaluate(const std::string& expression)
{
	std::istringstream stream(expression);
	std::string token;
	std::stack<double> stack;

	while (stream >> token)
	{
		if (token.length() == 1 && token[0] >= '0' && token[0] <= '9')
		{
			stack.push(token[0] - '0');
		}
		else if (isOperator(token))
		{
			if (stack.size() < 2)
				throw std::runtime_error("Error");
			double b = stack.top();
			stack.pop();
			double a = stack.top();
			stack.pop();
			stack.push(applyOperator(a, b, token[0]));
		}
		else
		{
			throw std::runtime_error("Error");
		}
	}

	if (stack.size() != 1)
		throw std::runtime_error("Error");

	double result = stack.top();
	if (result == static_cast<long>(result))
		std::cout << static_cast<long>(result) << std::endl;
	else
		std::cout << result << std::endl;
}
