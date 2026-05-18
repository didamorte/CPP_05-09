#ifndef RPN_HPP
# define RPN_HPP

#include <string>

class RPN
{
private:
	bool isOperator(const std::string& token);
	double applyOperator(double a, double b, char op);

public:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	void evaluate(const std::string& expression);
};

#endif
